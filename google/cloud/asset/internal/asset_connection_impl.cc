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
// source: google/cloud/asset/v1/asset_service.proto

#include "google/cloud/asset/internal/asset_connection_impl.h"
#include "google/cloud/asset/internal/asset_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace asset_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

AssetServiceConnectionImpl::AssetServiceConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<asset_internal::AssetServiceStub> stub, Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options), asset_internal::AssetServiceDefaultOptions(
                                  AssetServiceConnection::options()))) {}

future<StatusOr<google::cloud::asset::v1::ExportAssetsResponse>>
AssetServiceConnectionImpl::ExportAssets(
    google::cloud::asset::v1::ExportAssetsRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::asset::v1::ExportAssetsResponse>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::asset::v1::ExportAssetsRequest const& request) {
        return stub->AsyncExportAssets(cq, std::move(context), request);
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
          google::cloud::asset::v1::ExportAssetsResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ExportAssets(request), polling_policy(), __func__);
}

StreamRange<google::cloud::asset::v1::Asset>
AssetServiceConnectionImpl::ListAssets(
    google::cloud::asset::v1::ListAssetsRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry =
      std::shared_ptr<asset::AssetServiceRetryPolicy const>(retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListAssets(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::asset::v1::Asset>>(
      std::move(request),
      [stub, retry, backoff, idempotency,
       function_name](google::cloud::asset::v1::ListAssetsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::asset::v1::ListAssetsRequest const& request) {
              return stub->ListAssets(context, request);
            },
            r, function_name);
      },
      [](google::cloud::asset::v1::ListAssetsResponse r) {
        std::vector<google::cloud::asset::v1::Asset> result(r.assets().size());
        auto& messages = *r.mutable_assets();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::asset::v1::BatchGetAssetsHistoryResponse>
AssetServiceConnectionImpl::BatchGetAssetsHistory(
    google::cloud::asset::v1::BatchGetAssetsHistoryRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->BatchGetAssetsHistory(request),
      [this](grpc::ClientContext& context,
             google::cloud::asset::v1::BatchGetAssetsHistoryRequest const&
                 request) {
        return stub_->BatchGetAssetsHistory(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::asset::v1::Feed> AssetServiceConnectionImpl::CreateFeed(
    google::cloud::asset::v1::CreateFeedRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateFeed(request),
      [this](grpc::ClientContext& context,
             google::cloud::asset::v1::CreateFeedRequest const& request) {
        return stub_->CreateFeed(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::asset::v1::Feed> AssetServiceConnectionImpl::GetFeed(
    google::cloud::asset::v1::GetFeedRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->GetFeed(request),
      [this](grpc::ClientContext& context,
             google::cloud::asset::v1::GetFeedRequest const& request) {
        return stub_->GetFeed(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::asset::v1::ListFeedsResponse>
AssetServiceConnectionImpl::ListFeeds(
    google::cloud::asset::v1::ListFeedsRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->ListFeeds(request),
      [this](grpc::ClientContext& context,
             google::cloud::asset::v1::ListFeedsRequest const& request) {
        return stub_->ListFeeds(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::asset::v1::Feed> AssetServiceConnectionImpl::UpdateFeed(
    google::cloud::asset::v1::UpdateFeedRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateFeed(request),
      [this](grpc::ClientContext& context,
             google::cloud::asset::v1::UpdateFeedRequest const& request) {
        return stub_->UpdateFeed(context, request);
      },
      request, __func__);
}

Status AssetServiceConnectionImpl::DeleteFeed(
    google::cloud::asset::v1::DeleteFeedRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteFeed(request),
      [this](grpc::ClientContext& context,
             google::cloud::asset::v1::DeleteFeedRequest const& request) {
        return stub_->DeleteFeed(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::asset::v1::ResourceSearchResult>
AssetServiceConnectionImpl::SearchAllResources(
    google::cloud::asset::v1::SearchAllResourcesRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry =
      std::shared_ptr<asset::AssetServiceRetryPolicy const>(retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->SearchAllResources(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::asset::v1::ResourceSearchResult>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::asset::v1::SearchAllResourcesRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::asset::v1::SearchAllResourcesRequest const&
                       request) {
              return stub->SearchAllResources(context, request);
            },
            r, function_name);
      },
      [](google::cloud::asset::v1::SearchAllResourcesResponse r) {
        std::vector<google::cloud::asset::v1::ResourceSearchResult> result(
            r.results().size());
        auto& messages = *r.mutable_results();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StreamRange<google::cloud::asset::v1::IamPolicySearchResult>
AssetServiceConnectionImpl::SearchAllIamPolicies(
    google::cloud::asset::v1::SearchAllIamPoliciesRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry =
      std::shared_ptr<asset::AssetServiceRetryPolicy const>(retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->SearchAllIamPolicies(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::asset::v1::IamPolicySearchResult>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::asset::v1::SearchAllIamPoliciesRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::asset::v1::SearchAllIamPoliciesRequest const&
                       request) {
              return stub->SearchAllIamPolicies(context, request);
            },
            r, function_name);
      },
      [](google::cloud::asset::v1::SearchAllIamPoliciesResponse r) {
        std::vector<google::cloud::asset::v1::IamPolicySearchResult> result(
            r.results().size());
        auto& messages = *r.mutable_results();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::asset::v1::AnalyzeIamPolicyResponse>
AssetServiceConnectionImpl::AnalyzeIamPolicy(
    google::cloud::asset::v1::AnalyzeIamPolicyRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->AnalyzeIamPolicy(request),
      [this](grpc::ClientContext& context,
             google::cloud::asset::v1::AnalyzeIamPolicyRequest const& request) {
        return stub_->AnalyzeIamPolicy(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::asset::v1::AnalyzeIamPolicyLongrunningResponse>>
AssetServiceConnectionImpl::AnalyzeIamPolicyLongrunning(
    google::cloud::asset::v1::AnalyzeIamPolicyLongrunningRequest const&
        request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::asset::v1::AnalyzeIamPolicyLongrunningResponse>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::asset::v1::AnalyzeIamPolicyLongrunningRequest const&
                 request) {
        return stub->AsyncAnalyzeIamPolicyLongrunning(cq, std::move(context),
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
          google::cloud::asset::v1::AnalyzeIamPolicyLongrunningResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->AnalyzeIamPolicyLongrunning(request),
      polling_policy(), __func__);
}

StatusOr<google::cloud::asset::v1::AnalyzeMoveResponse>
AssetServiceConnectionImpl::AnalyzeMove(
    google::cloud::asset::v1::AnalyzeMoveRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->AnalyzeMove(request),
      [this](grpc::ClientContext& context,
             google::cloud::asset::v1::AnalyzeMoveRequest const& request) {
        return stub_->AnalyzeMove(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace asset_internal
}  // namespace cloud
}  // namespace google
