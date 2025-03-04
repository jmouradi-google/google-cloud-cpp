// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/storage/internal/bucket_metadata_parser.h"
#include "google/cloud/storage/internal/bucket_access_control_parser.h"
#include "google/cloud/storage/internal/common_metadata_parser.h"
#include "google/cloud/storage/internal/lifecycle_rule_parser.h"
#include "google/cloud/storage/internal/object_access_control_parser.h"
#include "absl/strings/str_format.h"
#include <nlohmann/json.hpp>
#include <functional>

namespace google {
namespace cloud {
namespace storage {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {
namespace {
void SetIfNotEmpty(nlohmann::json& json, char const* key,
                   std::string const& value) {
  if (value.empty()) {
    return;
  }
  json[key] = value;
}

StatusOr<CorsEntry> ParseCors(nlohmann::json const& json) {
  auto parse_string_list = [](nlohmann::json const& json,
                              char const* field_name) {
    std::vector<std::string> list;
    if (json.count(field_name) != 0) {
      for (auto const& kv : json[field_name].items()) {
        list.emplace_back(kv.value().get<std::string>());
      }
    }
    return list;
  };
  CorsEntry result;
  if (json.count("maxAgeSeconds") != 0) {
    auto v = internal::ParseLongField(json, "maxAgeSeconds");
    if (!v) return std::move(v).status();
    result.max_age_seconds = *v;
  }
  result.method = parse_string_list(json, "method");
  result.origin = parse_string_list(json, "origin");
  result.response_header = parse_string_list(json, "responseHeader");
  return result;
}

StatusOr<UniformBucketLevelAccess> ParseUniformBucketLevelAccess(
    nlohmann::json const& json) {
  auto enabled = internal::ParseBoolField(json, "enabled");
  if (!enabled) return std::move(enabled).status();
  auto locked_time = internal::ParseTimestampField(json, "lockedTime");
  if (!locked_time) return std::move(locked_time).status();

  return UniformBucketLevelAccess{*enabled, *locked_time};
}

Status ParseAcl(std::vector<BucketAccessControl>& acl,
                nlohmann::json const& json) {
  if (!json.contains("acl")) return Status{};

  std::vector<BucketAccessControl> value;
  for (auto const& kv : json["acl"].items()) {
    auto parsed = internal::BucketAccessControlParser::FromJson(kv.value());
    if (!parsed.ok()) return std::move(parsed).status();
    value.push_back(std::move(*parsed));
  }
  acl = std::move(value);
  return Status{};
}

Status ParseBilling(absl::optional<BucketBilling>& billing,
                    nlohmann::json const& json) {
  if (!json.contains("billing")) return Status{};
  auto b = json["billing"];
  auto requester_pays = internal::ParseBoolField(b, "requesterPays");
  if (!requester_pays) return std::move(requester_pays).status();
  billing = BucketBilling{*requester_pays};
  return Status{};
}

Status ParseCorsList(std::vector<CorsEntry>& list, nlohmann::json const& json) {
  if (!json.contains("cors")) return Status{};
  std::vector<CorsEntry> value;
  for (auto const& kv : json["cors"].items()) {
    auto cors = ParseCors(kv.value());
    if (!cors) return std::move(cors).status();
    value.push_back(*std::move(cors));
  }
  list = std::move(value);
  return Status{};
}

Status ParseDefaultEventBasedHold(bool& default_event_based_hold,
                                  nlohmann::json const& json) {
  if (json.contains("defaultEventBasedHold")) {
    default_event_based_hold = json.value("defaultEventBasedHold", false);
  }
  return Status{};
}

Status ParseDefaultObjectAcl(std::vector<ObjectAccessControl>& acl,
                             nlohmann::json const& json) {
  if (!json.contains("defaultObjectAcl")) return Status{};
  std::vector<ObjectAccessControl> value;
  for (auto const& kv : json["defaultObjectAcl"].items()) {
    auto parsed = internal::ObjectAccessControlParser::FromJson(kv.value());
    if (!parsed.ok()) return std::move(parsed).status();
    value.push_back(std::move(*parsed));
  }
  acl = std::move(value);
  return Status{};
}

Status ParseEncryption(absl::optional<BucketEncryption>& encryption,
                       nlohmann::json const& json) {
  if (json.contains("encryption")) {
    BucketEncryption e;
    e.default_kms_key_name = json["encryption"].value("defaultKmsKeyName", "");
    encryption = std::move(e);
  }
  return Status{};
}

Status ParseIamConfiguration(
    absl::optional<BucketIamConfiguration>& iam_configuration,
    nlohmann::json const& json) {
  if (!json.contains("iamConfiguration")) return Status{};
  BucketIamConfiguration value;
  auto c = json["iamConfiguration"];
  if (c.contains("uniformBucketLevelAccess")) {
    auto ubla = ParseUniformBucketLevelAccess(c["uniformBucketLevelAccess"]);
    if (!ubla) return std::move(ubla).status();
    value.uniform_bucket_level_access = *ubla;
  }
  if (c.contains("publicAccessPrevention")) {
    value.public_access_prevention = c.value("publicAccessPrevention", "");
  }
  iam_configuration = std::move(value);
  return Status{};
}

Status ParseLifecycle(absl::optional<BucketLifecycle>& lifecycle,
                      nlohmann::json const& json) {
  if (!json.contains("lifecycle")) return Status{};
  auto l = json["lifecycle"];
  BucketLifecycle value;
  if (l.contains("rule")) {
    for (auto const& kv : l["rule"].items()) {
      auto parsed = internal::LifecycleRuleParser::FromJson(kv.value());
      if (!parsed.ok()) return std::move(parsed).status();
      value.rule.emplace_back(std::move(*parsed));
    }
  }
  lifecycle = std::move(value);
  return Status{};
}

Status ParseLogging(absl::optional<BucketLogging>& logging,
                    nlohmann::json const& json) {
  if (!json.contains("logging")) return Status{};
  auto l = json["logging"];
  BucketLogging value;
  value.log_bucket = l.value("logBucket", "");
  value.log_object_prefix = l.value("logObjectPrefix", "");
  logging = std::move(value);
  return Status{};
}

std::map<std::string, std::string> ParseLabels(nlohmann::json const& json) {
  if (!json.contains("labels")) return {};
  std::map<std::string, std::string> value;
  for (auto const& kv : json["labels"].items()) {
    value.emplace(kv.key(), kv.value().get<std::string>());
  }
  return value;
}

Status ParseProjectNumber(std::int64_t& project_number,
                          nlohmann::json const& json) {
  auto p = internal::ParseLongField(json, "projectNumber");
  if (!p) return std::move(p).status();
  project_number = *p;
  return Status{};
}

Status ParseRetentionPolicy(
    absl::optional<BucketRetentionPolicy>& retention_policy,
    nlohmann::json const& json) {
  if (!json.contains("retentionPolicy")) return Status{};
  auto r = json["retentionPolicy"];
  auto is_locked = internal::ParseBoolField(r, "isLocked");
  if (!is_locked) return std::move(is_locked).status();
  auto retention_period = internal::ParseLongField(r, "retentionPeriod");
  if (!retention_period) return std::move(retention_period).status();
  auto effective_time = internal::ParseTimestampField(r, "effectiveTime");
  if (!effective_time) return std::move(effective_time).status();
  retention_policy = BucketRetentionPolicy{
      std::chrono::seconds(*retention_period), *effective_time, *is_locked};
  return Status{};
}

Status ParseVersioning(absl::optional<BucketVersioning>& versioning,
                       nlohmann::json const& json) {
  if (!json.contains("versioning")) return Status{};
  auto v = json["versioning"];
  if (!v.contains("enabled")) return Status{};
  auto enabled = internal::ParseBoolField(v, "enabled");
  if (!enabled) return std::move(enabled).status();
  versioning = BucketVersioning{*enabled};
  return Status{};
}

Status ParseWebsite(absl::optional<BucketWebsite>& website,
                    nlohmann::json const& json) {
  if (!json.contains("website")) return Status{};
  auto w = json["website"];
  BucketWebsite value;
  value.main_page_suffix = w.value("mainPageSuffix", "");
  value.not_found_page = w.value("notFoundPage", "");
  website = std::move(value);
  return Status{};
}

void ToJsonAcl(nlohmann::json& json, BucketMetadata const& meta) {
  if (meta.acl().empty()) return;
  nlohmann::json value;
  for (BucketAccessControl const& a : meta.acl()) {
    nlohmann::json entry;
    SetIfNotEmpty(entry, "entity", a.entity());
    SetIfNotEmpty(entry, "role", a.role());
    value.push_back(std::move(entry));
  }
  json["acl"] = std::move(value);
}

void ToJsonCors(nlohmann::json& json, BucketMetadata const& meta) {
  if (meta.cors().empty()) return;
  nlohmann::json value;
  for (CorsEntry const& v : meta.cors()) {
    nlohmann::json cors_as_json;
    if (v.max_age_seconds.has_value()) {
      cors_as_json["maxAgeSeconds"] = *v.max_age_seconds;
    }
    if (!v.method.empty()) {
      cors_as_json["method"] = v.method;
    }
    if (!v.origin.empty()) {
      cors_as_json["origin"] = v.origin;
    }
    if (!v.response_header.empty()) {
      cors_as_json["responseHeader"] = v.response_header;
    }
    value.emplace_back(std::move(cors_as_json));
  }
  json["cors"] = std::move(value);
}

void ToJsonBilling(nlohmann::json& json, BucketMetadata const& meta) {
  if (!meta.has_billing()) return;
  json["billing"] = nlohmann::json{
      {"requesterPays", meta.billing().requester_pays},
  };
}

void ToJsonDefaultEventBasedHold(nlohmann::json& json,
                                 BucketMetadata const& meta) {
  json["defaultEventBasedHold"] = meta.default_event_based_hold();
}

void ToJsonDefaultAcl(nlohmann::json& json, BucketMetadata const& meta) {
  if (meta.default_acl().empty()) return;
  nlohmann::json value;
  for (ObjectAccessControl const& a : meta.default_acl()) {
    nlohmann::json entry;
    SetIfNotEmpty(entry, "entity", a.entity());
    SetIfNotEmpty(entry, "role", a.role());
    value.push_back(std::move(entry));
  }
  json["defaultObjectAcl"] = std::move(value);
}

void ToJsonEncryption(nlohmann::json& json, BucketMetadata const& meta) {
  if (!meta.has_encryption()) return;
  nlohmann::json e;
  SetIfNotEmpty(e, "defaultKmsKeyName", meta.encryption().default_kms_key_name);
  json["encryption"] = std::move(e);
}

void ToJsonIamConfiguration(nlohmann::json& json, BucketMetadata const& meta) {
  if (!meta.has_iam_configuration()) return;
  nlohmann::json value;
  if (meta.iam_configuration().uniform_bucket_level_access.has_value()) {
    // The lockedTime field is not mutable and should not be set by the client
    // the server will provide a value.
    value["uniformBucketLevelAccess"] = nlohmann::json{
        {"enabled",
         meta.iam_configuration().uniform_bucket_level_access->enabled}};
  }
  if (meta.iam_configuration().public_access_prevention.has_value()) {
    value["publicAccessPrevention"] =
        *meta.iam_configuration().public_access_prevention;
  }
  json["iamConfiguration"] = std::move(value);
}

void ToJsonLabels(nlohmann::json& json, BucketMetadata const& meta) {
  if (meta.labels().empty()) return;
  nlohmann::json value;
  for (auto const& kv : meta.labels()) {
    value[kv.first] = kv.second;
  }
  json["labels"] = std::move(value);
}

void ToJsonLifecycle(nlohmann::json& json, BucketMetadata const& meta) {
  if (!meta.has_lifecycle()) return;
  nlohmann::json value;
  for (LifecycleRule const& v : meta.lifecycle().rule) {
    nlohmann::json condition;
    auto const& c = v.condition();
    if (c.age) {
      condition["age"] = *c.age;
    }
    if (c.created_before.has_value()) {
      condition["createdBefore"] =
          absl::StrFormat("%04d-%02d-%02d", c.created_before->year(),
                          c.created_before->month(), c.created_before->day());
    }
    if (c.is_live) {
      condition["isLive"] = *c.is_live;
    }
    if (c.matches_storage_class) {
      condition["matchesStorageClass"] = *c.matches_storage_class;
    }
    if (c.num_newer_versions) {
      condition["numNewerVersions"] = *c.num_newer_versions;
    }
    nlohmann::json action{{"type", v.action().type}};
    if (!v.action().storage_class.empty()) {
      action["storageClass"] = v.action().storage_class;
    }
    value.emplace_back(nlohmann::json{{"condition", std::move(condition)},
                                      {"action", std::move(action)}});
  }
  json["lifecycle"] = nlohmann::json{{"rule", std::move(value)}};
}

void ToJsonLocation(nlohmann::json& json, BucketMetadata const& meta) {
  SetIfNotEmpty(json, "location", meta.location());
}

void ToJsonLocationType(nlohmann::json& json, BucketMetadata const& meta) {
  SetIfNotEmpty(json, "locationType", meta.location_type());
}

void ToJsonLogging(nlohmann::json& json, BucketMetadata const& meta) {
  if (!meta.has_logging()) return;
  nlohmann::json value;
  SetIfNotEmpty(value, "logBucket", meta.logging().log_bucket);
  SetIfNotEmpty(value, "logObjectPrefix", meta.logging().log_object_prefix);
  json["logging"] = std::move(value);
}

void ToJsonName(nlohmann::json& json, BucketMetadata const& meta) {
  SetIfNotEmpty(json, "name", meta.name());
}

void ToJsonRetentionPolicy(nlohmann::json& json, BucketMetadata const& meta) {
  if (!meta.has_retention_policy()) return;
  json["retentionPolicy"] = nlohmann::json{
      {"retentionPeriod", meta.retention_policy().retention_period.count()}};
}

void ToJsonRpo(nlohmann::json& json, BucketMetadata const& meta) {
  SetIfNotEmpty(json, "rpo", meta.rpo());
}

void ToJsonStorageClass(nlohmann::json& json, BucketMetadata const& meta) {
  SetIfNotEmpty(json, "storageClass", meta.storage_class());
}

void ToJsonVersioning(nlohmann::json& json, BucketMetadata const& meta) {
  if (!meta.versioning().has_value()) return;
  json["versioning"] = nlohmann::json{{"enabled", meta.versioning()->enabled}};
}

void ToJsonWebsite(nlohmann::json& json, BucketMetadata const& meta) {
  if (!meta.has_website()) return;
  nlohmann::json value;
  SetIfNotEmpty(value, "mainPageSuffix", meta.website().main_page_suffix);
  SetIfNotEmpty(value, "notFoundPage", meta.website().not_found_page);
  json["website"] = std::move(value);
}

}  // namespace

StatusOr<BucketMetadata> BucketMetadataParser::FromJson(
    nlohmann::json const& json) {
  if (!json.is_object()) {
    return Status(StatusCode::kInvalidArgument, __func__);
  }

  using Parser = std::function<Status(BucketMetadata&, nlohmann::json const&)>;
  Parser parsers[] = {
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return CommonMetadataParser<BucketMetadata>::FromJson(meta, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseAcl(meta.acl_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseBilling(meta.billing_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseCorsList(meta.cors_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseDefaultEventBasedHold(meta.default_event_based_hold_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseDefaultObjectAcl(meta.default_acl_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseEncryption(meta.encryption_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseIamConfiguration(meta.iam_configuration_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseLifecycle(meta.lifecycle_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        meta.location_ = json.value("location", "");
        return Status{};
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        meta.location_type_ = json.value("locationType", "");
        return Status{};
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseLogging(meta.logging_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseProjectNumber(meta.project_number_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        meta.labels_ = ParseLabels(json);
        return Status{};
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseRetentionPolicy(meta.retention_policy_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        meta.rpo_ = json.value("rpo", "");
        return Status{};
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseVersioning(meta.versioning_, json);
      },
      [](BucketMetadata& meta, nlohmann::json const& json) {
        return ParseWebsite(meta.website_, json);
      },
  };

  BucketMetadata meta{};
  for (auto const& p : parsers) {
    auto status = p(meta, json);
    if (!status.ok()) return status;
  }
  return meta;
}

StatusOr<BucketMetadata> BucketMetadataParser::FromString(
    std::string const& payload) {
  auto json = nlohmann::json::parse(payload, nullptr, false);
  return FromJson(json);
}

std::string BucketMetadataToJsonString(BucketMetadata const& meta) {
  nlohmann::json json;
  ToJsonAcl(json, meta);
  ToJsonBilling(json, meta);
  ToJsonCors(json, meta);
  ToJsonDefaultEventBasedHold(json, meta);
  ToJsonDefaultAcl(json, meta);
  ToJsonEncryption(json, meta);
  ToJsonIamConfiguration(json, meta);
  ToJsonLabels(json, meta);
  ToJsonLifecycle(json, meta);
  ToJsonLocation(json, meta);
  ToJsonLocationType(json, meta);
  ToJsonLogging(json, meta);
  ToJsonName(json, meta);
  ToJsonRetentionPolicy(json, meta);
  ToJsonRpo(json, meta);
  ToJsonStorageClass(json, meta);
  ToJsonVersioning(json, meta);
  ToJsonWebsite(json, meta);

  return json.dump();
}

}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage
}  // namespace cloud
}  // namespace google
