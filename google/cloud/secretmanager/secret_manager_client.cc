// Copyright 2021 Google LLC
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
// source: google/cloud/secretmanager/v1/service.proto

#include "google/cloud/secretmanager/secret_manager_client.h"
#include "google/cloud/secretmanager/internal/secret_manager_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace secretmanager {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SecretManagerServiceClient::SecretManagerServiceClient(
    std::shared_ptr<SecretManagerServiceConnection> connection, Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options),
          secretmanager_internal::SecretManagerServiceDefaultOptions(
              connection_->options()))) {}
SecretManagerServiceClient::~SecretManagerServiceClient() = default;

StreamRange<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceClient::ListSecrets(std::string const& parent,
                                        Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::ListSecretsRequest request;
  request.set_parent(parent);
  return connection_->ListSecrets(request);
}

StreamRange<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceClient::ListSecrets(
    google::cloud::secretmanager::v1::ListSecretsRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListSecrets(std::move(request));
}

StatusOr<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceClient::CreateSecret(
    std::string const& parent, std::string const& secret_id,
    google::cloud::secretmanager::v1::Secret const& secret, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::CreateSecretRequest request;
  request.set_parent(parent);
  request.set_secret_id(secret_id);
  *request.mutable_secret() = secret;
  return connection_->CreateSecret(request);
}

StatusOr<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceClient::CreateSecret(
    google::cloud::secretmanager::v1::CreateSecretRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateSecret(request);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::AddSecretVersion(
    std::string const& parent,
    google::cloud::secretmanager::v1::SecretPayload const& payload,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::AddSecretVersionRequest request;
  request.set_parent(parent);
  *request.mutable_payload() = payload;
  return connection_->AddSecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::AddSecretVersion(
    google::cloud::secretmanager::v1::AddSecretVersionRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->AddSecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceClient::GetSecret(std::string const& name,
                                      Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::GetSecretRequest request;
  request.set_name(name);
  return connection_->GetSecret(request);
}

StatusOr<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceClient::GetSecret(
    google::cloud::secretmanager::v1::GetSecretRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetSecret(request);
}

StatusOr<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceClient::UpdateSecret(
    google::cloud::secretmanager::v1::Secret const& secret,
    google::protobuf::FieldMask const& update_mask, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::UpdateSecretRequest request;
  *request.mutable_secret() = secret;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateSecret(request);
}

StatusOr<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceClient::UpdateSecret(
    google::cloud::secretmanager::v1::UpdateSecretRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateSecret(request);
}

Status SecretManagerServiceClient::DeleteSecret(std::string const& name,
                                                Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::DeleteSecretRequest request;
  request.set_name(name);
  return connection_->DeleteSecret(request);
}

Status SecretManagerServiceClient::DeleteSecret(
    google::cloud::secretmanager::v1::DeleteSecretRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DeleteSecret(request);
}

StreamRange<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::ListSecretVersions(std::string const& parent,
                                               Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::ListSecretVersionsRequest request;
  request.set_parent(parent);
  return connection_->ListSecretVersions(request);
}

StreamRange<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::ListSecretVersions(
    google::cloud::secretmanager::v1::ListSecretVersionsRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListSecretVersions(std::move(request));
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::GetSecretVersion(std::string const& name,
                                             Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::GetSecretVersionRequest request;
  request.set_name(name);
  return connection_->GetSecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::GetSecretVersion(
    google::cloud::secretmanager::v1::GetSecretVersionRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetSecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::AccessSecretVersionResponse>
SecretManagerServiceClient::AccessSecretVersion(std::string const& name,
                                                Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::AccessSecretVersionRequest request;
  request.set_name(name);
  return connection_->AccessSecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::AccessSecretVersionResponse>
SecretManagerServiceClient::AccessSecretVersion(
    google::cloud::secretmanager::v1::AccessSecretVersionRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->AccessSecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::DisableSecretVersion(std::string const& name,
                                                 Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::DisableSecretVersionRequest request;
  request.set_name(name);
  return connection_->DisableSecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::DisableSecretVersion(
    google::cloud::secretmanager::v1::DisableSecretVersionRequest const&
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DisableSecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::EnableSecretVersion(std::string const& name,
                                                Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::EnableSecretVersionRequest request;
  request.set_name(name);
  return connection_->EnableSecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::EnableSecretVersion(
    google::cloud::secretmanager::v1::EnableSecretVersionRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->EnableSecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::DestroySecretVersion(std::string const& name,
                                                 Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::secretmanager::v1::DestroySecretVersionRequest request;
  request.set_name(name);
  return connection_->DestroySecretVersion(request);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceClient::DestroySecretVersion(
    google::cloud::secretmanager::v1::DestroySecretVersionRequest const&
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DestroySecretVersion(request);
}

StatusOr<google::iam::v1::Policy> SecretManagerServiceClient::SetIamPolicy(
    google::iam::v1::SetIamPolicyRequest const& request, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->SetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy> SecretManagerServiceClient::GetIamPolicy(
    google::iam::v1::GetIamPolicyRequest const& request, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetIamPolicy(request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
SecretManagerServiceClient::TestIamPermissions(
    google::iam::v1::TestIamPermissionsRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->TestIamPermissions(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace secretmanager
}  // namespace cloud
}  // namespace google
