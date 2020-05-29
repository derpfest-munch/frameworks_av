/*
 * Copyright (C) 2020 The Android Open Source Project
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

#include "AudioTypes.h"
#include "StringUtils.h"
#include <media/TypeConverter.h> // requires libmedia_helper to get the Audio code.

namespace android::mediametrics::types {

std::unordered_map<std::string, int64_t>& getAudioDeviceInMap() {
    // DO NOT MODIFY VALUES (OK to add new ones).  This does NOT match audio_device_t.
    static std::unordered_map<std::string, int64_t> map{
        {"AUDIO_DEVICE_IN_COMMUNICATION",          1LL << 0},
        {"AUDIO_DEVICE_IN_AMBIENT",                1LL << 1},
        {"AUDIO_DEVICE_IN_BUILTIN_MIC",            1LL << 2},
        {"AUDIO_DEVICE_IN_BLUETOOTH_SCO_HEADSET",  1LL << 3},
        {"AUDIO_DEVICE_IN_WIRED_HEADSET",          1LL << 4},
        {"AUDIO_DEVICE_IN_AUX_DIGITAL",            1LL << 5},
        {"AUDIO_DEVICE_IN_HDMI",                   1LL << 5}, // HDMI == AUX_DIGITAL (6 reserved)
        {"AUDIO_DEVICE_IN_VOICE_CALL",             1LL << 7},
        {"AUDIO_DEVICE_IN_TELEPHONY_RX",           1LL << 7}, // TELEPHONY_RX == VOICE_CALL (8 reserved)
        {"AUDIO_DEVICE_IN_BACK_MIC",               1LL << 9},
        {"AUDIO_DEVICE_IN_REMOTE_SUBMIX",          1LL << 10},
        {"AUDIO_DEVICE_IN_ANLG_DOCK_HEADSET",      1LL << 11},
        {"AUDIO_DEVICE_IN_DGTL_DOCK_HEADSET",      1LL << 12},
        {"AUDIO_DEVICE_IN_USB_ACCESSORY",          1LL << 13},
        {"AUDIO_DEVICE_IN_USB_DEVICE",             1LL << 14},
        {"AUDIO_DEVICE_IN_FM_TUNER",               1LL << 15},
        {"AUDIO_DEVICE_IN_TV_TUNER",               1LL << 16},
        {"AUDIO_DEVICE_IN_LINE",                   1LL << 17},
        {"AUDIO_DEVICE_IN_SPDIF",                  1LL << 18},
        {"AUDIO_DEVICE_IN_BLUETOOTH_A2DP",         1LL << 19},
        {"AUDIO_DEVICE_IN_LOOPBACK",               1LL << 20},
        {"AUDIO_DEVICE_IN_IP",                     1LL << 21},
        {"AUDIO_DEVICE_IN_BUS",                    1LL << 22},
        {"AUDIO_DEVICE_IN_PROXY",                  1LL << 23},
        {"AUDIO_DEVICE_IN_USB_HEADSET",            1LL << 24},
        {"AUDIO_DEVICE_IN_BLUETOOTH_BLE",          1LL << 25},
        {"AUDIO_DEVICE_IN_HDMI_ARC",               1LL << 26},
        {"AUDIO_DEVICE_IN_ECHO_REFERENCE",         1LL << 27},
        {"AUDIO_DEVICE_IN_DEFAULT",                1LL << 28},
        // R values above.
    };
    return map;
}

std::unordered_map<std::string, int64_t>& getAudioDeviceOutMap() {
    // DO NOT MODIFY VALUES (OK to add new ones).  This does NOT match audio_device_t.
    static std::unordered_map<std::string, int64_t> map{
        {"AUDIO_DEVICE_OUT_EARPIECE",                  1LL << 0},
        {"AUDIO_DEVICE_OUT_SPEAKER",                   1LL << 1},
        {"AUDIO_DEVICE_OUT_WIRED_HEADSET",             1LL << 2},
        {"AUDIO_DEVICE_OUT_WIRED_HEADPHONE",           1LL << 3},
        {"AUDIO_DEVICE_OUT_BLUETOOTH_SCO",             1LL << 4},
        {"AUDIO_DEVICE_OUT_BLUETOOTH_SCO_HEADSET",     1LL << 5},
        {"AUDIO_DEVICE_OUT_BLUETOOTH_SCO_CARKIT",      1LL << 6},
        {"AUDIO_DEVICE_OUT_BLUETOOTH_A2DP",            1LL << 7},
        {"AUDIO_DEVICE_OUT_BLUETOOTH_A2DP_HEADPHONES", 1LL << 8},
        {"AUDIO_DEVICE_OUT_BLUETOOTH_A2DP_SPEAKER",    1LL << 9},
        {"AUDIO_DEVICE_OUT_AUX_DIGITAL",               1LL << 10},
        {"AUDIO_DEVICE_OUT_HDMI",                      1LL << 10}, // HDMI == AUX_DIGITAL (11 reserved)
        {"AUDIO_DEVICE_OUT_ANLG_DOCK_HEADSET",         1LL << 12},
        {"AUDIO_DEVICE_OUT_DGTL_DOCK_HEADSET",         1LL << 13},
        {"AUDIO_DEVICE_OUT_USB_ACCESSORY",             1LL << 14},
        {"AUDIO_DEVICE_OUT_USB_DEVICE",                1LL << 15},
        {"AUDIO_DEVICE_OUT_REMOTE_SUBMIX",             1LL << 16},
        {"AUDIO_DEVICE_OUT_TELEPHONY_TX",              1LL << 17},
        {"AUDIO_DEVICE_OUT_LINE",                      1LL << 18},
        {"AUDIO_DEVICE_OUT_HDMI_ARC",                  1LL << 19},
        {"AUDIO_DEVICE_OUT_SPDIF",                     1LL << 20},
        {"AUDIO_DEVICE_OUT_FM",                        1LL << 21},
        {"AUDIO_DEVICE_OUT_AUX_LINE",                  1LL << 22},
        {"AUDIO_DEVICE_OUT_SPEAKER_SAFE",              1LL << 23},
        {"AUDIO_DEVICE_OUT_IP",                        1LL << 24},
        {"AUDIO_DEVICE_OUT_BUS",                       1LL << 25},
        {"AUDIO_DEVICE_OUT_PROXY",                     1LL << 26},
        {"AUDIO_DEVICE_OUT_USB_HEADSET",               1LL << 27},
        {"AUDIO_DEVICE_OUT_HEARING_AID",               1LL << 28},
        {"AUDIO_DEVICE_OUT_ECHO_CANCELLER",            1LL << 29},
        {"AUDIO_DEVICE_OUT_DEFAULT",                   1LL << 30},
        // R values above.
    };
    return map;
}

std::unordered_map<std::string, int32_t>& getCallerNameMap() {
    // DO NOT MODIFY VALUES (OK to add new ones).
    // This may be found in frameworks/av/media/libmediametrics/include/MediaMetricsConstants.h
    static std::unordered_map<std::string, int32_t> map{
        {"aaudio",        0},           // Native AAudio
        {"java",          1},           // Java API layer
        {"media",         2},           // libmedia (mediaplayer)
        {"opensles",      3},           // Open SLES
        {"rtp",           4},           // RTP communication
        {"soundpool",     5},           // SoundPool
        {"tonegenerator", 6},           // dial tones
        {"unknown",       7},           // callerName not set
        // R values above.
    };
    return map;
}

std::unordered_map<std::string, int32_t>& getThreadTypeMap() {
    // DO NOT MODIFY VALUES (OK to add new ones).
    // This may be found in frameworks/av/services/audioflinger/Threads.h
    static std::unordered_map<std::string, int32_t> map{
        // UNKNOWN is -1
        {"MIXER",         0},          // Thread class is MixerThread
        {"DIRECT",        1},          // Thread class is DirectOutputThread
        {"DUPLICATING",   2},          // Thread class is DuplicatingThread
        {"RECORD",        3},          // Thread class is RecordThread
        {"OFFLOAD",       4},          // Thread class is OffloadThread
        {"MMAP_PLAYBACK", 5},          // Thread class for MMAP playback stream
        {"MMAP_CAPTURE",  6},          // Thread class for MMAP capture stream
        // R values above.
    };
    return map;
}

// Helper: Create the corresponding int32 from string flags split with '|'.
template <typename Traits>
int32_t int32FromFlags(const std::string &flags)
{
    const auto result = stringutils::split(flags, "|");
    int32_t intFlags = 0;
    for (const auto& flag : result) {
        typename Traits::Type value;
        if (!TypeConverter<Traits>::fromString(flag, value)) {
            break;
        }
        intFlags |= value;
    }
    return intFlags;
}

template <typename Traits>
std::string stringFromFlags(const std::string &flags, size_t len)
{
    const auto result = stringutils::split(flags, "|");
    std::string sFlags;
    for (const auto& flag : result) {
        typename Traits::Type value;
        if (!TypeConverter<Traits>::fromString(flag, value)) {
            break;
        }
        if (len >= flag.size()) continue;
        if (!sFlags.empty()) sFlags += "|";
        sFlags += flag.c_str() + len;
    }
    return sFlags;
}

template <>
int32_t lookup<CONTENT_TYPE>(const std::string &contentType)
{
    AudioContentTraits::Type value;
    if (!TypeConverter<AudioContentTraits>::fromString(contentType, value)) {
        value = AUDIO_CONTENT_TYPE_UNKNOWN;
    }
    return (int32_t)value;
}

template <>
std::string lookup<CONTENT_TYPE>(const std::string &contentType)
{
    AudioContentTraits::Type value;
    if (!TypeConverter<AudioContentTraits>::fromString(contentType, value)) {
        return "UNKNOWN";
    }
    return contentType.c_str() + sizeof("AUDIO_CONTENT_TYPE");
}

template <>
int32_t lookup<ENCODING>(const std::string &encoding)
{
    FormatTraits::Type value;
    if (!TypeConverter<FormatTraits>::fromString(encoding, value)) {
        value = AUDIO_FORMAT_INVALID;
    }
    return (int32_t)value;
}

template <>
std::string lookup<ENCODING>(const std::string &encoding)
{
    FormatTraits::Type value;
    if (!TypeConverter<FormatTraits>::fromString(encoding, value)) {
        return "INVALID";
    }
    return encoding.c_str() + sizeof("AUDIO_FORMAT");
}

template <>
int32_t lookup<INPUT_FLAG>(const std::string &inputFlag)
{
    return int32FromFlags<InputFlagTraits>(inputFlag);
}

template <>
std::string lookup<INPUT_FLAG>(const std::string &inputFlag)
{
    return stringFromFlags<InputFlagTraits>(inputFlag, sizeof("AUDIO_INPUT_FLAG"));
}

template <>
int32_t lookup<OUTPUT_FLAG>(const std::string &outputFlag)
{
    return int32FromFlags<OutputFlagTraits>(outputFlag);
}

template <>
std::string lookup<OUTPUT_FLAG>(const std::string &outputFlag)
{
    return stringFromFlags<OutputFlagTraits>(outputFlag, sizeof("AUDIO_OUTPUT_FLAG"));
}

template <>
int32_t lookup<SOURCE_TYPE>(const std::string &sourceType)
{
    SourceTraits::Type value;
    if (!TypeConverter<SourceTraits>::fromString(sourceType, value)) {
        value = AUDIO_SOURCE_DEFAULT;
    }
    return (int32_t)value;
}

template <>
std::string lookup<SOURCE_TYPE>(const std::string &sourceType)
{
    SourceTraits::Type value;
    if (!TypeConverter<SourceTraits>::fromString(sourceType, value)) {
        return "DEFAULT";
    }
    return sourceType.c_str() + sizeof("AUDIO_SOURCE");
}

template <>
int32_t lookup<STREAM_TYPE>(const std::string &streamType)
{
    StreamTraits::Type value;
    if (!TypeConverter<StreamTraits>::fromString(streamType, value)) {
        value = AUDIO_STREAM_DEFAULT;
    }
    return (int32_t)value;
}

template <>
std::string lookup<STREAM_TYPE>(const std::string &streamType)
{
    StreamTraits::Type value;
    if (!TypeConverter<StreamTraits>::fromString(streamType, value)) {
        return "DEFAULT";
    }
    return streamType.c_str() + sizeof("AUDIO_STREAM");
}

template <>
int32_t lookup<USAGE>(const std::string &usage)
{
    UsageTraits::Type value;
    if (!TypeConverter<UsageTraits>::fromString(usage, value)) {
        value = AUDIO_USAGE_UNKNOWN;
    }
    return (int32_t)value;
}

template <>
std::string lookup<USAGE>(const std::string &usage)
{
    UsageTraits::Type value;
    if (!TypeConverter<UsageTraits>::fromString(usage, value)) {
        return "UNKNOWN";
    }
    return usage.c_str() + sizeof("AUDIO_USAGE");
}

template <>
int64_t lookup<INPUT_DEVICE>(const std::string &inputDevice)
{
    auto& map = getAudioDeviceInMap();
    auto it = map.find(inputDevice);
    if (it == map.end()) {
        return 0;
    }
    return it->second;
}

template <>
std::string lookup<INPUT_DEVICE>(const std::string &inputDevice)
{
    auto& map = getAudioDeviceInMap();
    auto it = map.find(inputDevice);
    if (it == map.end()) {
        return "NONE";
    }
    return inputDevice.c_str() + sizeof("AUDIO_DEVICE_IN");
}

template <>
int64_t lookup<OUTPUT_DEVICE>(const std::string &outputDevice)
{
    auto& map = getAudioDeviceOutMap();
    auto it = map.find(outputDevice);
    if (it == map.end()) {
        return 0; // nothing
    }
    return it->second;
}

template <>
std::string lookup<OUTPUT_DEVICE>(const std::string &outputDevice)
{
    auto& map = getAudioDeviceOutMap();
    auto it = map.find(outputDevice);
    if (it == map.end()) {
        return "NONE";
    }
    return outputDevice.c_str() + sizeof("AUDIO_DEVICE_OUT");
}

template <>
int32_t lookup<CALLER_NAME>(const std::string &callerName)
{
    auto& map = getCallerNameMap();
    auto it = map.find(callerName);
    if (it == map.end()) {
        return 7;      // return unknown
    }
    return it->second;
}

template <>
std::string lookup<CALLER_NAME>(const std::string &callerName)
{
    auto& map = getCallerNameMap();
    auto it = map.find(callerName);
    if (it == map.end()) {
        return "unknown";
    }
    return callerName;
}

template <>
int32_t lookup<THREAD_TYPE>(const std::string &threadType)
{
    auto& map = getThreadTypeMap();
    auto it = map.find(threadType);
    if (it == map.end()) {
        return -1; // note this as an illegal thread value as we don't have unknown here.
    }
    return it->second;
}

template <>
std::string lookup<THREAD_TYPE>(const std::string &threadType)
{
    auto& map = getThreadTypeMap();
    auto it = map.find(threadType);
    if (it == map.end()) {
        return "UNKNOWN";
    }
    return threadType;
}

bool isInputThreadType(const std::string &threadType)
{
    return threadType == "RECORD" || threadType == "MMAP_CAPTURE";
}

} // namespace android::mediametrics::types