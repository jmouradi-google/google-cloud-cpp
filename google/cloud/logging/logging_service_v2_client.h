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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LOGGING_LOGGING_SERVICE_V2_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LOGGING_LOGGING_SERVICE_V2_CLIENT_H

#include "google/cloud/logging/logging_service_v2_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <map>
#include <memory>

namespace google {
namespace cloud {
namespace logging {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service for ingesting and querying logs.
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
class LoggingServiceV2Client {
 public:
  explicit LoggingServiceV2Client(
      std::shared_ptr<LoggingServiceV2Connection> connection,
      Options options = {});
  ~LoggingServiceV2Client();

  //@{
  // @name Copy and move support
  LoggingServiceV2Client(LoggingServiceV2Client const&) = default;
  LoggingServiceV2Client& operator=(LoggingServiceV2Client const&) = default;
  LoggingServiceV2Client(LoggingServiceV2Client&&) = default;
  LoggingServiceV2Client& operator=(LoggingServiceV2Client&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(LoggingServiceV2Client const& a,
                         LoggingServiceV2Client const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(LoggingServiceV2Client const& a,
                         LoggingServiceV2Client const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Deletes all the log entries in a log. The log reappears if it receives new
  /// entries. Log entries written shortly before the delete operation might not
  /// be deleted. Entries received after the delete operation with a timestamp
  /// before the operation will be deleted.
  ///
  /// @param log_name  Required. The resource name of the log to delete:
  ///      "projects/[PROJECT_ID]/logs/[LOG_ID]"
  ///      "organizations/[ORGANIZATION_ID]/logs/[LOG_ID]"
  ///      "billingAccounts/[BILLING_ACCOUNT_ID]/logs/[LOG_ID]"
  ///      "folders/[FOLDER_ID]/logs/[LOG_ID]"
  ///  `[LOG_ID]` must be URL-encoded. For example,
  ///  `"projects/my-project-id/logs/syslog"`,
  ///  `"organizations/1234567890/logs/cloudresourcemanager.googleapis.com%2Factivity"`.
  ///  For more information about log names, see
  ///  [LogEntry][google.logging.v2.LogEntry].
  /// @param options  Optional. Operation options.
  ///
  /// [google.logging.v2.DeleteLogRequest]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L140}
  ///
  Status DeleteLog(std::string const& log_name, Options options = {});

  ///
  /// Deletes all the log entries in a log. The log reappears if it receives new
  /// entries. Log entries written shortly before the delete operation might not
  /// be deleted. Entries received after the delete operation with a timestamp
  /// before the operation will be deleted.
  ///
  /// @param request
  /// @googleapis_link{google::logging::v2::DeleteLogRequest,google/logging/v2/logging.proto#L140}
  /// @param options  Optional. Operation options.
  ///
  /// [google.logging.v2.DeleteLogRequest]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L140}
  ///
  Status DeleteLog(google::logging::v2::DeleteLogRequest const& request,
                   Options options = {});

  ///
  /// Writes log entries to Logging. This API method is the
  /// only way to send log entries to Logging. This method
  /// is used, directly or indirectly, by the Logging agent
  /// (fluentd) and all logging libraries configured to use Logging.
  /// A single request may contain log entries for a maximum of 1000
  /// different resources (projects, organizations, billing accounts or
  /// folders)
  ///
  /// @param log_name  Optional. A default log resource name that is assigned to
  /// all log entries
  ///  in `entries` that do not specify a value for `log_name`:
  ///      "projects/[PROJECT_ID]/logs/[LOG_ID]"
  ///      "organizations/[ORGANIZATION_ID]/logs/[LOG_ID]"
  ///      "billingAccounts/[BILLING_ACCOUNT_ID]/logs/[LOG_ID]"
  ///      "folders/[FOLDER_ID]/logs/[LOG_ID]"
  ///  `[LOG_ID]` must be URL-encoded. For example:
  ///      "projects/my-project-id/logs/syslog"
  ///      "organizations/1234567890/logs/cloudresourcemanager.googleapis.com%2Factivity"
  ///  The permission `logging.logEntries.create` is needed on each project,
  ///  organization, billing account, or folder that is receiving new log
  ///  entries, whether the resource is specified in `logName` or in an
  ///  individual log entry.
  /// @param resource  Optional. A default monitored resource object that is
  /// assigned to all log
  ///  entries in `entries` that do not specify a value for `resource`. Example:
  ///      { "type": "gce_instance",
  ///        "labels": {
  ///          "zone": "us-central1-a", "instance_id": "00000000000000000000" }}
  ///  See [LogEntry][google.logging.v2.LogEntry].
  /// @param labels  Optional. Default labels that are added to the `labels`
  /// field of all log
  ///  entries in `entries`. If a log entry already has a label with the same
  ///  key as a label in this parameter, then the log entry's label is not
  ///  changed. See [LogEntry][google.logging.v2.LogEntry].
  /// @param entries  Required. The log entries to send to Logging. The order of
  /// log
  ///  entries in this list does not matter. Values supplied in this method's
  ///  `log_name`, `resource`, and `labels` fields are copied into those log
  ///  entries in this list that do not include values for their corresponding
  ///  fields. For more information, see the
  ///  [LogEntry][google.logging.v2.LogEntry] type.
  ///  If the `timestamp` or `insert_id` fields are missing in log entries, then
  ///  this method supplies the current time or a unique identifier,
  ///  respectively. The supplied values are chosen so that, among the log
  ///  entries that did not supply their own values, the entries earlier in the
  ///  list will sort before the entries later in the list. See the
  ///  `entries.list` method. Log entries with timestamps that are more than the
  ///  [logs retention period](https://cloud.google.com/logging/quota-policy) in
  ///  the past or more than 24 hours in the future will not be available when
  ///  calling `entries.list`. However, those log entries can still be [exported
  ///  with
  ///  LogSinks](https://cloud.google.com/logging/docs/api/tasks/exporting-logs).
  ///  To improve throughput and to avoid exceeding the
  ///  [quota limit](https://cloud.google.com/logging/quota-policy) for calls to
  ///  `entries.write`, you should try to include several log entries in this
  ///  list, rather than calling this method for each individual log entry.
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::logging::v2::WriteLogEntriesResponse,google/logging/v2/logging.proto#L243}
  ///
  /// [google.logging.v2.WriteLogEntriesRequest]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L162}
  /// [google.logging.v2.WriteLogEntriesResponse]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L243}
  ///
  StatusOr<google::logging::v2::WriteLogEntriesResponse> WriteLogEntries(
      std::string const& log_name,
      google::api::MonitoredResource const& resource,
      std::map<std::string, std::string> const& labels,
      std::vector<google::logging::v2::LogEntry> const& entries,
      Options options = {});

  ///
  /// Writes log entries to Logging. This API method is the
  /// only way to send log entries to Logging. This method
  /// is used, directly or indirectly, by the Logging agent
  /// (fluentd) and all logging libraries configured to use Logging.
  /// A single request may contain log entries for a maximum of 1000
  /// different resources (projects, organizations, billing accounts or
  /// folders)
  ///
  /// @param request
  /// @googleapis_link{google::logging::v2::WriteLogEntriesRequest,google/logging/v2/logging.proto#L162}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::logging::v2::WriteLogEntriesResponse,google/logging/v2/logging.proto#L243}
  ///
  /// [google.logging.v2.WriteLogEntriesRequest]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L162}
  /// [google.logging.v2.WriteLogEntriesResponse]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L243}
  ///
  StatusOr<google::logging::v2::WriteLogEntriesResponse> WriteLogEntries(
      google::logging::v2::WriteLogEntriesRequest const& request,
      Options options = {});

  ///
  /// Lists log entries.  Use this method to retrieve log entries that
  /// originated from a project/folder/organization/billing account.  For ways
  /// to export log entries, see [Exporting
  /// Logs](https://cloud.google.com/logging/docs/export).
  ///
  /// @param resource_names  Required. Names of one or more parent resources
  /// from which to
  ///  retrieve log entries:
  ///      "projects/[PROJECT_ID]"
  ///      "organizations/[ORGANIZATION_ID]"
  ///      "billingAccounts/[BILLING_ACCOUNT_ID]"
  ///      "folders/[FOLDER_ID]"
  ///  May alternatively be one or more views
  ///    projects/[PROJECT_ID]/locations/[LOCATION_ID]/buckets/[BUCKET_ID]/views/[VIEW_ID]
  ///    organization/[ORGANIZATION_ID]/locations/[LOCATION_ID]/buckets/[BUCKET_ID]/views/[VIEW_ID]
  ///    billingAccounts/[BILLING_ACCOUNT_ID]/locations/[LOCATION_ID]/buckets/[BUCKET_ID]/views/[VIEW_ID]
  ///    folders/[FOLDER_ID]/locations/[LOCATION_ID]/buckets/[BUCKET_ID]/views/[VIEW_ID]
  ///  Projects listed in the `project_ids` field are added to this list.
  /// @param filter  Optional. A filter that chooses which log entries to
  /// return.  See [Advanced
  ///  Logs
  ///  Queries](https://cloud.google.com/logging/docs/view/advanced-queries).
  ///  Only log entries that match the filter are returned.  An empty filter
  ///  matches all log entries in the resources listed in `resource_names`.
  ///  Referencing a parent resource that is not listed in `resource_names` will
  ///  cause the filter to return no results. The maximum length of the filter
  ///  is 20000 characters.
  /// @param order_by  Optional. How the results should be sorted.  Presently,
  /// the only permitted
  ///  values are `"timestamp asc"` (default) and `"timestamp desc"`. The first
  ///  option returns entries in order of increasing values of
  ///  `LogEntry.timestamp` (oldest first), and the second option returns
  ///  entries in order of decreasing timestamps (newest first).  Entries with
  ///  equal timestamps are returned in order of their `insert_id` values.
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::logging::v2::LogEntry,google/logging/v2/log_entry.proto#L42}
  ///
  /// [google.logging.v2.ListLogEntriesRequest]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L257}
  /// [google.logging.v2.LogEntry]:
  /// @googleapis_reference_link{google/logging/v2/log_entry.proto#L42}
  ///
  StreamRange<google::logging::v2::LogEntry> ListLogEntries(
      std::vector<std::string> const& resource_names, std::string const& filter,
      std::string const& order_by, Options options = {});

  ///
  /// Lists log entries.  Use this method to retrieve log entries that
  /// originated from a project/folder/organization/billing account.  For ways
  /// to export log entries, see [Exporting
  /// Logs](https://cloud.google.com/logging/docs/export).
  ///
  /// @param request
  /// @googleapis_link{google::logging::v2::ListLogEntriesRequest,google/logging/v2/logging.proto#L257}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::logging::v2::LogEntry,google/logging/v2/log_entry.proto#L42}
  ///
  /// [google.logging.v2.ListLogEntriesRequest]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L257}
  /// [google.logging.v2.LogEntry]:
  /// @googleapis_reference_link{google/logging/v2/log_entry.proto#L42}
  ///
  StreamRange<google::logging::v2::LogEntry> ListLogEntries(
      google::logging::v2::ListLogEntriesRequest request, Options options = {});

  ///
  /// Lists the descriptors for monitored resource types used by Logging.
  ///
  /// @param request
  /// @googleapis_link{google::logging::v2::ListMonitoredResourceDescriptorsRequest,google/logging/v2/logging.proto#L331}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::api::MonitoredResourceDescriptor,google/api/monitored_resource.proto#L40}
  ///
  /// [google.logging.v2.ListMonitoredResourceDescriptorsRequest]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L331}
  /// [google.api.MonitoredResourceDescriptor]:
  /// @googleapis_reference_link{google/api/monitored_resource.proto#L40}
  ///
  StreamRange<google::api::MonitoredResourceDescriptor>
  ListMonitoredResourceDescriptors(
      google::logging::v2::ListMonitoredResourceDescriptorsRequest request,
      Options options = {});

  ///
  /// Lists the logs in projects, organizations, folders, or billing accounts.
  /// Only logs that have entries are listed.
  ///
  /// @param parent  Required. The resource name that owns the logs:
  ///      "projects/[PROJECT_ID]"
  ///      "organizations/[ORGANIZATION_ID]"
  ///      "billingAccounts/[BILLING_ACCOUNT_ID]"
  ///      "folders/[FOLDER_ID]"
  /// @param options  Optional. Operation options.
  /// @return std::string
  ///
  /// [google.logging.v2.ListLogsRequest]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L356}
  ///
  StreamRange<std::string> ListLogs(std::string const& parent,
                                    Options options = {});

  ///
  /// Lists the logs in projects, organizations, folders, or billing accounts.
  /// Only logs that have entries are listed.
  ///
  /// @param request
  /// @googleapis_link{google::logging::v2::ListLogsRequest,google/logging/v2/logging.proto#L356}
  /// @param options  Optional. Operation options.
  /// @return std::string
  ///
  /// [google.logging.v2.ListLogsRequest]:
  /// @googleapis_reference_link{google/logging/v2/logging.proto#L356}
  ///
  StreamRange<std::string> ListLogs(
      google::logging::v2::ListLogsRequest request, Options options = {});

  std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      google::logging::v2::TailLogEntriesRequest,
      google::logging::v2::TailLogEntriesResponse>>
  AsyncTailLogEntries(Options options = {});

 private:
  std::shared_ptr<LoggingServiceV2Connection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace logging
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LOGGING_LOGGING_SERVICE_V2_CLIENT_H
