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
// source: google/cloud/orchestration/airflow/service/v1/image_versions.proto

#include "google/cloud/composer/image_versions_client.h"
#include "google/cloud/composer/internal/image_versions_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace composer {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ImageVersionsClient::ImageVersionsClient(
    std::shared_ptr<ImageVersionsConnection> connection, Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options), composer_internal::ImageVersionsDefaultOptions(
                                  connection_->options()))) {}
ImageVersionsClient::~ImageVersionsClient() = default;

StreamRange<google::cloud::orchestration::airflow::service::v1::ImageVersion>
ImageVersionsClient::ListImageVersions(std::string const& parent,
                                       Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::orchestration::airflow::service::v1::ListImageVersionsRequest
      request;
  request.set_parent(parent);
  return connection_->ListImageVersions(request);
}

StreamRange<google::cloud::orchestration::airflow::service::v1::ImageVersion>
ImageVersionsClient::ListImageVersions(
    google::cloud::orchestration::airflow::service::v1::ListImageVersionsRequest
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListImageVersions(std::move(request));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace composer
}  // namespace cloud
}  // namespace google
