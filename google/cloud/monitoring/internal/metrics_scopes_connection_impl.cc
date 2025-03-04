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
// source: google/monitoring/metricsscope/v1/metrics_scopes.proto

#include "google/cloud/monitoring/internal/metrics_scopes_connection_impl.h"
#include "google/cloud/monitoring/internal/metrics_scopes_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

MetricsScopesConnectionImpl::MetricsScopesConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<monitoring_internal::MetricsScopesStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options), monitoring_internal::MetricsScopesDefaultOptions(
                                  MetricsScopesConnection::options()))) {}

StatusOr<google::monitoring::metricsscope::v1::MetricsScope>
MetricsScopesConnectionImpl::GetMetricsScope(
    google::monitoring::metricsscope::v1::GetMetricsScopeRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetMetricsScope(request),
      [this](grpc::ClientContext& context,
             google::monitoring::metricsscope::v1::GetMetricsScopeRequest const&
                 request) { return stub_->GetMetricsScope(context, request); },
      request, __func__);
}

StatusOr<google::monitoring::metricsscope::v1::
             ListMetricsScopesByMonitoredProjectResponse>
MetricsScopesConnectionImpl::ListMetricsScopesByMonitoredProject(
    google::monitoring::metricsscope::v1::
        ListMetricsScopesByMonitoredProjectRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->ListMetricsScopesByMonitoredProject(request),
      [this](grpc::ClientContext& context,
             google::monitoring::metricsscope::v1::
                 ListMetricsScopesByMonitoredProjectRequest const& request) {
        return stub_->ListMetricsScopesByMonitoredProject(context, request);
      },
      request, __func__);
}

future<StatusOr<google::monitoring::metricsscope::v1::MonitoredProject>>
MetricsScopesConnectionImpl::CreateMonitoredProject(
    google::monitoring::metricsscope::v1::CreateMonitoredProjectRequest const&
        request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::monitoring::metricsscope::v1::MonitoredProject>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::monitoring::metricsscope::v1::
                 CreateMonitoredProjectRequest const& request) {
        return stub->AsyncCreateMonitoredProject(cq, std::move(context),
                                                 request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::monitoring::metricsscope::v1::MonitoredProject>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateMonitoredProject(request), polling_policy(),
      __func__);
}

future<StatusOr<google::monitoring::metricsscope::v1::OperationMetadata>>
MetricsScopesConnectionImpl::DeleteMonitoredProject(
    google::monitoring::metricsscope::v1::DeleteMonitoredProjectRequest const&
        request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::monitoring::metricsscope::v1::OperationMetadata>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::monitoring::metricsscope::v1::
                 DeleteMonitoredProjectRequest const& request) {
        return stub->AsyncDeleteMonitoredProject(cq, std::move(context),
                                                 request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultMetadata<
          google::monitoring::metricsscope::v1::OperationMetadata>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteMonitoredProject(request), polling_policy(),
      __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google
