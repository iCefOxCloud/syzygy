// Copyright 2015 Google Inc. All Rights Reserved.
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

#ifndef SYZYGY_KASKO_LOADER_LOCK_H_
#define SYZYGY_KASKO_LOADER_LOCK_H_

#include <Windows.h>

namespace kasko {

// Retrieves the loader lock from the Process Environment Block (PEB).
CRITICAL_SECTION* GetLoaderLock();

}  // namespace kasko

#endif  // SYZYGY_KASKO_LOADER_LOCK_H_
