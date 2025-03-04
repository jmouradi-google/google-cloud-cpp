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
// source: google/cloud/videointelligence/v1/video_intelligence.proto

#include "google/cloud/videointelligence/video_intelligence_client.h"
#include "google/cloud/videointelligence/internal/video_intelligence_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace videointelligence {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

VideoIntelligenceServiceClient::VideoIntelligenceServiceClient(
    std::shared_ptr<VideoIntelligenceServiceConnection> connection,
    Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options),
          videointelligence_internal::VideoIntelligenceServiceDefaultOptions(
              connection_->options()))) {}
VideoIntelligenceServiceClient::~VideoIntelligenceServiceClient() = default;

future<StatusOr<google::cloud::videointelligence::v1::AnnotateVideoResponse>>
VideoIntelligenceServiceClient::AnnotateVideo(
    std::string const& input_uri,
    std::vector<google::cloud::videointelligence::v1::Feature> const& features,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::videointelligence::v1::AnnotateVideoRequest request;
  request.set_input_uri(input_uri);
  *request.mutable_features() = {features.begin(), features.end()};
  return connection_->AnnotateVideo(request);
}

future<StatusOr<google::cloud::videointelligence::v1::AnnotateVideoResponse>>
VideoIntelligenceServiceClient::AnnotateVideo(
    google::cloud::videointelligence::v1::AnnotateVideoRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->AnnotateVideo(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace videointelligence
}  // namespace cloud
}  // namespace google
