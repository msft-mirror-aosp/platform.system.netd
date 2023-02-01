/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Network.h"

namespace android::net {

class LocalNetwork : public Network {
public:
    explicit LocalNetwork(unsigned netId);
    virtual ~LocalNetwork();
    Permission getPermission() const { return PERMISSION_SYSTEM; };

private:
    std::string getTypeString() const override { return "LOCAL"; };
    [[nodiscard]] int addInterface(const std::string& interface) override;
    [[nodiscard]] int removeInterface(const std::string& interface) override;
};

}  // namespace android::net
