#pragma once
#include <windows.h>
#include <string>
#include <random>

#include "json.hpp"
#include "jni.h"

using json = nlohmann::json;

namespace cheat {
	inline HMODULE main_module;
	inline HWND window = nullptr;

	struct Version
	{
		std::string name{};
		std::string mappings_laby_text;
		std::string mappings_fabric_text;
		enum
		{
			UNDEFINED,
			MAJOR_1_7_10,
			MAJOR_1_8_9,
			MAJOR_1_12,
			MAJOR_1_16_5,
			MAJOR_1_17,
			MAJOR_1_18,
			MAJOR_1_19,
			MAJOR_1_20,
			MAJOR_1_21_1,
			MAJOR_1_21_4
		} type = UNDEFINED;
	};
	extern Version versions[];
	inline Version version{};
	inline json mapp;

	inline JavaVM* jvm = nullptr;
	inline JNIEnv* jni = nullptr;

	inline bool is_running = true;
	inline bool is_hiden = false;
	inline bool is_laby = false;

	inline bool temp_var_1 = false;
	inline bool temp_var_2 = false;
	inline bool temp_var_3 = false;

	inline static std::random_device rd{};
	inline static std::mt19937 gen{ rd() };

	//findClass variables//////

	inline jmethodID findclass_md = nullptr;
	inline jobject classloader_obj = nullptr;

	///////////////////////////

	jclass find_cls(const char*);
	jclass find_cls(std::string);
	bool init_findcls();

	std::string get_obf_mid(
		const json& root,
		const std::string& class_name,
		const std::optional<std::string>& method_name
	);

	std::string get_obf_fid(
		const json& root,
		const std::string& class_name,
		const std::optional<std::string>& method_name
	);

	std::string get_sig_mid(
		const json& root,
		const std::string& class_name,
		const std::string& method_name
	);

	std::string get_sig_fid(
		const json& root,
		const std::string& class_name,
		const std::string& method_name
	);

	void init(HMODULE main_module);
	void get_laby();
};