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
// source: google/cloud/tpu/v1/cloud_tpu.proto

#include "google/cloud/tpu/tpu_connection.h"
#include "google/cloud/tpu/internal/tpu_connection_impl.h"
#include "google/cloud/tpu/internal/tpu_option_defaults.h"
#include "google/cloud/tpu/internal/tpu_stub_factory.h"
#include "google/cloud/tpu/tpu_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace tpu {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TpuConnection::~TpuConnection() = default;

StreamRange<google::cloud::tpu::v1::Node> TpuConnection::ListNodes(
    google::cloud::tpu::v1::
        ListNodesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::tpu::v1::Node>>();
}

StatusOr<google::cloud::tpu::v1::Node> TpuConnection::GetNode(
    google::cloud::tpu::v1::GetNodeRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::tpu::v1::Node>> TpuConnection::CreateNode(
    google::cloud::tpu::v1::CreateNodeRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::tpu::v1::Node>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::tpu::v1::Node>> TpuConnection::DeleteNode(
    google::cloud::tpu::v1::DeleteNodeRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::tpu::v1::Node>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::tpu::v1::Node>> TpuConnection::ReimageNode(
    google::cloud::tpu::v1::ReimageNodeRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::tpu::v1::Node>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::tpu::v1::Node>> TpuConnection::StopNode(
    google::cloud::tpu::v1::StopNodeRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::tpu::v1::Node>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::tpu::v1::Node>> TpuConnection::StartNode(
    google::cloud::tpu::v1::StartNodeRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::tpu::v1::Node>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StreamRange<google::cloud::tpu::v1::TensorFlowVersion>
    TpuConnection::ListTensorFlowVersions(
        google::cloud::tpu::v1::
            ListTensorFlowVersionsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::tpu::v1::TensorFlowVersion>>();
}

StatusOr<google::cloud::tpu::v1::TensorFlowVersion>
TpuConnection::GetTensorFlowVersion(
    google::cloud::tpu::v1::GetTensorFlowVersionRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::tpu::v1::AcceleratorType>
    TpuConnection::ListAcceleratorTypes(
        google::cloud::tpu::v1::
            ListAcceleratorTypesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::tpu::v1::AcceleratorType>>();
}

StatusOr<google::cloud::tpu::v1::AcceleratorType>
TpuConnection::GetAcceleratorType(
    google::cloud::tpu::v1::GetAcceleratorTypeRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<TpuConnection> MakeTpuConnection(Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 TpuPolicyOptionList>(options, __func__);
  options = tpu_internal::TpuDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = tpu_internal::CreateDefaultTpuStub(background->cq(), options);
  return std::make_shared<tpu_internal::TpuConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace tpu
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace tpu_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<tpu::TpuConnection> MakeTpuConnection(
    std::shared_ptr<TpuStub> stub, Options options) {
  options = TpuDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<tpu_internal::TpuConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace tpu_internal
}  // namespace cloud
}  // namespace google
