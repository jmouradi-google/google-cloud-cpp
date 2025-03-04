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
// source: google/monitoring/v3/uptime_service.proto

#include "google/cloud/monitoring/uptime_check_connection.h"
#include "google/cloud/monitoring/internal/uptime_check_connection_impl.h"
#include "google/cloud/monitoring/internal/uptime_check_option_defaults.h"
#include "google/cloud/monitoring/internal/uptime_check_stub_factory.h"
#include "google/cloud/monitoring/uptime_check_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

UptimeCheckServiceConnection::~UptimeCheckServiceConnection() = default;

StreamRange<google::monitoring::v3::UptimeCheckConfig>
    UptimeCheckServiceConnection::ListUptimeCheckConfigs(
        google::monitoring::v3::
            ListUptimeCheckConfigsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::monitoring::v3::UptimeCheckConfig>>();
}

StatusOr<google::monitoring::v3::UptimeCheckConfig>
UptimeCheckServiceConnection::GetUptimeCheckConfig(
    google::monitoring::v3::GetUptimeCheckConfigRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::monitoring::v3::UptimeCheckConfig>
UptimeCheckServiceConnection::CreateUptimeCheckConfig(
    google::monitoring::v3::CreateUptimeCheckConfigRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::monitoring::v3::UptimeCheckConfig>
UptimeCheckServiceConnection::UpdateUptimeCheckConfig(
    google::monitoring::v3::UpdateUptimeCheckConfigRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status UptimeCheckServiceConnection::DeleteUptimeCheckConfig(
    google::monitoring::v3::DeleteUptimeCheckConfigRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::monitoring::v3::UptimeCheckIp>
    UptimeCheckServiceConnection::ListUptimeCheckIps(
        google::monitoring::v3::
            ListUptimeCheckIpsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::monitoring::v3::UptimeCheckIp>>();
}

std::shared_ptr<UptimeCheckServiceConnection> MakeUptimeCheckServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UptimeCheckServicePolicyOptionList>(options,
                                                                     __func__);
  options =
      monitoring_internal::UptimeCheckServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = monitoring_internal::CreateDefaultUptimeCheckServiceStub(
      background->cq(), options);
  return std::make_shared<
      monitoring_internal::UptimeCheckServiceConnectionImpl>(
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

std::shared_ptr<monitoring::UptimeCheckServiceConnection>
MakeUptimeCheckServiceConnection(std::shared_ptr<UptimeCheckServiceStub> stub,
                                 Options options) {
  options = UptimeCheckServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<
      monitoring_internal::UptimeCheckServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google
