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
// source: google/cloud/retail/v2/product_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_INTERNAL_PRODUCT_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_INTERNAL_PRODUCT_CONNECTION_IMPL_H

#include "google/cloud/retail/internal/product_retry_traits.h"
#include "google/cloud/retail/internal/product_stub.h"
#include "google/cloud/retail/product_connection.h"
#include "google/cloud/retail/product_connection_idempotency_policy.h"
#include "google/cloud/retail/product_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace retail_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ProductServiceConnectionImpl : public retail::ProductServiceConnection {
 public:
  ~ProductServiceConnectionImpl() override = default;

  ProductServiceConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<retail_internal::ProductServiceStub> stub,
      Options options);

  Options options() override { return options_; }

  StatusOr<google::cloud::retail::v2::Product> CreateProduct(
      google::cloud::retail::v2::CreateProductRequest const& request) override;

  StatusOr<google::cloud::retail::v2::Product> GetProduct(
      google::cloud::retail::v2::GetProductRequest const& request) override;

  StreamRange<google::cloud::retail::v2::Product> ListProducts(
      google::cloud::retail::v2::ListProductsRequest request) override;

  StatusOr<google::cloud::retail::v2::Product> UpdateProduct(
      google::cloud::retail::v2::UpdateProductRequest const& request) override;

  Status DeleteProduct(
      google::cloud::retail::v2::DeleteProductRequest const& request) override;

  future<StatusOr<google::cloud::retail::v2::ImportProductsResponse>>
  ImportProducts(
      google::cloud::retail::v2::ImportProductsRequest const& request) override;

  future<StatusOr<google::cloud::retail::v2::SetInventoryResponse>>
  SetInventory(
      google::cloud::retail::v2::SetInventoryRequest const& request) override;

  future<StatusOr<google::cloud::retail::v2::AddFulfillmentPlacesResponse>>
  AddFulfillmentPlaces(
      google::cloud::retail::v2::AddFulfillmentPlacesRequest const& request)
      override;

  future<StatusOr<google::cloud::retail::v2::RemoveFulfillmentPlacesResponse>>
  RemoveFulfillmentPlaces(
      google::cloud::retail::v2::RemoveFulfillmentPlacesRequest const& request)
      override;

 private:
  std::unique_ptr<retail::ProductServiceRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<retail::ProductServiceRetryPolicyOption>()) {
      return options.get<retail::ProductServiceRetryPolicyOption>()->clone();
    }
    return options_.get<retail::ProductServiceRetryPolicyOption>()->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<retail::ProductServiceBackoffPolicyOption>()) {
      return options.get<retail::ProductServiceBackoffPolicyOption>()->clone();
    }
    return options_.get<retail::ProductServiceBackoffPolicyOption>()->clone();
  }

  std::unique_ptr<retail::ProductServiceConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options
            .has<retail::ProductServiceConnectionIdempotencyPolicyOption>()) {
      return options
          .get<retail::ProductServiceConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return options_
        .get<retail::ProductServiceConnectionIdempotencyPolicyOption>()
        ->clone();
  }

  std::unique_ptr<PollingPolicy> polling_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<retail::ProductServicePollingPolicyOption>()) {
      return options.get<retail::ProductServicePollingPolicyOption>()->clone();
    }
    return options_.get<retail::ProductServicePollingPolicyOption>()->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<retail_internal::ProductServiceStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace retail_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_INTERNAL_PRODUCT_CONNECTION_IMPL_H
