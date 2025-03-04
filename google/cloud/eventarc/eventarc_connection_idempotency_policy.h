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
// source: google/cloud/eventarc/v1/eventarc.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_EVENTARC_EVENTARC_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_EVENTARC_EVENTARC_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/cloud/eventarc/v1/eventarc.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace eventarc {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class EventarcConnectionIdempotencyPolicy {
 public:
  virtual ~EventarcConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<EventarcConnectionIdempotencyPolicy> clone()
      const = 0;

  virtual google::cloud::Idempotency GetTrigger(
      google::cloud::eventarc::v1::GetTriggerRequest const& request) = 0;

  virtual google::cloud::Idempotency ListTriggers(
      google::cloud::eventarc::v1::ListTriggersRequest request) = 0;

  virtual google::cloud::Idempotency CreateTrigger(
      google::cloud::eventarc::v1::CreateTriggerRequest const& request) = 0;

  virtual google::cloud::Idempotency UpdateTrigger(
      google::cloud::eventarc::v1::UpdateTriggerRequest const& request) = 0;

  virtual google::cloud::Idempotency DeleteTrigger(
      google::cloud::eventarc::v1::DeleteTriggerRequest const& request) = 0;
};

std::unique_ptr<EventarcConnectionIdempotencyPolicy>
MakeDefaultEventarcConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace eventarc
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_EVENTARC_EVENTARC_CONNECTION_IDEMPOTENCY_POLICY_H
