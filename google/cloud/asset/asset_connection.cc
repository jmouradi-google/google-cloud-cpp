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

#include "google/cloud/asset/asset_connection.h"
#include "google/cloud/asset/asset_options.h"
#include "google/cloud/asset/internal/asset_connection_impl.h"
#include "google/cloud/asset/internal/asset_option_defaults.h"
#include "google/cloud/asset/internal/asset_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace asset {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

AssetServiceConnection::~AssetServiceConnection() = default;

future<StatusOr<google::cloud::asset::v1::ExportAssetsResponse>>
AssetServiceConnection::ExportAssets(
    google::cloud::asset::v1::ExportAssetsRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::asset::v1::ExportAssetsResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StreamRange<google::cloud::asset::v1::Asset> AssetServiceConnection::ListAssets(
    google::cloud::asset::v1::
        ListAssetsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::asset::v1::Asset>>();
}

StatusOr<google::cloud::asset::v1::BatchGetAssetsHistoryResponse>
AssetServiceConnection::BatchGetAssetsHistory(
    google::cloud::asset::v1::BatchGetAssetsHistoryRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::asset::v1::Feed> AssetServiceConnection::CreateFeed(
    google::cloud::asset::v1::CreateFeedRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::asset::v1::Feed> AssetServiceConnection::GetFeed(
    google::cloud::asset::v1::GetFeedRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::asset::v1::ListFeedsResponse>
AssetServiceConnection::ListFeeds(
    google::cloud::asset::v1::ListFeedsRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::asset::v1::Feed> AssetServiceConnection::UpdateFeed(
    google::cloud::asset::v1::UpdateFeedRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status AssetServiceConnection::DeleteFeed(
    google::cloud::asset::v1::DeleteFeedRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::asset::v1::ResourceSearchResult>
    AssetServiceConnection::SearchAllResources(
        google::cloud::asset::v1::
            SearchAllResourcesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::asset::v1::ResourceSearchResult>>();
}

StreamRange<google::cloud::asset::v1::IamPolicySearchResult>
    AssetServiceConnection::SearchAllIamPolicies(
        google::cloud::asset::v1::
            SearchAllIamPoliciesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::asset::v1::IamPolicySearchResult>>();
}

StatusOr<google::cloud::asset::v1::AnalyzeIamPolicyResponse>
AssetServiceConnection::AnalyzeIamPolicy(
    google::cloud::asset::v1::AnalyzeIamPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::asset::v1::AnalyzeIamPolicyLongrunningResponse>>
AssetServiceConnection::AnalyzeIamPolicyLongrunning(
    google::cloud::asset::v1::AnalyzeIamPolicyLongrunningRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::asset::v1::AnalyzeIamPolicyLongrunningResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::cloud::asset::v1::AnalyzeMoveResponse>
AssetServiceConnection::AnalyzeMove(
    google::cloud::asset::v1::AnalyzeMoveRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<AssetServiceConnection> MakeAssetServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 AssetServicePolicyOptionList>(options,
                                                               __func__);
  options = asset_internal::AssetServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub =
      asset_internal::CreateDefaultAssetServiceStub(background->cq(), options);
  return std::make_shared<asset_internal::AssetServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace asset
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace asset_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<asset::AssetServiceConnection> MakeAssetServiceConnection(
    std::shared_ptr<AssetServiceStub> stub, Options options) {
  options = AssetServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<asset_internal::AssetServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace asset_internal
}  // namespace cloud
}  // namespace google
