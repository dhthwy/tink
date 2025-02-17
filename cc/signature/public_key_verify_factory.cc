// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

#include "tink/signature/public_key_verify_factory.h"

#include <memory>

#include "tink/key_manager.h"
#include "tink/keyset_handle.h"
#include "tink/public_key_verify.h"
#include "tink/registry.h"
#include "tink/signature/public_key_verify_wrapper.h"
#include "tink/util/status.h"
#include "tink/util/statusor.h"

namespace crypto {
namespace tink {

// static
util::StatusOr<std::unique_ptr<PublicKeyVerify>>
PublicKeyVerifyFactory::GetPrimitive(const KeysetHandle& keyset_handle) {
  util::Status status = Registry::RegisterPrimitiveWrapper(
      absl::make_unique<PublicKeyVerifyWrapper>());
  if (!status.ok()) {
    return status;
  }
  return keyset_handle.GetPrimitive<PublicKeyVerify>();
}

// static
util::StatusOr<std::unique_ptr<PublicKeyVerify>>
PublicKeyVerifyFactory::GetPrimitive(
    const KeysetHandle& keyset_handle,
    const KeyManager<PublicKeyVerify>* custom_key_manager) {
  util::Status status = Registry::RegisterPrimitiveWrapper(
      absl::make_unique<PublicKeyVerifyWrapper>());
  if (!status.ok()) {
    return status;
  }
  return keyset_handle.GetPrimitive<PublicKeyVerify>(custom_key_manager);
}

}  // namespace tink
}  // namespace crypto
