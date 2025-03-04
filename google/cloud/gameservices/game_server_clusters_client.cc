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
// source: google/cloud/gaming/v1/game_server_clusters_service.proto

#include "google/cloud/gameservices/game_server_clusters_client.h"
#include "google/cloud/gameservices/internal/game_server_clusters_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace gameservices {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

GameServerClustersServiceClient::GameServerClustersServiceClient(
    std::shared_ptr<GameServerClustersServiceConnection> connection,
    Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options),
          gameservices_internal::GameServerClustersServiceDefaultOptions(
              connection_->options()))) {}
GameServerClustersServiceClient::~GameServerClustersServiceClient() = default;

StreamRange<google::cloud::gaming::v1::GameServerCluster>
GameServerClustersServiceClient::ListGameServerClusters(
    std::string const& parent, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::gaming::v1::ListGameServerClustersRequest request;
  request.set_parent(parent);
  return connection_->ListGameServerClusters(request);
}

StreamRange<google::cloud::gaming::v1::GameServerCluster>
GameServerClustersServiceClient::ListGameServerClusters(
    google::cloud::gaming::v1::ListGameServerClustersRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListGameServerClusters(std::move(request));
}

StatusOr<google::cloud::gaming::v1::GameServerCluster>
GameServerClustersServiceClient::GetGameServerCluster(std::string const& name,
                                                      Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::gaming::v1::GetGameServerClusterRequest request;
  request.set_name(name);
  return connection_->GetGameServerCluster(request);
}

StatusOr<google::cloud::gaming::v1::GameServerCluster>
GameServerClustersServiceClient::GetGameServerCluster(
    google::cloud::gaming::v1::GetGameServerClusterRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetGameServerCluster(request);
}

future<StatusOr<google::cloud::gaming::v1::GameServerCluster>>
GameServerClustersServiceClient::CreateGameServerCluster(
    std::string const& parent,
    google::cloud::gaming::v1::GameServerCluster const& game_server_cluster,
    std::string const& game_server_cluster_id, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::gaming::v1::CreateGameServerClusterRequest request;
  request.set_parent(parent);
  *request.mutable_game_server_cluster() = game_server_cluster;
  request.set_game_server_cluster_id(game_server_cluster_id);
  return connection_->CreateGameServerCluster(request);
}

future<StatusOr<google::cloud::gaming::v1::GameServerCluster>>
GameServerClustersServiceClient::CreateGameServerCluster(
    google::cloud::gaming::v1::CreateGameServerClusterRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateGameServerCluster(request);
}

StatusOr<google::cloud::gaming::v1::PreviewCreateGameServerClusterResponse>
GameServerClustersServiceClient::PreviewCreateGameServerCluster(
    google::cloud::gaming::v1::PreviewCreateGameServerClusterRequest const&
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->PreviewCreateGameServerCluster(request);
}

future<StatusOr<google::cloud::gaming::v1::OperationMetadata>>
GameServerClustersServiceClient::DeleteGameServerCluster(
    std::string const& name, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::gaming::v1::DeleteGameServerClusterRequest request;
  request.set_name(name);
  return connection_->DeleteGameServerCluster(request);
}

future<StatusOr<google::cloud::gaming::v1::OperationMetadata>>
GameServerClustersServiceClient::DeleteGameServerCluster(
    google::cloud::gaming::v1::DeleteGameServerClusterRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DeleteGameServerCluster(request);
}

StatusOr<google::cloud::gaming::v1::PreviewDeleteGameServerClusterResponse>
GameServerClustersServiceClient::PreviewDeleteGameServerCluster(
    google::cloud::gaming::v1::PreviewDeleteGameServerClusterRequest const&
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->PreviewDeleteGameServerCluster(request);
}

future<StatusOr<google::cloud::gaming::v1::GameServerCluster>>
GameServerClustersServiceClient::UpdateGameServerCluster(
    google::cloud::gaming::v1::GameServerCluster const& game_server_cluster,
    google::protobuf::FieldMask const& update_mask, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::gaming::v1::UpdateGameServerClusterRequest request;
  *request.mutable_game_server_cluster() = game_server_cluster;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateGameServerCluster(request);
}

future<StatusOr<google::cloud::gaming::v1::GameServerCluster>>
GameServerClustersServiceClient::UpdateGameServerCluster(
    google::cloud::gaming::v1::UpdateGameServerClusterRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateGameServerCluster(request);
}

StatusOr<google::cloud::gaming::v1::PreviewUpdateGameServerClusterResponse>
GameServerClustersServiceClient::PreviewUpdateGameServerCluster(
    google::cloud::gaming::v1::PreviewUpdateGameServerClusterRequest const&
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->PreviewUpdateGameServerCluster(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace gameservices
}  // namespace cloud
}  // namespace google
