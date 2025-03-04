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
// source: google/cloud/billing/v1/cloud_billing.proto

#include "google/cloud/billing/cloud_billing_client.h"
#include "google/cloud/billing/cloud_billing_options.h"
#include "google/cloud/billing/internal/cloud_billing_option_defaults.h"
#include <memory>
#include <thread>

namespace google {
namespace cloud {
namespace billing {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudBillingClient::CloudBillingClient(
    std::shared_ptr<CloudBillingConnection> connection, Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options), billing_internal::CloudBillingDefaultOptions(
                                  connection_->options()))) {}
CloudBillingClient::~CloudBillingClient() = default;

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingClient::GetBillingAccount(std::string const& name,
                                      Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::billing::v1::GetBillingAccountRequest request;
  request.set_name(name);
  return connection_->GetBillingAccount(request);
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingClient::GetBillingAccount(
    google::cloud::billing::v1::GetBillingAccountRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetBillingAccount(request);
}

StreamRange<google::cloud::billing::v1::BillingAccount>
CloudBillingClient::ListBillingAccounts(Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::billing::v1::ListBillingAccountsRequest request;
  return connection_->ListBillingAccounts(request);
}

StreamRange<google::cloud::billing::v1::BillingAccount>
CloudBillingClient::ListBillingAccounts(
    google::cloud::billing::v1::ListBillingAccountsRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListBillingAccounts(std::move(request));
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingClient::UpdateBillingAccount(
    std::string const& name,
    google::cloud::billing::v1::BillingAccount const& account,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::billing::v1::UpdateBillingAccountRequest request;
  request.set_name(name);
  *request.mutable_account() = account;
  return connection_->UpdateBillingAccount(request);
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingClient::UpdateBillingAccount(
    google::cloud::billing::v1::UpdateBillingAccountRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateBillingAccount(request);
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingClient::CreateBillingAccount(
    google::cloud::billing::v1::BillingAccount const& billing_account,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::billing::v1::CreateBillingAccountRequest request;
  *request.mutable_billing_account() = billing_account;
  return connection_->CreateBillingAccount(request);
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingClient::CreateBillingAccount(
    google::cloud::billing::v1::CreateBillingAccountRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateBillingAccount(request);
}

StreamRange<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingClient::ListProjectBillingInfo(std::string const& name,
                                           Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::billing::v1::ListProjectBillingInfoRequest request;
  request.set_name(name);
  return connection_->ListProjectBillingInfo(request);
}

StreamRange<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingClient::ListProjectBillingInfo(
    google::cloud::billing::v1::ListProjectBillingInfoRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListProjectBillingInfo(std::move(request));
}

StatusOr<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingClient::GetProjectBillingInfo(std::string const& name,
                                          Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::billing::v1::GetProjectBillingInfoRequest request;
  request.set_name(name);
  return connection_->GetProjectBillingInfo(request);
}

StatusOr<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingClient::GetProjectBillingInfo(
    google::cloud::billing::v1::GetProjectBillingInfoRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetProjectBillingInfo(request);
}

StatusOr<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingClient::UpdateProjectBillingInfo(
    std::string const& name,
    google::cloud::billing::v1::ProjectBillingInfo const& project_billing_info,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::billing::v1::UpdateProjectBillingInfoRequest request;
  request.set_name(name);
  *request.mutable_project_billing_info() = project_billing_info;
  return connection_->UpdateProjectBillingInfo(request);
}

StatusOr<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingClient::UpdateProjectBillingInfo(
    google::cloud::billing::v1::UpdateProjectBillingInfoRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateProjectBillingInfo(request);
}

StatusOr<google::iam::v1::Policy> CloudBillingClient::GetIamPolicy(
    std::string const& resource, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::iam::v1::GetIamPolicyRequest request;
  request.set_resource(resource);
  return connection_->GetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy> CloudBillingClient::GetIamPolicy(
    google::iam::v1::GetIamPolicyRequest const& request, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy> CloudBillingClient::SetIamPolicy(
    std::string const& resource, google::iam::v1::Policy const& policy,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::iam::v1::SetIamPolicyRequest request;
  request.set_resource(resource);
  *request.mutable_policy() = policy;
  return connection_->SetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy> CloudBillingClient::SetIamPolicy(
    std::string const& resource, IamUpdater const& updater, Options options) {
  internal::CheckExpectedOptions<CloudBillingBackoffPolicyOption>(options,
                                                                  __func__);
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::iam::v1::GetIamPolicyRequest get_request;
  get_request.set_resource(resource);
  google::iam::v1::SetIamPolicyRequest set_request;
  set_request.set_resource(resource);
  auto backoff_policy = internal::CurrentOptions()
                            .get<CloudBillingBackoffPolicyOption>()
                            ->clone();
  for (;;) {
    auto recent = connection_->GetIamPolicy(get_request);
    if (!recent) {
      return recent.status();
    }
    auto policy = updater(*std::move(recent));
    if (!policy) {
      return Status(StatusCode::kCancelled, "updater did not yield a policy");
    }
    *set_request.mutable_policy() = *std::move(policy);
    auto result = connection_->SetIamPolicy(set_request);
    if (result || result.status().code() != StatusCode::kAborted) {
      return result;
    }
    std::this_thread::sleep_for(backoff_policy->OnCompletion());
  }
}

StatusOr<google::iam::v1::Policy> CloudBillingClient::SetIamPolicy(
    google::iam::v1::SetIamPolicyRequest const& request, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->SetIamPolicy(request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
CloudBillingClient::TestIamPermissions(
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
CloudBillingClient::TestIamPermissions(
    google::iam::v1::TestIamPermissionsRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->TestIamPermissions(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace billing
}  // namespace cloud
}  // namespace google
