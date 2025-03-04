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
// source: google/cloud/redis/v1/cloud_redis.proto

#include "google/cloud/redis/internal/cloud_redis_connection_impl.h"
#include "google/cloud/redis/internal/cloud_redis_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace redis_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudRedisConnectionImpl::CloudRedisConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<redis_internal::CloudRedisStub> stub, Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(std::move(options),
                                      redis_internal::CloudRedisDefaultOptions(
                                          CloudRedisConnection::options()))) {}

StreamRange<google::cloud::redis::v1::Instance>
CloudRedisConnectionImpl::ListInstances(
    google::cloud::redis::v1::ListInstancesRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry =
      std::shared_ptr<redis::CloudRedisRetryPolicy const>(retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListInstances(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::redis::v1::Instance>>(
      std::move(request),
      [stub, retry, backoff, idempotency,
       function_name](google::cloud::redis::v1::ListInstancesRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](
                grpc::ClientContext& context,
                google::cloud::redis::v1::ListInstancesRequest const& request) {
              return stub->ListInstances(context, request);
            },
            r, function_name);
      },
      [](google::cloud::redis::v1::ListInstancesResponse r) {
        std::vector<google::cloud::redis::v1::Instance> result(
            r.instances().size());
        auto& messages = *r.mutable_instances();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::redis::v1::Instance>
CloudRedisConnectionImpl::GetInstance(
    google::cloud::redis::v1::GetInstanceRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetInstance(request),
      [this](grpc::ClientContext& context,
             google::cloud::redis::v1::GetInstanceRequest const& request) {
        return stub_->GetInstance(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::redis::v1::Instance>>
CloudRedisConnectionImpl::CreateInstance(
    google::cloud::redis::v1::CreateInstanceRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::redis::v1::Instance>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::redis::v1::CreateInstanceRequest const& request) {
        return stub->AsyncCreateInstance(cq, std::move(context), request);
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
          google::cloud::redis::v1::Instance>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateInstance(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::redis::v1::Instance>>
CloudRedisConnectionImpl::UpdateInstance(
    google::cloud::redis::v1::UpdateInstanceRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::redis::v1::Instance>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::redis::v1::UpdateInstanceRequest const& request) {
        return stub->AsyncUpdateInstance(cq, std::move(context), request);
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
          google::cloud::redis::v1::Instance>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateInstance(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::redis::v1::Instance>>
CloudRedisConnectionImpl::UpgradeInstance(
    google::cloud::redis::v1::UpgradeInstanceRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::redis::v1::Instance>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::redis::v1::UpgradeInstanceRequest const& request) {
        return stub->AsyncUpgradeInstance(cq, std::move(context), request);
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
          google::cloud::redis::v1::Instance>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpgradeInstance(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::redis::v1::Instance>>
CloudRedisConnectionImpl::ImportInstance(
    google::cloud::redis::v1::ImportInstanceRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::redis::v1::Instance>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::redis::v1::ImportInstanceRequest const& request) {
        return stub->AsyncImportInstance(cq, std::move(context), request);
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
          google::cloud::redis::v1::Instance>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ImportInstance(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::redis::v1::Instance>>
CloudRedisConnectionImpl::ExportInstance(
    google::cloud::redis::v1::ExportInstanceRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::redis::v1::Instance>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::redis::v1::ExportInstanceRequest const& request) {
        return stub->AsyncExportInstance(cq, std::move(context), request);
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
          google::cloud::redis::v1::Instance>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ExportInstance(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::redis::v1::Instance>>
CloudRedisConnectionImpl::FailoverInstance(
    google::cloud::redis::v1::FailoverInstanceRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::redis::v1::Instance>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::redis::v1::FailoverInstanceRequest const& request) {
        return stub->AsyncFailoverInstance(cq, std::move(context), request);
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
          google::cloud::redis::v1::Instance>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->FailoverInstance(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::redis::v1::OperationMetadata>>
CloudRedisConnectionImpl::DeleteInstance(
    google::cloud::redis::v1::DeleteInstanceRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::redis::v1::OperationMetadata>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::redis::v1::DeleteInstanceRequest const& request) {
        return stub->AsyncDeleteInstance(cq, std::move(context), request);
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
          google::cloud::redis::v1::OperationMetadata>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteInstance(request), polling_policy(),
      __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace redis_internal
}  // namespace cloud
}  // namespace google
