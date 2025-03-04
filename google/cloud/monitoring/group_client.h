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
// source: google/monitoring/v3/group_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_GROUP_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_GROUP_CLIENT_H

#include "google/cloud/monitoring/group_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// The Group API lets you inspect and manage your
/// [groups](#google.monitoring.v3.Group).
///
/// A group is a named filter that is used to identify
/// a collection of monitored resources. Groups are typically used to
/// mirror the physical and/or logical topology of the environment.
/// Because group membership is computed dynamically, monitored
/// resources that are started in the future are automatically placed
/// in matching groups. By using a group to name monitored resources in,
/// for example, an alert policy, the target of that alert policy is
/// updated automatically as monitored resources are added and removed
/// from the infrastructure.
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class GroupServiceClient {
 public:
  explicit GroupServiceClient(
      std::shared_ptr<GroupServiceConnection> connection, Options options = {});
  ~GroupServiceClient();

  //@{
  // @name Copy and move support
  GroupServiceClient(GroupServiceClient const&) = default;
  GroupServiceClient& operator=(GroupServiceClient const&) = default;
  GroupServiceClient(GroupServiceClient&&) = default;
  GroupServiceClient& operator=(GroupServiceClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(GroupServiceClient const& a,
                         GroupServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(GroupServiceClient const& a,
                         GroupServiceClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Lists the existing groups.
  ///
  /// @param name  Required. The
  /// [project](https://cloud.google.com/monitoring/api/v3#project_name)
  ///  whose groups are to be listed. The format is:
  ///      projects/[PROJECT_ID_OR_NUMBER]
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::Group,google/monitoring/v3/group.proto#L55}
  ///
  /// [google.monitoring.v3.ListGroupsRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L108}
  /// [google.monitoring.v3.Group]:
  /// @googleapis_reference_link{google/monitoring/v3/group.proto#L55}
  ///
  StreamRange<google::monitoring::v3::Group> ListGroups(std::string const& name,
                                                        Options options = {});

  ///
  /// Lists the existing groups.
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::ListGroupsRequest,google/monitoring/v3/group_service.proto#L108}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::Group,google/monitoring/v3/group.proto#L55}
  ///
  /// [google.monitoring.v3.ListGroupsRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L108}
  /// [google.monitoring.v3.Group]:
  /// @googleapis_reference_link{google/monitoring/v3/group.proto#L55}
  ///
  StreamRange<google::monitoring::v3::Group> ListGroups(
      google::monitoring::v3::ListGroupsRequest request, Options options = {});

  ///
  /// Gets a single group.
  ///
  /// @param name  Required. The group to retrieve. The format is:
  ///      projects/[PROJECT_ID_OR_NUMBER]/groups/[GROUP_ID]
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::Group,google/monitoring/v3/group.proto#L55}
  ///
  /// [google.monitoring.v3.GetGroupRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L179}
  /// [google.monitoring.v3.Group]:
  /// @googleapis_reference_link{google/monitoring/v3/group.proto#L55}
  ///
  StatusOr<google::monitoring::v3::Group> GetGroup(std::string const& name,
                                                   Options options = {});

  ///
  /// Gets a single group.
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::GetGroupRequest,google/monitoring/v3/group_service.proto#L179}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::Group,google/monitoring/v3/group.proto#L55}
  ///
  /// [google.monitoring.v3.GetGroupRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L179}
  /// [google.monitoring.v3.Group]:
  /// @googleapis_reference_link{google/monitoring/v3/group.proto#L55}
  ///
  StatusOr<google::monitoring::v3::Group> GetGroup(
      google::monitoring::v3::GetGroupRequest const& request,
      Options options = {});

  ///
  /// Creates a new group.
  ///
  /// @param name  Required. The
  /// [project](https://cloud.google.com/monitoring/api/v3#project_name) in
  ///  which to create the group. The format is:
  ///      projects/[PROJECT_ID_OR_NUMBER]
  /// @param group  Required. A group definition. It is an error to define the
  /// `name` field because
  ///  the system assigns the name.
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::Group,google/monitoring/v3/group.proto#L55}
  ///
  /// [google.monitoring.v3.CreateGroupRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L192}
  /// [google.monitoring.v3.Group]:
  /// @googleapis_reference_link{google/monitoring/v3/group.proto#L55}
  ///
  StatusOr<google::monitoring::v3::Group> CreateGroup(
      std::string const& name, google::monitoring::v3::Group const& group,
      Options options = {});

  ///
  /// Creates a new group.
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::CreateGroupRequest,google/monitoring/v3/group_service.proto#L192}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::Group,google/monitoring/v3/group.proto#L55}
  ///
  /// [google.monitoring.v3.CreateGroupRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L192}
  /// [google.monitoring.v3.Group]:
  /// @googleapis_reference_link{google/monitoring/v3/group.proto#L55}
  ///
  StatusOr<google::monitoring::v3::Group> CreateGroup(
      google::monitoring::v3::CreateGroupRequest const& request,
      Options options = {});

  ///
  /// Updates an existing group.
  /// You can change any group attributes except `name`.
  ///
  /// @param group  Required. The new definition of the group.  All fields of
  /// the existing group,
  ///  excepting `name`, are replaced with the corresponding fields of this
  ///  group.
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::Group,google/monitoring/v3/group.proto#L55}
  ///
  /// [google.monitoring.v3.UpdateGroupRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L213}
  /// [google.monitoring.v3.Group]:
  /// @googleapis_reference_link{google/monitoring/v3/group.proto#L55}
  ///
  StatusOr<google::monitoring::v3::Group> UpdateGroup(
      google::monitoring::v3::Group const& group, Options options = {});

  ///
  /// Updates an existing group.
  /// You can change any group attributes except `name`.
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::UpdateGroupRequest,google/monitoring/v3/group_service.proto#L213}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::Group,google/monitoring/v3/group.proto#L55}
  ///
  /// [google.monitoring.v3.UpdateGroupRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L213}
  /// [google.monitoring.v3.Group]:
  /// @googleapis_reference_link{google/monitoring/v3/group.proto#L55}
  ///
  StatusOr<google::monitoring::v3::Group> UpdateGroup(
      google::monitoring::v3::UpdateGroupRequest const& request,
      Options options = {});

  ///
  /// Deletes an existing group.
  ///
  /// @param name  Required. The group to delete. The format is:
  ///      projects/[PROJECT_ID_OR_NUMBER]/groups/[GROUP_ID]
  /// @param options  Optional. Operation options.
  ///
  /// [google.monitoring.v3.DeleteGroupRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L224}
  ///
  Status DeleteGroup(std::string const& name, Options options = {});

  ///
  /// Deletes an existing group.
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::DeleteGroupRequest,google/monitoring/v3/group_service.proto#L224}
  /// @param options  Optional. Operation options.
  ///
  /// [google.monitoring.v3.DeleteGroupRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L224}
  ///
  Status DeleteGroup(google::monitoring::v3::DeleteGroupRequest const& request,
                     Options options = {});

  ///
  /// Lists the monitored resources that are members of a group.
  ///
  /// @param name  Required. The group whose members are listed. The format is:
  ///      projects/[PROJECT_ID_OR_NUMBER]/groups/[GROUP_ID]
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::api::MonitoredResource,google/api/monitored_resource.proto#L85}
  ///
  /// [google.monitoring.v3.ListGroupMembersRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L242}
  /// [google.api.MonitoredResource]:
  /// @googleapis_reference_link{google/api/monitored_resource.proto#L85}
  ///
  StreamRange<google::api::MonitoredResource> ListGroupMembers(
      std::string const& name, Options options = {});

  ///
  /// Lists the monitored resources that are members of a group.
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::ListGroupMembersRequest,google/monitoring/v3/group_service.proto#L242}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::api::MonitoredResource,google/api/monitored_resource.proto#L85}
  ///
  /// [google.monitoring.v3.ListGroupMembersRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/group_service.proto#L242}
  /// [google.api.MonitoredResource]:
  /// @googleapis_reference_link{google/api/monitored_resource.proto#L85}
  ///
  StreamRange<google::api::MonitoredResource> ListGroupMembers(
      google::monitoring::v3::ListGroupMembersRequest request,
      Options options = {});

 private:
  std::shared_ptr<GroupServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_GROUP_CLIENT_H
