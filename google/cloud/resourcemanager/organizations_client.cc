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
// source: google/cloud/resourcemanager/v3/organizations.proto

#include "google/cloud/resourcemanager/organizations_client.h"
#include "google/cloud/resourcemanager/internal/organizations_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace resourcemanager {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

OrganizationsClient::OrganizationsClient(
    std::shared_ptr<OrganizationsConnection> connection, Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options),
          resourcemanager_internal::OrganizationsDefaultOptions(
              connection_->options()))) {}
OrganizationsClient::~OrganizationsClient() = default;

StatusOr<google::cloud::resourcemanager::v3::Organization>
OrganizationsClient::GetOrganization(std::string const& name, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::resourcemanager::v3::GetOrganizationRequest request;
  request.set_name(name);
  return connection_->GetOrganization(request);
}

StatusOr<google::cloud::resourcemanager::v3::Organization>
OrganizationsClient::GetOrganization(
    google::cloud::resourcemanager::v3::GetOrganizationRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetOrganization(request);
}

StreamRange<google::cloud::resourcemanager::v3::Organization>
OrganizationsClient::SearchOrganizations(std::string const& query,
                                         Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::resourcemanager::v3::SearchOrganizationsRequest request;
  request.set_query(query);
  return connection_->SearchOrganizations(request);
}

StreamRange<google::cloud::resourcemanager::v3::Organization>
OrganizationsClient::SearchOrganizations(
    google::cloud::resourcemanager::v3::SearchOrganizationsRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->SearchOrganizations(std::move(request));
}

StatusOr<google::iam::v1::Policy> OrganizationsClient::GetIamPolicy(
    std::string const& resource, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::iam::v1::GetIamPolicyRequest request;
  request.set_resource(resource);
  return connection_->GetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy> OrganizationsClient::GetIamPolicy(
    google::iam::v1::GetIamPolicyRequest const& request, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy> OrganizationsClient::SetIamPolicy(
    std::string const& resource, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::iam::v1::SetIamPolicyRequest request;
  request.set_resource(resource);
  return connection_->SetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy> OrganizationsClient::SetIamPolicy(
    google::iam::v1::SetIamPolicyRequest const& request, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->SetIamPolicy(request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
OrganizationsClient::TestIamPermissions(
    std::string const& resource, std::vector<std::string> const& permissions,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::iam::v1::TestIamPermissionsRequest request;
  request.set_resource(resource);
  *request.mutable_permissions() = {permissions.begin(), permissions.end()};
  return connection_->TestIamPermissions(request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
OrganizationsClient::TestIamPermissions(
    google::iam::v1::TestIamPermissionsRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->TestIamPermissions(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace resourcemanager
}  // namespace cloud
}  // namespace google
