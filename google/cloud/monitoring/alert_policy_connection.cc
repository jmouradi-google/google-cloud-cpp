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
// source: google/monitoring/v3/alert_service.proto

#include "google/cloud/monitoring/alert_policy_connection.h"
#include "google/cloud/monitoring/alert_policy_options.h"
#include "google/cloud/monitoring/internal/alert_policy_connection_impl.h"
#include "google/cloud/monitoring/internal/alert_policy_option_defaults.h"
#include "google/cloud/monitoring/internal/alert_policy_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

AlertPolicyServiceConnection::~AlertPolicyServiceConnection() = default;

StreamRange<google::monitoring::v3::AlertPolicy>
    AlertPolicyServiceConnection::ListAlertPolicies(
        google::monitoring::v3::
            ListAlertPoliciesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::monitoring::v3::AlertPolicy>>();
}

StatusOr<google::monitoring::v3::AlertPolicy>
AlertPolicyServiceConnection::GetAlertPolicy(
    google::monitoring::v3::GetAlertPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::monitoring::v3::AlertPolicy>
AlertPolicyServiceConnection::CreateAlertPolicy(
    google::monitoring::v3::CreateAlertPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status AlertPolicyServiceConnection::DeleteAlertPolicy(
    google::monitoring::v3::DeleteAlertPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::monitoring::v3::AlertPolicy>
AlertPolicyServiceConnection::UpdateAlertPolicy(
    google::monitoring::v3::UpdateAlertPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<AlertPolicyServiceConnection> MakeAlertPolicyServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 AlertPolicyServicePolicyOptionList>(options,
                                                                     __func__);
  options =
      monitoring_internal::AlertPolicyServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = monitoring_internal::CreateDefaultAlertPolicyServiceStub(
      background->cq(), options);
  return std::make_shared<
      monitoring_internal::AlertPolicyServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<monitoring::AlertPolicyServiceConnection>
MakeAlertPolicyServiceConnection(std::shared_ptr<AlertPolicyServiceStub> stub,
                                 Options options) {
  options = AlertPolicyServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<
      monitoring_internal::AlertPolicyServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google
