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
// source: google/cloud/memcache/v1/cloud_memcache.proto

#include "google/cloud/memcache/cloud_memcache_connection.h"
#include "google/cloud/memcache/cloud_memcache_options.h"
#include "google/cloud/memcache/internal/cloud_memcache_connection_impl.h"
#include "google/cloud/memcache/internal/cloud_memcache_option_defaults.h"
#include "google/cloud/memcache/internal/cloud_memcache_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace memcache {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudMemcacheConnection::~CloudMemcacheConnection() = default;

StreamRange<google::cloud::memcache::v1::Instance>
    CloudMemcacheConnection::ListInstances(
        google::cloud::memcache::v1::
            ListInstancesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::memcache::v1::Instance>>();
}

StatusOr<google::cloud::memcache::v1::Instance>
CloudMemcacheConnection::GetInstance(
    google::cloud::memcache::v1::GetInstanceRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::memcache::v1::Instance>>
CloudMemcacheConnection::CreateInstance(
    google::cloud::memcache::v1::CreateInstanceRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::memcache::v1::Instance>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::memcache::v1::Instance>>
CloudMemcacheConnection::UpdateInstance(
    google::cloud::memcache::v1::UpdateInstanceRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::memcache::v1::Instance>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::memcache::v1::Instance>>
CloudMemcacheConnection::UpdateParameters(
    google::cloud::memcache::v1::UpdateParametersRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::memcache::v1::Instance>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::memcache::v1::OperationMetadata>>
CloudMemcacheConnection::DeleteInstance(
    google::cloud::memcache::v1::DeleteInstanceRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::memcache::v1::OperationMetadata>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::memcache::v1::Instance>>
CloudMemcacheConnection::ApplyParameters(
    google::cloud::memcache::v1::ApplyParametersRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::memcache::v1::Instance>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

std::shared_ptr<CloudMemcacheConnection> MakeCloudMemcacheConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 CloudMemcachePolicyOptionList>(options,
                                                                __func__);
  options = memcache_internal::CloudMemcacheDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = memcache_internal::CreateDefaultCloudMemcacheStub(
      background->cq(), options);
  return std::make_shared<memcache_internal::CloudMemcacheConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace memcache
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace memcache_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<memcache::CloudMemcacheConnection> MakeCloudMemcacheConnection(
    std::shared_ptr<CloudMemcacheStub> stub, Options options) {
  options = CloudMemcacheDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<memcache_internal::CloudMemcacheConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace memcache_internal
}  // namespace cloud
}  // namespace google
