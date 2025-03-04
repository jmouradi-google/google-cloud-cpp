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
// source: google/cloud/datacatalog/v1/datacatalog.proto

#include "google/cloud/datacatalog/internal/data_catalog_connection_impl.h"
#include "google/cloud/datacatalog/internal/data_catalog_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace datacatalog_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DataCatalogConnectionImpl::DataCatalogConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<datacatalog_internal::DataCatalogStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options), datacatalog_internal::DataCatalogDefaultOptions(
                                  DataCatalogConnection::options()))) {}

StreamRange<google::cloud::datacatalog::v1::SearchCatalogResult>
DataCatalogConnectionImpl::SearchCatalog(
    google::cloud::datacatalog::v1::SearchCatalogRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<datacatalog::DataCatalogRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->SearchCatalog(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::datacatalog::v1::SearchCatalogResult>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::datacatalog::v1::SearchCatalogRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::datacatalog::v1::SearchCatalogRequest const&
                       request) {
              return stub->SearchCatalog(context, request);
            },
            r, function_name);
      },
      [](google::cloud::datacatalog::v1::SearchCatalogResponse r) {
        std::vector<google::cloud::datacatalog::v1::SearchCatalogResult> result(
            r.results().size());
        auto& messages = *r.mutable_results();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::datacatalog::v1::EntryGroup>
DataCatalogConnectionImpl::CreateEntryGroup(
    google::cloud::datacatalog::v1::CreateEntryGroupRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateEntryGroup(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::CreateEntryGroupRequest const&
                 request) { return stub_->CreateEntryGroup(context, request); },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::EntryGroup>
DataCatalogConnectionImpl::GetEntryGroup(
    google::cloud::datacatalog::v1::GetEntryGroupRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetEntryGroup(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::datacatalog::v1::GetEntryGroupRequest const& request) {
        return stub_->GetEntryGroup(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::EntryGroup>
DataCatalogConnectionImpl::UpdateEntryGroup(
    google::cloud::datacatalog::v1::UpdateEntryGroupRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateEntryGroup(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::UpdateEntryGroupRequest const&
                 request) { return stub_->UpdateEntryGroup(context, request); },
      request, __func__);
}

Status DataCatalogConnectionImpl::DeleteEntryGroup(
    google::cloud::datacatalog::v1::DeleteEntryGroupRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteEntryGroup(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::DeleteEntryGroupRequest const&
                 request) { return stub_->DeleteEntryGroup(context, request); },
      request, __func__);
}

StreamRange<google::cloud::datacatalog::v1::EntryGroup>
DataCatalogConnectionImpl::ListEntryGroups(
    google::cloud::datacatalog::v1::ListEntryGroupsRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<datacatalog::DataCatalogRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListEntryGroups(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::datacatalog::v1::EntryGroup>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::datacatalog::v1::ListEntryGroupsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::datacatalog::v1::ListEntryGroupsRequest const&
                       request) {
              return stub->ListEntryGroups(context, request);
            },
            r, function_name);
      },
      [](google::cloud::datacatalog::v1::ListEntryGroupsResponse r) {
        std::vector<google::cloud::datacatalog::v1::EntryGroup> result(
            r.entry_groups().size());
        auto& messages = *r.mutable_entry_groups();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::datacatalog::v1::Entry>
DataCatalogConnectionImpl::CreateEntry(
    google::cloud::datacatalog::v1::CreateEntryRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateEntry(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::datacatalog::v1::CreateEntryRequest const& request) {
        return stub_->CreateEntry(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::Entry>
DataCatalogConnectionImpl::UpdateEntry(
    google::cloud::datacatalog::v1::UpdateEntryRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateEntry(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::datacatalog::v1::UpdateEntryRequest const& request) {
        return stub_->UpdateEntry(context, request);
      },
      request, __func__);
}

Status DataCatalogConnectionImpl::DeleteEntry(
    google::cloud::datacatalog::v1::DeleteEntryRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteEntry(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::datacatalog::v1::DeleteEntryRequest const& request) {
        return stub_->DeleteEntry(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::Entry>
DataCatalogConnectionImpl::GetEntry(
    google::cloud::datacatalog::v1::GetEntryRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->GetEntry(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::GetEntryRequest const& request) {
        return stub_->GetEntry(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::Entry>
DataCatalogConnectionImpl::LookupEntry(
    google::cloud::datacatalog::v1::LookupEntryRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->LookupEntry(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::datacatalog::v1::LookupEntryRequest const& request) {
        return stub_->LookupEntry(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::datacatalog::v1::Entry>
DataCatalogConnectionImpl::ListEntries(
    google::cloud::datacatalog::v1::ListEntriesRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<datacatalog::DataCatalogRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListEntries(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::datacatalog::v1::Entry>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::datacatalog::v1::ListEntriesRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::datacatalog::v1::ListEntriesRequest const&
                       request) { return stub->ListEntries(context, request); },
            r, function_name);
      },
      [](google::cloud::datacatalog::v1::ListEntriesResponse r) {
        std::vector<google::cloud::datacatalog::v1::Entry> result(
            r.entries().size());
        auto& messages = *r.mutable_entries();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::datacatalog::v1::TagTemplate>
DataCatalogConnectionImpl::CreateTagTemplate(
    google::cloud::datacatalog::v1::CreateTagTemplateRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateTagTemplate(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::CreateTagTemplateRequest const&
                 request) {
        return stub_->CreateTagTemplate(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplate>
DataCatalogConnectionImpl::GetTagTemplate(
    google::cloud::datacatalog::v1::GetTagTemplateRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetTagTemplate(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::GetTagTemplateRequest const&
                 request) { return stub_->GetTagTemplate(context, request); },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplate>
DataCatalogConnectionImpl::UpdateTagTemplate(
    google::cloud::datacatalog::v1::UpdateTagTemplateRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateTagTemplate(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::UpdateTagTemplateRequest const&
                 request) {
        return stub_->UpdateTagTemplate(context, request);
      },
      request, __func__);
}

Status DataCatalogConnectionImpl::DeleteTagTemplate(
    google::cloud::datacatalog::v1::DeleteTagTemplateRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteTagTemplate(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::DeleteTagTemplateRequest const&
                 request) {
        return stub_->DeleteTagTemplate(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplateField>
DataCatalogConnectionImpl::CreateTagTemplateField(
    google::cloud::datacatalog::v1::CreateTagTemplateFieldRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateTagTemplateField(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::datacatalog::v1::CreateTagTemplateFieldRequest const&
              request) {
        return stub_->CreateTagTemplateField(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplateField>
DataCatalogConnectionImpl::UpdateTagTemplateField(
    google::cloud::datacatalog::v1::UpdateTagTemplateFieldRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateTagTemplateField(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::datacatalog::v1::UpdateTagTemplateFieldRequest const&
              request) {
        return stub_->UpdateTagTemplateField(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplateField>
DataCatalogConnectionImpl::RenameTagTemplateField(
    google::cloud::datacatalog::v1::RenameTagTemplateFieldRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->RenameTagTemplateField(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::datacatalog::v1::RenameTagTemplateFieldRequest const&
              request) {
        return stub_->RenameTagTemplateField(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplateField>
DataCatalogConnectionImpl::RenameTagTemplateFieldEnumValue(
    google::cloud::datacatalog::v1::
        RenameTagTemplateFieldEnumValueRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->RenameTagTemplateFieldEnumValue(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::
                 RenameTagTemplateFieldEnumValueRequest const& request) {
        return stub_->RenameTagTemplateFieldEnumValue(context, request);
      },
      request, __func__);
}

Status DataCatalogConnectionImpl::DeleteTagTemplateField(
    google::cloud::datacatalog::v1::DeleteTagTemplateFieldRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteTagTemplateField(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::datacatalog::v1::DeleteTagTemplateFieldRequest const&
              request) {
        return stub_->DeleteTagTemplateField(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::Tag>
DataCatalogConnectionImpl::CreateTag(
    google::cloud::datacatalog::v1::CreateTagRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateTag(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::CreateTagRequest const& request) {
        return stub_->CreateTag(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::datacatalog::v1::Tag>
DataCatalogConnectionImpl::UpdateTag(
    google::cloud::datacatalog::v1::UpdateTagRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateTag(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::UpdateTagRequest const& request) {
        return stub_->UpdateTag(context, request);
      },
      request, __func__);
}

Status DataCatalogConnectionImpl::DeleteTag(
    google::cloud::datacatalog::v1::DeleteTagRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteTag(request),
      [this](grpc::ClientContext& context,
             google::cloud::datacatalog::v1::DeleteTagRequest const& request) {
        return stub_->DeleteTag(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::datacatalog::v1::Tag>
DataCatalogConnectionImpl::ListTags(
    google::cloud::datacatalog::v1::ListTagsRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<datacatalog::DataCatalogRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListTags(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::datacatalog::v1::Tag>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::datacatalog::v1::ListTagsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::datacatalog::v1::ListTagsRequest const&
                       request) { return stub->ListTags(context, request); },
            r, function_name);
      },
      [](google::cloud::datacatalog::v1::ListTagsResponse r) {
        std::vector<google::cloud::datacatalog::v1::Tag> result(
            r.tags().size());
        auto& messages = *r.mutable_tags();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::iam::v1::Policy> DataCatalogConnectionImpl::SetIamPolicy(
    google::iam::v1::SetIamPolicyRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->SetIamPolicy(request),
      [this](grpc::ClientContext& context,
             google::iam::v1::SetIamPolicyRequest const& request) {
        return stub_->SetIamPolicy(context, request);
      },
      request, __func__);
}

StatusOr<google::iam::v1::Policy> DataCatalogConnectionImpl::GetIamPolicy(
    google::iam::v1::GetIamPolicyRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetIamPolicy(request),
      [this](grpc::ClientContext& context,
             google::iam::v1::GetIamPolicyRequest const& request) {
        return stub_->GetIamPolicy(context, request);
      },
      request, __func__);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
DataCatalogConnectionImpl::TestIamPermissions(
    google::iam::v1::TestIamPermissionsRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->TestIamPermissions(request),
      [this](grpc::ClientContext& context,
             google::iam::v1::TestIamPermissionsRequest const& request) {
        return stub_->TestIamPermissions(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datacatalog_internal
}  // namespace cloud
}  // namespace google
