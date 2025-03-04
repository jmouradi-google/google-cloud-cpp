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
// source: google/cloud/managedidentities/v1/managed_identities_service.proto

#include "google/cloud/managedidentities/managed_identities_client.h"
#include "google/cloud/managedidentities/internal/managed_identities_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace managedidentities {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ManagedIdentitiesServiceClient::ManagedIdentitiesServiceClient(
    std::shared_ptr<ManagedIdentitiesServiceConnection> connection,
    Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options),
          managedidentities_internal::ManagedIdentitiesServiceDefaultOptions(
              connection_->options()))) {}
ManagedIdentitiesServiceClient::~ManagedIdentitiesServiceClient() = default;

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::CreateMicrosoftAdDomain(
    std::string const& parent, std::string const& domain_name,
    google::cloud::managedidentities::v1::Domain const& domain,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::managedidentities::v1::CreateMicrosoftAdDomainRequest request;
  request.set_parent(parent);
  request.set_domain_name(domain_name);
  *request.mutable_domain() = domain;
  return connection_->CreateMicrosoftAdDomain(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::CreateMicrosoftAdDomain(
    google::cloud::managedidentities::v1::CreateMicrosoftAdDomainRequest const&
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateMicrosoftAdDomain(request);
}

StatusOr<google::cloud::managedidentities::v1::ResetAdminPasswordResponse>
ManagedIdentitiesServiceClient::ResetAdminPassword(std::string const& name,
                                                   Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::managedidentities::v1::ResetAdminPasswordRequest request;
  request.set_name(name);
  return connection_->ResetAdminPassword(request);
}

StatusOr<google::cloud::managedidentities::v1::ResetAdminPasswordResponse>
ManagedIdentitiesServiceClient::ResetAdminPassword(
    google::cloud::managedidentities::v1::ResetAdminPasswordRequest const&
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ResetAdminPassword(request);
}

StreamRange<google::cloud::managedidentities::v1::Domain>
ManagedIdentitiesServiceClient::ListDomains(std::string const& parent,
                                            Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::managedidentities::v1::ListDomainsRequest request;
  request.set_parent(parent);
  return connection_->ListDomains(request);
}

StreamRange<google::cloud::managedidentities::v1::Domain>
ManagedIdentitiesServiceClient::ListDomains(
    google::cloud::managedidentities::v1::ListDomainsRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListDomains(std::move(request));
}

StatusOr<google::cloud::managedidentities::v1::Domain>
ManagedIdentitiesServiceClient::GetDomain(std::string const& name,
                                          Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::managedidentities::v1::GetDomainRequest request;
  request.set_name(name);
  return connection_->GetDomain(request);
}

StatusOr<google::cloud::managedidentities::v1::Domain>
ManagedIdentitiesServiceClient::GetDomain(
    google::cloud::managedidentities::v1::GetDomainRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetDomain(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::UpdateDomain(
    google::cloud::managedidentities::v1::Domain const& domain,
    google::protobuf::FieldMask const& update_mask, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::managedidentities::v1::UpdateDomainRequest request;
  *request.mutable_domain() = domain;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateDomain(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::UpdateDomain(
    google::cloud::managedidentities::v1::UpdateDomainRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateDomain(request);
}

future<StatusOr<google::cloud::managedidentities::v1::OpMetadata>>
ManagedIdentitiesServiceClient::DeleteDomain(std::string const& name,
                                             Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::managedidentities::v1::DeleteDomainRequest request;
  request.set_name(name);
  return connection_->DeleteDomain(request);
}

future<StatusOr<google::cloud::managedidentities::v1::OpMetadata>>
ManagedIdentitiesServiceClient::DeleteDomain(
    google::cloud::managedidentities::v1::DeleteDomainRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DeleteDomain(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::AttachTrust(
    std::string const& name,
    google::cloud::managedidentities::v1::Trust const& trust, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::managedidentities::v1::AttachTrustRequest request;
  request.set_name(name);
  *request.mutable_trust() = trust;
  return connection_->AttachTrust(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::AttachTrust(
    google::cloud::managedidentities::v1::AttachTrustRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->AttachTrust(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::ReconfigureTrust(
    std::string const& name, std::string const& target_domain_name,
    std::vector<std::string> const& target_dns_ip_addresses, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::managedidentities::v1::ReconfigureTrustRequest request;
  request.set_name(name);
  request.set_target_domain_name(target_domain_name);
  *request.mutable_target_dns_ip_addresses() = {target_dns_ip_addresses.begin(),
                                                target_dns_ip_addresses.end()};
  return connection_->ReconfigureTrust(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::ReconfigureTrust(
    google::cloud::managedidentities::v1::ReconfigureTrustRequest const&
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ReconfigureTrust(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::DetachTrust(
    std::string const& name,
    google::cloud::managedidentities::v1::Trust const& trust, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::managedidentities::v1::DetachTrustRequest request;
  request.set_name(name);
  *request.mutable_trust() = trust;
  return connection_->DetachTrust(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::DetachTrust(
    google::cloud::managedidentities::v1::DetachTrustRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DetachTrust(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::ValidateTrust(
    std::string const& name,
    google::cloud::managedidentities::v1::Trust const& trust, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::managedidentities::v1::ValidateTrustRequest request;
  request.set_name(name);
  *request.mutable_trust() = trust;
  return connection_->ValidateTrust(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceClient::ValidateTrust(
    google::cloud::managedidentities::v1::ValidateTrustRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ValidateTrust(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace managedidentities
}  // namespace cloud
}  // namespace google
