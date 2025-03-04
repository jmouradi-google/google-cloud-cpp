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
// source: google/cloud/websecurityscanner/v1/web_security_scanner.proto

#include "google/cloud/websecurityscanner/internal/web_security_scanner_metadata_decorator.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/cloud/websecurityscanner/v1/web_security_scanner.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace websecurityscanner_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

WebSecurityScannerMetadata::WebSecurityScannerMetadata(
    std::shared_ptr<WebSecurityScannerStub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::cloud::websecurityscanner::v1::ScanConfig>
WebSecurityScannerMetadata::CreateScanConfig(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::CreateScanConfigRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->CreateScanConfig(context, request);
}

Status WebSecurityScannerMetadata::DeleteScanConfig(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::DeleteScanConfigRequest const&
        request) {
  SetMetadata(context, "name=" + request.name());
  return child_->DeleteScanConfig(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ScanConfig>
WebSecurityScannerMetadata::GetScanConfig(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::GetScanConfigRequest const&
        request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetScanConfig(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ListScanConfigsResponse>
WebSecurityScannerMetadata::ListScanConfigs(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::ListScanConfigsRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListScanConfigs(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ScanConfig>
WebSecurityScannerMetadata::UpdateScanConfig(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::UpdateScanConfigRequest const&
        request) {
  SetMetadata(context, "scan_config.name=" + request.scan_config().name());
  return child_->UpdateScanConfig(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ScanRun>
WebSecurityScannerMetadata::StartScanRun(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::StartScanRunRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->StartScanRun(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ScanRun>
WebSecurityScannerMetadata::GetScanRun(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::GetScanRunRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetScanRun(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ListScanRunsResponse>
WebSecurityScannerMetadata::ListScanRuns(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::ListScanRunsRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListScanRuns(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ScanRun>
WebSecurityScannerMetadata::StopScanRun(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::StopScanRunRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->StopScanRun(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ListCrawledUrlsResponse>
WebSecurityScannerMetadata::ListCrawledUrls(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::ListCrawledUrlsRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListCrawledUrls(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::Finding>
WebSecurityScannerMetadata::GetFinding(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::GetFindingRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetFinding(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ListFindingsResponse>
WebSecurityScannerMetadata::ListFindings(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::ListFindingsRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListFindings(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ListFindingTypeStatsResponse>
WebSecurityScannerMetadata::ListFindingTypeStats(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::ListFindingTypeStatsRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListFindingTypeStats(context, request);
}

void WebSecurityScannerMetadata::SetMetadata(
    grpc::ClientContext& context, std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void WebSecurityScannerMetadata::SetMetadata(grpc::ClientContext& context) {
  context.AddMetadata("x-goog-api-client", api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace websecurityscanner_internal
}  // namespace cloud
}  // namespace google
