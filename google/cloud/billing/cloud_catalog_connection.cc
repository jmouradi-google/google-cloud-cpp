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
// source: google/cloud/billing/v1/cloud_catalog.proto

#include "google/cloud/billing/cloud_catalog_connection.h"
#include "google/cloud/billing/cloud_catalog_options.h"
#include "google/cloud/billing/internal/cloud_catalog_connection_impl.h"
#include "google/cloud/billing/internal/cloud_catalog_option_defaults.h"
#include "google/cloud/billing/internal/cloud_catalog_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace billing {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudCatalogConnection::~CloudCatalogConnection() = default;

StreamRange<google::cloud::billing::v1::Service>
    CloudCatalogConnection::ListServices(
        google::cloud::billing::v1::
            ListServicesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::billing::v1::Service>>();
}

StreamRange<google::cloud::billing::v1::Sku> CloudCatalogConnection::ListSkus(
    google::cloud::billing::v1::
        ListSkusRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::billing::v1::Sku>>();
}

std::shared_ptr<CloudCatalogConnection> MakeCloudCatalogConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 CloudCatalogPolicyOptionList>(options,
                                                               __func__);
  options = billing_internal::CloudCatalogDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = billing_internal::CreateDefaultCloudCatalogStub(background->cq(),
                                                              options);
  return std::make_shared<billing_internal::CloudCatalogConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace billing
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace billing_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<billing::CloudCatalogConnection> MakeCloudCatalogConnection(
    std::shared_ptr<CloudCatalogStub> stub, Options options) {
  options = CloudCatalogDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<billing_internal::CloudCatalogConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace billing_internal
}  // namespace cloud
}  // namespace google
