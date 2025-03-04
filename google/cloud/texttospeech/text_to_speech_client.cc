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
// source: google/cloud/texttospeech/v1/cloud_tts.proto

#include "google/cloud/texttospeech/text_to_speech_client.h"
#include "google/cloud/texttospeech/internal/text_to_speech_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace texttospeech {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TextToSpeechClient::TextToSpeechClient(
    std::shared_ptr<TextToSpeechConnection> connection, Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options), texttospeech_internal::TextToSpeechDefaultOptions(
                                  connection_->options()))) {}
TextToSpeechClient::~TextToSpeechClient() = default;

StatusOr<google::cloud::texttospeech::v1::ListVoicesResponse>
TextToSpeechClient::ListVoices(std::string const& language_code,
                               Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::texttospeech::v1::ListVoicesRequest request;
  request.set_language_code(language_code);
  return connection_->ListVoices(request);
}

StatusOr<google::cloud::texttospeech::v1::ListVoicesResponse>
TextToSpeechClient::ListVoices(
    google::cloud::texttospeech::v1::ListVoicesRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListVoices(request);
}

StatusOr<google::cloud::texttospeech::v1::SynthesizeSpeechResponse>
TextToSpeechClient::SynthesizeSpeech(
    google::cloud::texttospeech::v1::SynthesisInput const& input,
    google::cloud::texttospeech::v1::VoiceSelectionParams const& voice,
    google::cloud::texttospeech::v1::AudioConfig const& audio_config,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::texttospeech::v1::SynthesizeSpeechRequest request;
  *request.mutable_input() = input;
  *request.mutable_voice() = voice;
  *request.mutable_audio_config() = audio_config;
  return connection_->SynthesizeSpeech(request);
}

StatusOr<google::cloud::texttospeech::v1::SynthesizeSpeechResponse>
TextToSpeechClient::SynthesizeSpeech(
    google::cloud::texttospeech::v1::SynthesizeSpeechRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->SynthesizeSpeech(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace texttospeech
}  // namespace cloud
}  // namespace google
