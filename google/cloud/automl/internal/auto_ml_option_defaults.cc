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
// source: google/cloud/automl/v1/service.proto

#include "google/cloud/automl/internal/auto_ml_option_defaults.h"
#include "google/cloud/automl/auto_ml_connection.h"
#include "google/cloud/automl/auto_ml_options.h"
#include "google/cloud/common_options.h"
#include "google/cloud/connection_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/getenv.h"
#include "google/cloud/internal/user_agent_prefix.h"
#include "google/cloud/options.h"
#include <memory>

namespace google {
namespace cloud {
namespace automl_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options AutoMlDefaultOptions(Options options) {
  if (!options.has<EndpointOption>()) {
    auto env = internal::GetEnv("GOOGLE_CLOUD_CPP_AUTO_ML_ENDPOINT");
    options.set<EndpointOption>(env && !env->empty() ? *env
                                                     : "automl.googleapis.com");
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

  if (!options.has<automl::AutoMlRetryPolicyOption>()) {
    options.set<automl::AutoMlRetryPolicyOption>(
        automl::AutoMlLimitedTimeRetryPolicy(std::chrono::minutes(30)).clone());
  }
  if (!options.has<automl::AutoMlBackoffPolicyOption>()) {
    options.set<automl::AutoMlBackoffPolicyOption>(
        ExponentialBackoffPolicy(std::chrono::seconds(1),
                                 std::chrono::minutes(5), kBackoffScaling)
            .clone());
  }
  if (!options.has<automl::AutoMlPollingPolicyOption>()) {
    options.set<automl::AutoMlPollingPolicyOption>(
        GenericPollingPolicy<automl::AutoMlRetryPolicyOption::Type,
                             automl::AutoMlBackoffPolicyOption::Type>(
            options.get<automl::AutoMlRetryPolicyOption>()->clone(),
            options.get<automl::AutoMlBackoffPolicyOption>()->clone())
            .clone());
  }
  if (!options.has<automl::AutoMlConnectionIdempotencyPolicyOption>()) {
    options.set<automl::AutoMlConnectionIdempotencyPolicyOption>(
        automl::MakeDefaultAutoMlConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace automl_internal
}  // namespace cloud
}  // namespace google
