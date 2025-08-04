#pragma once

#include <optional>
#include "smbios.h"
#include "definitions.hpp"

using std::cout, std::vector;
using namespace smbios;

extern "C" {
	IDirect3D9* Direct3DCreate9(
		UINT SDKVersion
	);
}

std::optional<hwidInfo> getInfoHwid() {
	DWORD hdd_serial{};
	hwidInfo hwid_info{};

	if (GetVolumeInformationA("C://", NULL, NULL, &hdd_serial, NULL, NULL, NULL, NULL) == 0) {
		std::cerr << "Error in GetVolumeInformation: " << GetLastError() << "\n";
		return std::nullopt;
	}
	hwid_info.hdd_serial = hdd_serial;

	DWORD smbios_data_size = GetSystemFirmwareTable('RSMB', 0, nullptr, 0);
	if (!smbios_data_size) {
		std::cerr << "Error getting SMBIOS size\n";
		return std::nullopt;
	}

	auto smbios_data_buffer = std::make_unique<BYTE[]>(smbios_data_size);
	DWORD read_size = GetSystemFirmwareTable('RSMB', 0, smbios_data_buffer.get(), smbios_data_size);
	if (!read_size) {
		std::cerr << "Error reading SMBIOS data\n";
		return std::nullopt;
	}

	auto* smbios_data = reinterpret_cast<RawSMBIOSData*>(smbios_data_buffer.get());
	BYTE* b_ = smbios_data->SMBIOSTableData;
	BYTE* table_end = b_ + smbios_data->Length;

	while (b_ < table_end) {
		dmi_header* header = reinterpret_cast<dmi_header*>(b_);

		if (header->length < sizeof(dmi_header)) {
			std::cerr << "Invalid SMBIOS header length\n";
			break;
		}

		if (header->type == dmi_entry_type::DMI_ENTRY_BASEBOARD) {
			if (header->length < 8) {
				std::cerr << "Baseboard entry too short\n";
				break;
			}

			BYTE* data = reinterpret_cast<BYTE*>(header);
			BYTE version_index = data[7];
			BYTE serial_index = data[6];

			hwid_info.baseboard_serial = dmi_string(header, serial_index);
			hwid_info.baseboard_version = dmi_string(header, version_index);
			break; // если нужно только одно совпадение
		}

		// ѕропускаем основную структуру
		b_ += header->length;

		// ѕропускаем строковую секцию (ищем \0\0)
		while (b_ < table_end - 1 && !(b_[0] == 0 && b_[1] == 0)) {
			++b_;
		}
		b_ += 2; // пропускаем \0\0
	}

	return hwid_info;
}
