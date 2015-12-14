/*
 * Copyright 2016 The Android Open Source Project
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

#ifndef ANDROID_I_MEDIA_RESOURCE_MONITOR_H
#define ANDROID_I_MEDIA_RESOURCE_MONITOR_H

#include <binder/IInterface.h>

namespace android {

// ----------------------------------------------------------------------

class IMediaResourceMonitor : public IInterface {
public:
    DECLARE_META_INTERFACE(MediaResourceMonitor);

    virtual void notifyResourceGranted(/*in*/ int32_t pid, /*in*/ const String16& type,
            /*in*/ const String16& subType, /*in*/ int64_t value) = 0;

    enum {
        NOTIFY_RESOURCE_GRANTED = IBinder::FIRST_CALL_TRANSACTION,
    };
};

// ----------------------------------------------------------------------

class BnMediaResourceMonitor : public BnInterface<IMediaResourceMonitor> {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply,
            uint32_t flags = 0);
};

// ----------------------------------------------------------------------

}; // namespace android

#endif // ANDROID_I_MEDIA_RESOURCE_MONITOR_H
