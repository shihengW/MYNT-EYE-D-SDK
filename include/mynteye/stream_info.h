// Copyright 2018 Slightech Co., Ltd. All rights reserved.
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
#ifndef MYNTEYE_STREAM_INFO_H_
#define MYNTEYE_STREAM_INFO_H_
#pragma once

#include "mynteye/stubs/global.h"
#include "mynteye/types.h"

MYNTEYE_BEGIN_NAMESPACE

/**
 * Stream information.
 */
struct MYNTEYE_API StreamInfo {
  /**
   * The stream index.
   */
  std::int32_t index;

  /**
   * The stream width.
   */
  std::int32_t width;

  /**
   * The stream height.
   */
  std::int32_t height;

  /**
   * The stream format.
   */
  StreamFormat format;
};

MYNTEYE_END_NAMESPACE

MYNTEYE_API
std::ostream& operator<<(std::ostream& os, const mynteye::StreamInfo& info);

#endif  // MYNTEYE_STREAM_INFO_H_