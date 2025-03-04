#!/usr/bin/env bash
#
# Copyright 2020 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set -euo pipefail

source "$(dirname "$0")/../../../../ci/lib/init.sh"
source module /ci/etc/integration-tests-config.sh
source module /ci/lib/run_gcs_httpbin_emulator_utils.sh

if [[ $# -lt 1 ]]; then
  echo "Usage: $(basename "$0") <binary-dir> [ctest-args]"
  exit 1
fi

BINARY_DIR="$(
  cd "${1}"
  pwd
)"
readonly BINARY_DIR
shift
ctest_args=("$@")

cd "${BINARY_DIR}"
start_emulator

# Create the test buckets in the emulator:
printf '{"name": "%s"}' "${GOOGLE_CLOUD_CPP_STORAGE_TEST_BUCKET_NAME}" |
  curl -X POST -H "Content-Type: application/json" --data-binary @- \
    "${CLOUD_STORAGE_EMULATOR_ENDPOINT}/storage/v1/b?project=${GOOGLE_CLOUD_PROJECT}"
printf '{"name": "%s"}' "${GOOGLE_CLOUD_CPP_STORAGE_TEST_DESTINATION_BUCKET_NAME}" |
  curl -s -X POST -H "Content-Type: application/json" --data-binary @- \
    "${CLOUD_STORAGE_EMULATOR_ENDPOINT}/storage/v1/b?project=${GOOGLE_CLOUD_PROJECT}"

ctest -R "^storage_" "${ctest_args[@]}"
exit_status=$?

kill_emulator
trap '' EXIT

if [[ "$exit_status" -ne 0 ]]; then
  cat "${HOME}/gcs_emulator.log"
fi

exit "${exit_status}"
