// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: generator/integration_tests/test.proto

#include "generator/integration_tests/golden/golden_kitchen_sink_client.h"
#include "generator/integration_tests/golden/internal/golden_kitchen_sink_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace golden {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

GoldenKitchenSinkClient::GoldenKitchenSinkClient(std::shared_ptr<GoldenKitchenSinkConnection> connection, Options options) : connection_(std::move(connection)), options_(internal::MergeOptions(std::move(options), golden_internal::GoldenKitchenSinkDefaultOptions(connection_->options()))) {}
GoldenKitchenSinkClient::~GoldenKitchenSinkClient() = default;

StatusOr<google::test::admin::database::v1::GenerateAccessTokenResponse>
GoldenKitchenSinkClient::GenerateAccessToken(std::string const& name, std::vector<std::string> const& delegates, std::vector<std::string> const& scope, google::protobuf::Duration const& lifetime, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  google::test::admin::database::v1::GenerateAccessTokenRequest request;
  request.set_name(name);
  *request.mutable_delegates() = {delegates.begin(), delegates.end()};
  *request.mutable_scope() = {scope.begin(), scope.end()};
  *request.mutable_lifetime() = lifetime;
  return connection_->GenerateAccessToken(request);
}

StatusOr<google::test::admin::database::v1::GenerateAccessTokenResponse>
GoldenKitchenSinkClient::GenerateAccessToken(google::test::admin::database::v1::GenerateAccessTokenRequest const& request, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  return connection_->GenerateAccessToken(request);
}

StatusOr<google::test::admin::database::v1::GenerateIdTokenResponse>
GoldenKitchenSinkClient::GenerateIdToken(std::string const& name, std::vector<std::string> const& delegates, std::string const& audience, bool include_email, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  google::test::admin::database::v1::GenerateIdTokenRequest request;
  request.set_name(name);
  *request.mutable_delegates() = {delegates.begin(), delegates.end()};
  request.set_audience(audience);
  request.set_include_email(include_email);
  return connection_->GenerateIdToken(request);
}

StatusOr<google::test::admin::database::v1::GenerateIdTokenResponse>
GoldenKitchenSinkClient::GenerateIdToken(google::test::admin::database::v1::GenerateIdTokenRequest const& request, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  return connection_->GenerateIdToken(request);
}

StatusOr<google::test::admin::database::v1::WriteLogEntriesResponse>
GoldenKitchenSinkClient::WriteLogEntries(std::string const& log_name, std::map<std::string, std::string> const& labels, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  google::test::admin::database::v1::WriteLogEntriesRequest request;
  request.set_log_name(log_name);
  *request.mutable_labels() = {labels.begin(), labels.end()};
  return connection_->WriteLogEntries(request);
}

StatusOr<google::test::admin::database::v1::WriteLogEntriesResponse>
GoldenKitchenSinkClient::WriteLogEntries(google::test::admin::database::v1::WriteLogEntriesRequest const& request, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  return connection_->WriteLogEntries(request);
}

StreamRange<std::string>
GoldenKitchenSinkClient::ListLogs(std::string const& parent, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  google::test::admin::database::v1::ListLogsRequest request;
  request.set_parent(parent);
  return connection_->ListLogs(request);
}

StreamRange<std::string>
GoldenKitchenSinkClient::ListLogs(google::test::admin::database::v1::ListLogsRequest request, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  return connection_->ListLogs(std::move(request));
}

StreamRange<google::test::admin::database::v1::TailLogEntriesResponse>
GoldenKitchenSinkClient::TailLogEntries(std::vector<std::string> const& resource_names, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  google::test::admin::database::v1::TailLogEntriesRequest request;
  *request.mutable_resource_names() = {resource_names.begin(), resource_names.end()};
  return connection_->TailLogEntries(request);
}

StreamRange<google::test::admin::database::v1::TailLogEntriesResponse>
GoldenKitchenSinkClient::TailLogEntries(google::test::admin::database::v1::TailLogEntriesRequest const& request, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  return connection_->TailLogEntries(request);
}

StatusOr<google::test::admin::database::v1::ListServiceAccountKeysResponse>
GoldenKitchenSinkClient::ListServiceAccountKeys(std::string const& name, std::vector<google::test::admin::database::v1::ListServiceAccountKeysRequest::KeyType> const& key_types, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  google::test::admin::database::v1::ListServiceAccountKeysRequest request;
  request.set_name(name);
  *request.mutable_key_types() = {key_types.begin(), key_types.end()};
  return connection_->ListServiceAccountKeys(request);
}

StatusOr<google::test::admin::database::v1::ListServiceAccountKeysResponse>
GoldenKitchenSinkClient::ListServiceAccountKeys(google::test::admin::database::v1::ListServiceAccountKeysRequest const& request, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  return connection_->ListServiceAccountKeys(request);
}

Status
GoldenKitchenSinkClient::DoNothing(Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  google::protobuf::Empty request;
  return connection_->DoNothing(request);
}

Status
GoldenKitchenSinkClient::DoNothing(google::protobuf::Empty const& request, Options options) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(options), options_));
  return connection_->DoNothing(request);
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::test::admin::database::v1::AppendRowsRequest,
    google::test::admin::database::v1::AppendRowsResponse>>
GoldenKitchenSinkClient::AsyncAppendRows(Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->AsyncAppendRows();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace golden
}  // namespace cloud
}  // namespace google
