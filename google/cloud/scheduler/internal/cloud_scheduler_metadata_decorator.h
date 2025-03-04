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
// source: google/cloud/scheduler/v1/cloudscheduler.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SCHEDULER_INTERNAL_CLOUD_SCHEDULER_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SCHEDULER_INTERNAL_CLOUD_SCHEDULER_METADATA_DECORATOR_H

#include "google/cloud/scheduler/internal/cloud_scheduler_stub.h"
#include "google/cloud/version.h"
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace scheduler_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class CloudSchedulerMetadata : public CloudSchedulerStub {
 public:
  ~CloudSchedulerMetadata() override = default;
  explicit CloudSchedulerMetadata(std::shared_ptr<CloudSchedulerStub> child);

  StatusOr<google::cloud::scheduler::v1::ListJobsResponse> ListJobs(
      grpc::ClientContext& context,
      google::cloud::scheduler::v1::ListJobsRequest const& request) override;

  StatusOr<google::cloud::scheduler::v1::Job> GetJob(
      grpc::ClientContext& context,
      google::cloud::scheduler::v1::GetJobRequest const& request) override;

  StatusOr<google::cloud::scheduler::v1::Job> CreateJob(
      grpc::ClientContext& context,
      google::cloud::scheduler::v1::CreateJobRequest const& request) override;

  StatusOr<google::cloud::scheduler::v1::Job> UpdateJob(
      grpc::ClientContext& context,
      google::cloud::scheduler::v1::UpdateJobRequest const& request) override;

  Status DeleteJob(
      grpc::ClientContext& context,
      google::cloud::scheduler::v1::DeleteJobRequest const& request) override;

  StatusOr<google::cloud::scheduler::v1::Job> PauseJob(
      grpc::ClientContext& context,
      google::cloud::scheduler::v1::PauseJobRequest const& request) override;

  StatusOr<google::cloud::scheduler::v1::Job> ResumeJob(
      grpc::ClientContext& context,
      google::cloud::scheduler::v1::ResumeJobRequest const& request) override;

  StatusOr<google::cloud::scheduler::v1::Job> RunJob(
      grpc::ClientContext& context,
      google::cloud::scheduler::v1::RunJobRequest const& request) override;

 private:
  void SetMetadata(grpc::ClientContext& context,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context);

  std::shared_ptr<CloudSchedulerStub> child_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace scheduler_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SCHEDULER_INTERNAL_CLOUD_SCHEDULER_METADATA_DECORATOR_H
