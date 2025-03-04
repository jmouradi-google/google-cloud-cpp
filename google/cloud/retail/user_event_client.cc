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
// source: google/cloud/retail/v2/user_event_service.proto

#include "google/cloud/retail/user_event_client.h"
#include "google/cloud/retail/internal/user_event_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace retail {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

UserEventServiceClient::UserEventServiceClient(
    std::shared_ptr<UserEventServiceConnection> connection, Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options), retail_internal::UserEventServiceDefaultOptions(
                                  connection_->options()))) {}
UserEventServiceClient::~UserEventServiceClient() = default;

StatusOr<google::cloud::retail::v2::UserEvent>
UserEventServiceClient::WriteUserEvent(
    google::cloud::retail::v2::WriteUserEventRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->WriteUserEvent(request);
}

StatusOr<google::api::HttpBody> UserEventServiceClient::CollectUserEvent(
    google::cloud::retail::v2::CollectUserEventRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CollectUserEvent(request);
}

future<StatusOr<google::cloud::retail::v2::PurgeUserEventsResponse>>
UserEventServiceClient::PurgeUserEvents(
    google::cloud::retail::v2::PurgeUserEventsRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->PurgeUserEvents(request);
}

future<StatusOr<google::cloud::retail::v2::ImportUserEventsResponse>>
UserEventServiceClient::ImportUserEvents(
    google::cloud::retail::v2::ImportUserEventsRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ImportUserEvents(request);
}

future<StatusOr<google::cloud::retail::v2::RejoinUserEventsResponse>>
UserEventServiceClient::RejoinUserEvents(
    google::cloud::retail::v2::RejoinUserEventsRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->RejoinUserEvents(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace retail
}  // namespace cloud
}  // namespace google
