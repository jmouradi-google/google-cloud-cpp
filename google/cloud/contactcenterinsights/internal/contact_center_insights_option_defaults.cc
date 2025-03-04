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
// source: google/cloud/contactcenterinsights/v1/contact_center_insights.proto

#include "google/cloud/contactcenterinsights/internal/contact_center_insights_option_defaults.h"
#include "google/cloud/contactcenterinsights/contact_center_insights_connection.h"
#include "google/cloud/contactcenterinsights/contact_center_insights_options.h"
#include "google/cloud/common_options.h"
#include "google/cloud/connection_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/getenv.h"
#include "google/cloud/internal/user_agent_prefix.h"
#include "google/cloud/options.h"
#include <memory>

namespace google {
namespace cloud {
namespace contactcenterinsights_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options ContactCenterInsightsDefaultOptions(Options options) {
  if (!options.has<EndpointOption>()) {
    auto env =
        internal::GetEnv("GOOGLE_CLOUD_CPP_CONTACT_CENTER_INSIGHTS_ENDPOINT");
    options.set<EndpointOption>(
        env && !env->empty() ? *env : "contactcenterinsights.googleapis.com");
  }
  if (!options.has<GrpcCredentialOption>()) {
    options.set<GrpcCredentialOption>(grpc::GoogleDefaultCredentials());
  }
  if (!options.has<TracingComponentsOption>()) {
    options.set<TracingComponentsOption>(internal::DefaultTracingComponents());
  }
  if (!options.has<GrpcTracingOptionsOption>()) {
    options.set<GrpcTracingOptionsOption>(internal::DefaultTracingOptions());
  }
  auto& products = options.lookup<UserAgentProductsOption>();
  products.insert(products.begin(), google::cloud::internal::UserAgentPrefix());

  if (!options.has<
          contactcenterinsights::ContactCenterInsightsRetryPolicyOption>()) {
    options.set<contactcenterinsights::ContactCenterInsightsRetryPolicyOption>(
        contactcenterinsights::ContactCenterInsightsLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<
          contactcenterinsights::ContactCenterInsightsBackoffPolicyOption>()) {
    options
        .set<contactcenterinsights::ContactCenterInsightsBackoffPolicyOption>(
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone());
  }
  if (!options.has<
          contactcenterinsights::ContactCenterInsightsPollingPolicyOption>()) {
    options.set<
        contactcenterinsights::ContactCenterInsightsPollingPolicyOption>(
        GenericPollingPolicy<
            contactcenterinsights::ContactCenterInsightsRetryPolicyOption::Type,
            contactcenterinsights::ContactCenterInsightsBackoffPolicyOption::
                Type>(options
                          .get<contactcenterinsights::
                                   ContactCenterInsightsRetryPolicyOption>()
                          ->clone(),
                      options
                          .get<contactcenterinsights::
                                   ContactCenterInsightsBackoffPolicyOption>()
                          ->clone())
            .clone());
  }
  if (!options
           .has<contactcenterinsights::
                    ContactCenterInsightsConnectionIdempotencyPolicyOption>()) {
    options.set<contactcenterinsights::
                    ContactCenterInsightsConnectionIdempotencyPolicyOption>(
        contactcenterinsights::
            MakeDefaultContactCenterInsightsConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace contactcenterinsights_internal
}  // namespace cloud
}  // namespace google
