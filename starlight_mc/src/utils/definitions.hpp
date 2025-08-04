#pragma once

#include <cstdint>
#include <cstddef>
#include "valueObfuscation.h"

struct sectionInfo {
	util::encrypted_ptr<uint8_t> address;
	size_t size;
};

struct hwidInfo {
	DWORD hdd_serial;
	std::string baseboard_version;
	std::string baseboard_serial;
};