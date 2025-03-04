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
// source: generator/integration_tests/test.proto

#include "generator/integration_tests/golden/golden_kitchen_sink_connection.h"
#include "generator/integration_tests/golden/golden_kitchen_sink_options.h"
#include "generator/integration_tests/golden/internal/golden_kitchen_sink_connection_impl.h"
#include "generator/integration_tests/golden/internal/golden_kitchen_sink_option_defaults.h"
#include "generator/integration_tests/golden/internal/golden_kitchen_sink_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/resumable_streaming_read_rpc.h"
#include <memory>

namespace google {
namespace cloud {
namespace golden {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

GoldenKitchenSinkConnection::~GoldenKitchenSinkConnection() = default;

StatusOr<google::test::admin::database::v1::GenerateAccessTokenResponse>
GoldenKitchenSinkConnection::GenerateAccessToken(
    google::test::admin::database::v1::GenerateAccessTokenRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::test::admin::database::v1::GenerateIdTokenResponse>
GoldenKitchenSinkConnection::GenerateIdToken(
    google::test::admin::database::v1::GenerateIdTokenRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::test::admin::database::v1::WriteLogEntriesResponse>
GoldenKitchenSinkConnection::WriteLogEntries(
    google::test::admin::database::v1::WriteLogEntriesRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<std::string> GoldenKitchenSinkConnection::ListLogs(
    google::test::admin::database::v1::ListLogsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<std::string>>();
}

StreamRange<google::test::admin::database::v1::TailLogEntriesResponse> GoldenKitchenSinkConnection::TailLogEntries(
    google::test::admin::database::v1::TailLogEntriesRequest const&) {
  return google::cloud::internal::MakeStreamRange<
      google::test::admin::database::v1::TailLogEntriesResponse>(
      []() -> absl::variant<Status,
      google::test::admin::database::v1::TailLogEntriesResponse>{
        return Status(StatusCode::kUnimplemented, "not implemented");}
      );
}

StatusOr<google::test::admin::database::v1::ListServiceAccountKeysResponse>
GoldenKitchenSinkConnection::ListServiceAccountKeys(
    google::test::admin::database::v1::ListServiceAccountKeysRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status
GoldenKitchenSinkConnection::DoNothing(
    google::protobuf::Empty const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::test::admin::database::v1::AppendRowsRequest,
    google::test::admin::database::v1::AppendRowsResponse>>
GoldenKitchenSinkConnection::AsyncAppendRows() {
  return absl::make_unique<
      ::google::cloud::internal::AsyncStreamingReadWriteRpcError<
          google::test::admin::database::v1::AppendRowsRequest,
          google::test::admin::database::v1::AppendRowsResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

std::shared_ptr<GoldenKitchenSinkConnection> MakeGoldenKitchenSinkConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
      GoldenKitchenSinkPolicyOptionList>(options, __func__);
  options = golden_internal::GoldenKitchenSinkDefaultOptions(
      std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = golden_internal::CreateDefaultGoldenKitchenSinkStub(
    background->cq(), options);
  return std::make_shared<golden_internal::GoldenKitchenSinkConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace golden
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace golden_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<golden::GoldenKitchenSinkConnection>
MakeGoldenKitchenSinkConnection(
    std::shared_ptr<GoldenKitchenSinkStub> stub, Options options) {
  options = GoldenKitchenSinkDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<golden_internal::GoldenKitchenSinkConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace golden_internal
}  // namespace cloud
}  // namespace google
