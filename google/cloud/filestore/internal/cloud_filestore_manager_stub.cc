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
// source: google/cloud/filestore/v1/cloud_filestore_service.proto

#include "google/cloud/filestore/internal/cloud_filestore_manager_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/cloud/filestore/v1/cloud_filestore_service.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace filestore_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudFilestoreManagerStub::~CloudFilestoreManagerStub() = default;

StatusOr<google::cloud::filestore::v1::ListInstancesResponse>
DefaultCloudFilestoreManagerStub::ListInstances(
    grpc::ClientContext& client_context,
    google::cloud::filestore::v1::ListInstancesRequest const& request) {
  google::cloud::filestore::v1::ListInstancesResponse response;
  auto status = grpc_stub_->ListInstances(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::filestore::v1::Instance>
DefaultCloudFilestoreManagerStub::GetInstance(
    grpc::ClientContext& client_context,
    google::cloud::filestore::v1::GetInstanceRequest const& request) {
  google::cloud::filestore::v1::Instance response;
  auto status = grpc_stub_->GetInstance(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudFilestoreManagerStub::AsyncCreateInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::CreateInstanceRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::filestore::v1::CreateInstanceRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateInstance(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudFilestoreManagerStub::AsyncUpdateInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::UpdateInstanceRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::filestore::v1::UpdateInstanceRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncUpdateInstance(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudFilestoreManagerStub::AsyncRestoreInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::RestoreInstanceRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](
          grpc::ClientContext* context,
          google::cloud::filestore::v1::RestoreInstanceRequest const& request,
          grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncRestoreInstance(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudFilestoreManagerStub::AsyncDeleteInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::DeleteInstanceRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::filestore::v1::DeleteInstanceRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncDeleteInstance(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::cloud::filestore::v1::ListBackupsResponse>
DefaultCloudFilestoreManagerStub::ListBackups(
    grpc::ClientContext& client_context,
    google::cloud::filestore::v1::ListBackupsRequest const& request) {
  google::cloud::filestore::v1::ListBackupsResponse response;
  auto status = grpc_stub_->ListBackups(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::filestore::v1::Backup>
DefaultCloudFilestoreManagerStub::GetBackup(
    grpc::ClientContext& client_context,
    google::cloud::filestore::v1::GetBackupRequest const& request) {
  google::cloud::filestore::v1::Backup response;
  auto status = grpc_stub_->GetBackup(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudFilestoreManagerStub::AsyncCreateBackup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::CreateBackupRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::filestore::v1::CreateBackupRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateBackup(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudFilestoreManagerStub::AsyncDeleteBackup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::DeleteBackupRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::filestore::v1::DeleteBackupRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncDeleteBackup(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudFilestoreManagerStub::AsyncUpdateBackup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::UpdateBackupRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::filestore::v1::UpdateBackupRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncUpdateBackup(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudFilestoreManagerStub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::longrunning::GetOperationRequest const& request,
             grpc::CompletionQueue* cq) {
        return operations_->AsyncGetOperation(context, request, cq);
      },
      request, std::move(context));
}

future<Status> DefaultCloudFilestoreManagerStub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return cq
      .MakeUnaryRpc(
          [this](grpc::ClientContext* context,
                 google::longrunning::CancelOperationRequest const& request,
                 grpc::CompletionQueue* cq) {
            return operations_->AsyncCancelOperation(context, request, cq);
          },
          request, std::move(context))
      .then([](future<StatusOr<google::protobuf::Empty>> f) {
        return f.get().status();
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace filestore_internal
}  // namespace cloud
}  // namespace google
