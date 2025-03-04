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
// source: google/logging/v2/logging.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LOGGING_INTERNAL_LOGGING_SERVICE_V2_LOGGING_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LOGGING_INTERNAL_LOGGING_SERVICE_V2_LOGGING_DECORATOR_H

#include "google/cloud/logging/internal/logging_service_v2_stub.h"
#include "google/cloud/tracing_options.h"
#include "google/cloud/version.h"
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace logging_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class LoggingServiceV2Logging : public LoggingServiceV2Stub {
 public:
  ~LoggingServiceV2Logging() override = default;
  LoggingServiceV2Logging(std::shared_ptr<LoggingServiceV2Stub> child,
                          TracingOptions tracing_options,
                          std::set<std::string> components);

  Status DeleteLog(
      grpc::ClientContext& context,
      google::logging::v2::DeleteLogRequest const& request) override;

  StatusOr<google::logging::v2::WriteLogEntriesResponse> WriteLogEntries(
      grpc::ClientContext& context,
      google::logging::v2::WriteLogEntriesRequest const& request) override;

  StatusOr<google::logging::v2::ListLogEntriesResponse> ListLogEntries(
      grpc::ClientContext& context,
      google::logging::v2::ListLogEntriesRequest const& request) override;

  StatusOr<google::logging::v2::ListMonitoredResourceDescriptorsResponse>
  ListMonitoredResourceDescriptors(
      grpc::ClientContext& context,
      google::logging::v2::ListMonitoredResourceDescriptorsRequest const&
          request) override;

  StatusOr<google::logging::v2::ListLogsResponse> ListLogs(
      grpc::ClientContext& context,
      google::logging::v2::ListLogsRequest const& request) override;

  std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      google::logging::v2::TailLogEntriesRequest,
      google::logging::v2::TailLogEntriesResponse>>
  AsyncTailLogEntries(google::cloud::CompletionQueue const& cq,
                      std::unique_ptr<grpc::ClientContext> context) override;

 private:
  std::shared_ptr<LoggingServiceV2Stub> child_;
  TracingOptions tracing_options_;
  std::set<std::string> components_;
};  // LoggingServiceV2Logging

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace logging_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LOGGING_INTERNAL_LOGGING_SERVICE_V2_LOGGING_DECORATOR_H
