#define IMGUI_DISABLE_DEBUG_TOOLS
#define IMGUI_DISABLE_METRICS_WINDOW
#define IMGUI_DISABLE_DEBUG_LOG

#include <cstdio>
#include <thread>
#include <unordered_map>
#include <iostream>
#include <windows.h>

#include "utils/process.hpp"
#include "utils/macros.h"
#include "utils/definitions.hpp"
#include "cheat.hpp"
#include "mappings/mappings.hpp"
#include "utils/valueObfuscation.h"
#include "utils/Logger.h"
#include "utils/hwid_checker.h"
#include "utils/fnv1a.h"
#include "utils/tea_crypt.hpp"

#include "modules/modules.hpp"
#include "classes/java_classes.hpp"
#include "classes/references.hpp"

#include "gui/imguiHook.h"
#include "gui/gui.h"
#include "gui/options.h"

#include "jvmti.h"
using GetCreatedJavaVMs_t = jint(*)(JavaVM** vmBuf, jsize bufLen, jsize* nVMs);

extern cheat::Version cheat::versions[] =
{
	{XOR_STR("1.16"), Mappings::mappings_forge_1_16_5.dec(), Mappings::mappings_fabric_1_16_5.dec(), Version::MAJOR_1_16_5},
	{XOR_STR("1.17"), Mappings::mappings_laby_1_17.dec(), Mappings::mappings_fabric_1_16_5.dec(), Version::MAJOR_1_17},
	{XOR_STR("1.18"), Mappings::mappings_laby_1_18.dec(), Mappings::mappings_fabric_1_16_5.dec(), Version::MAJOR_1_18},
	{XOR_STR("1.19"), Mappings::mappings_laby_1_19.dec(), Mappings::mappings_fabric_1_16_5.dec(), Version::MAJOR_1_19},
	{XOR_STR("1.20"), Mappings::mappings_laby_1_20.dec(), Mappings::mappings_fabric_1_16_5.dec(), Version::MAJOR_1_20},
	{XOR_STR("1.21.4"), Mappings::mappings_laby_1_21_4.dec(), Mappings::mappings_fabric_1_21_4.dec(), Version::MAJOR_1_21_4},
};

void cheat::get_laby() {
	auto current_window = process::getCurrentWindow();
	is_laby = process::getWindowName(current_window).find(XOR_STR("LabyMod")) != std::string::npos;
}

static HWND g_hConsole = nullptr;
static FILE* g_stdout = nullptr;
static FILE* g_stderr = nullptr;
static FILE* g_stdin = nullptr;

void create_console() {
	if (!g_hConsole) {
		AllocConsole();
		g_hConsole = GetConsoleWindow();
		freopen_s(&g_stdout, "CONOUT$", "w", stdout);
		freopen_s(&g_stderr, "CONOUT$", "w", stderr);
		freopen_s(&g_stdin, "CONIN$", "r", stdin);
	}
	ShowWindow(g_hConsole, SW_SHOW);
}

void close_console() {
	if (g_hConsole) {
		ShowWindow(g_hConsole, SW_HIDE);
		FreeConsole();
	}
}

std::string secret_word_buffer;

static void check_secret_word() {
	if (options::menu::hide_word == nullptr || options::menu::hide_word[0] == '\0') {
		return;
	}

	static size_t last_target_len = 0;
	size_t targetLen = std::strlen(options::menu::hide_word);

	if (targetLen != last_target_len) {
		secret_word_buffer.clear();
		last_target_len = targetLen;
	}

	for (int vk = 'A'; vk <= 'Z'; ++vk) {
		if (GetAsyncKeyState(vk) & 0x8000) {
			bool shift = (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;
			bool caps = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
			bool isUpper = shift ^ caps;

			char ch = static_cast<char>(vk);
			if (!isUpper) ch = static_cast<char>(tolower(ch));

			secret_word_buffer.push_back(ch);

			if (secret_word_buffer.size() > targetLen) {
				secret_word_buffer.erase(0, secret_word_buffer.size() - targetLen);
			}

			if (secret_word_buffer.size() == targetLen &&
				secret_word_buffer == options::menu::hide_word) {
				options::menu::isMenuVisible = true;
				cheat::is_hiden = false;
				secret_word_buffer.clear();
				break;
			}

			while (GetAsyncKeyState(vk) & 0x8000) {
				Sleep(5);
			}
		}
	}
}


void main_loop() {
	c_minecraft& mc = c_minecraft::instance();
	c_player& player = c_player::instance();
	c_world& world = c_world::instance();
	c_timer& timer = c_timer::instance();
	
	if (!refs::init()) {
		printf("Failed to init refs\n");
		return;
	}
	mc.get_mc();
	timer.obj = mc.get_timer();

	static std::unordered_map<int, bool> prevKeyState;
	while (cheat::is_running) {
		if (cheat::is_hiden) {
			check_secret_word();
			continue;
		}

		if ((player.obj = mc.get_localPlayer()) == nullptr || (world.obj = mc.get_world()) == nullptr) {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			continue;
		}
		world.get_players();

		for (auto& mod_ptr : cheat_modules) {
			if(cheat::temp_var_3) mod_ptr->run();

			int vk = mod_ptr->key_bind;
			if (vk == 0) continue;

			bool downNow = (GetAsyncKeyState(vk) & 0x8000) != 0;
			bool downPrev = prevKeyState[vk];

			if (downNow && !downPrev) {
				mod_ptr->enabled = !mod_ptr->enabled;
			}

			prevKeyState[vk] = downNow;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	if (cheat::jvm != nullptr) cheat::jvm->DetachCurrentThread();
	cheat::mapp.clear();
	ImGuiHook::Unload();
}

void cheat::init(HMODULE main_module) {
	cheat::main_module = main_module;

	create_console();
	printf(XOR_STR("---LEGIT DLC---\n"));

	/*const auto hwid_info = getInfoHwid();
	if (!hwid_info) {
		Logger::log(Logger::Type::Error, XOR_STR("Failed to retrieve HWID\n"));
		std::this_thread::sleep_for(std::chrono::seconds(5));
		ExitProcess(0);
		return;
	}

	uint32_t key[4] = {
		static_cast<uint32_t>(hwid_info->hdd_serial),
		static_cast<uint32_t>(FNV1A(hwid_info->baseboard_serial.c_str())),
		static_cast<uint32_t>(FNV1A(hwid_info->baseboard_version.c_str())),
		(uint32_t)0xCAFEBABE
	};

	uint64_t cipher_key =
		(static_cast<uint64_t>(XOR_32(0x12345678)) << 32) |
		static_cast<uint64_t>(XOR_32(0xDEAFBEEF));

	const auto encrypted_key = tea_encrypt(cipher_key, key);*/

	////std::cout << "your id: " << encrypted_key << '\n';

	//if ((uint32_t)encrypted_key == XOR_32((uint32_t)ID_KEY)) {
	//	Logger::log(Logger::Type::Info, XOR_STR("Succesfly checked ID\n"));
	//	temp_var_1 = true;
	//} //ID CHECKER

	//if (!temp_var_1) {
	//	Logger::log(Logger::Type::Error, XOR_STR("Wrong ID\n"));
	//	std::this_thread::sleep_for(std::chrono::seconds(5));
	//	ExitProcess(0);
	//	return;
	//}

	const auto h_jvm = GetModuleHandleA(XOR_STR("jvm.dll"));
	if (h_jvm == nullptr)
	{
		Logger::log(Logger::Type::Error, XOR_STR("Failed to retrieve handle for jvm.dll\n"));
		std::this_thread::sleep_for(std::chrono::seconds(5));
		ExitProcess(0);
		return;
	}

	const auto GetCreatedJavaVMs = reinterpret_cast<GetCreatedJavaVMs_t>(GetProcAddress(
		h_jvm, XOR_STR("JNI_GetCreatedJavaVMs")));

	GetCreatedJavaVMs(&cheat::jvm, 1, nullptr);
	if (cheat::jvm == nullptr) {
		Logger::log(Logger::Type::Error, XOR_STR("Failed to attach JVM\n"));
		std::this_thread::sleep_for(std::chrono::seconds(5));
		ExitProcess(0);
		return;
	}
	Logger::log(Logger::Type::Info, XOR_STR("Attached JVM\n"));

	jvm->AttachCurrentThread((void**)&cheat::jni, nullptr);

	if (cheat::jni == nullptr) {
		Logger::log(Logger::Type::Error, XOR_STR("Failed to attach JNI\n"));
		std::this_thread::sleep_for(std::chrono::seconds(5));
		ExitProcess(0);
		return;
	}
	Logger::log(Logger::Type::Info, XOR_STR("Attached JNI\n"));

	bool foundVersion = false;
	cheat::window = process::getCurrentWindow();
	std::string windowName = process::getWindowName(window);
	for (Version v : versions)
	{
		if (windowName.find(v.name) != std::string::npos)
		{
			foundVersion = true;
			cheat::version = v;
			Logger::log(Logger::Type::Info, XOR_FORMAT("Found version %s\n", v.name.c_str()));
			break;
		}
	}

	if (!foundVersion) {
		Logger::log(Logger::Type::Error, XOR_STR("Failed to determine version\n"));
		std::this_thread::sleep_for(std::chrono::seconds(5));
		ExitProcess(0);
		return;
	}
	else {
		if (!init_findcls()) {
			Logger::log(Logger::Type::Error, XOR_STR("Failed to init findcls\n"));
			std::this_thread::sleep_for(std::chrono::seconds(5));
			ExitProcess(0);
			return;
		}

		get_laby();
		if (cheat::is_laby) Logger::log(Logger::Type::Info, XOR_STR("Using LabyMod FABRIC mappings\n"));
		else Logger::log(Logger::Type::Info, XOR_STR("Using Default FABRIC mappings\n"));

		try {
			std::string str_mappings_text;
			if (cheat::is_laby) {
				str_mappings_text = cheat::version.mappings_laby_text;
			}
			else {
				str_mappings_text = cheat::version.mappings_fabric_text;
			}
			cheat::mapp = json::parse(str_mappings_text);
		}
		catch (const std::exception& e) {
			Logger::log(Logger::Type::Error, XOR_STR("Mappings parse error\n"));
			std::this_thread::sleep_for(std::chrono::seconds(5));
			ExitProcess(0);
			return;
		}
		Logger::log(Logger::Type::Info, XOR_STR("Initialized mappings\n"));
	}

	/*if ((uint32_t)encrypted_key == XOR_32((uint32_t)ID_KEY)) {
		temp_var_2 = true;
	}
	if (temp_var_2)*/ temp_var_3 = true; //ID CHECKER

	std::this_thread::sleep_for(std::chrono::seconds(3));
	close_console();

	ImGuiHook::Load(renderAll);

	main_loop();
}

inline static std::unordered_map<std::string, jclass> class_cache = [] {
	std::unordered_map<std::string, jclass> m;
	m.reserve(64);
	return m;
}();

jclass cheat::find_cls(const char* class_name) {
	std::string class_name_format(class_name);
	std::replace(class_name_format.begin(), class_name_format.end(), '/', '.');

	jstring jname = jni->NewStringUTF(class_name_format.c_str());
	if (!jname) {
		return nullptr;
	}

	jclass cls = reinterpret_cast<jclass>(jni->CallObjectMethod(classloader_obj, findclass_md, jname));

	jni->DeleteLocalRef(jname);

	return cls;
}

jclass cheat::find_cls(std::string class_name) {
	return find_cls(class_name.c_str());
}

std::string get_obf(
	const json& root,
	const std::string& class_name,
	const std::optional<std::string>& method_name,
	bool isMethod
) {
	if (!root.contains(class_name)) return "";
	const auto& class_info = root[class_name];

	if (!method_name.has_value()) {
		if (class_info.contains(XOR_STR("obfuscated"))) {
			return class_info[XOR_STR("obfuscated")].get<std::string>();
		}
		return "";
	}

	if (!class_info.contains(XOR_STR("methods"))) return "";

	for (const auto& method : class_info[isMethod ? XOR_STR("methods") : XOR_STR("fields")]) {
		if (method.contains(XOR_STR("name")) && method[XOR_STR("name")] == *method_name) {
			if (method.contains(XOR_STR("obfuscated"))) {
				return method[XOR_STR("obfuscated")].get<std::string>();
			}
		}
	}

	return "";
}

std::string cheat::get_obf_mid(
	const json& root,
	const std::string& class_name,
	const std::optional<std::string>& method_name
) {
	return get_obf(root, class_name, method_name, true);
}

std::string cheat::get_obf_fid(
	const json& root,
	const std::string& class_name,
	const std::optional<std::string>& method_name
) {
	return get_obf(root, class_name, method_name, false);
}

std::string get_sig(
	const json& root,
	const std::string& class_name,
	const std::string& method_name,
	bool isMethod
) {
	if (!root.contains(class_name)) return "";
	const auto& class_info = root[class_name];
	if (!class_info.contains(XOR_STR("methods"))) return "";

	for (const auto& method : class_info[isMethod ? XOR_STR("methods") : XOR_STR("fields")]) {
		if (method.contains(XOR_STR("name")) && method[XOR_STR("name")] == method_name) {
			if (method.contains(XOR_STR("signature"))) {
				return method[XOR_STR("signature")].get<std::string>();
			}
		}
	}

	return "";
}

std::string cheat::get_sig_mid(
	const json& root,
	const std::string& class_name,
	const std::string& method_name
) {
	return get_sig(root, class_name, method_name, true);
}

std::string cheat::get_sig_fid(
	const json& root,
	const std::string& class_name,
	const std::string& method_name
) {
	return get_sig(root, class_name, method_name, false);
}

static bool findClsLoaderByThreads(JNIEnv* env, const char* cls_loader_name) {
	jclass threadCls = env->FindClass(XOR_STR("java/lang/Thread"));
	jmethodID allStackTracesMd = env->GetStaticMethodID(threadCls, XOR_STR("getAllStackTraces"), XOR_STR("()Ljava/util/Map;"));
	if (!allStackTracesMd) {
		printf(XOR_STR("[ERROR] Cannot get Thread.getAllStackTraces method ID\n"));
		return false;
	}
	jobject threadMap = env->CallStaticObjectMethod(threadCls, allStackTracesMd);
	if (!threadMap) {
		printf(XOR_STR("[ERROR] getAllStackTraces() returned null\n"));
		return false;
	}

	jclass mapCls = env->FindClass(XOR_STR("java/util/Map"));
	jmethodID entrySetMd = env->GetMethodID(mapCls, XOR_STR("entrySet"), XOR_STR("()Ljava/util/Set;"));
	jobject entrySet = env->CallObjectMethod(threadMap, entrySetMd);
	jclass setCls = env->FindClass(XOR_STR("java/util/Set"));
	jmethodID iteratorMd = env->GetMethodID(setCls, XOR_STR("iterator"), XOR_STR("()Ljava/util/Iterator;"));
	jobject it = env->CallObjectMethod(entrySet, iteratorMd);
	jclass itCls = env->FindClass(XOR_STR("java/util/Iterator"));
	jmethodID hasNextMd = env->GetMethodID(itCls, XOR_STR("hasNext"), XOR_STR("()Z"));
	jmethodID nextMd = env->GetMethodID(itCls, XOR_STR("next"), XOR_STR("()Ljava/lang/Object;"));

	jclass entryCls = env->FindClass(XOR_STR("java/util/Map$Entry"));
	jmethodID getKeyMd = env->GetMethodID(entryCls, XOR_STR("getKey"), XOR_STR("()Ljava/lang/Object;"));
	jmethodID getContextMd = env->GetMethodID(threadCls, XOR_STR("getContextClassLoader"), XOR_STR("()Ljava/lang/ClassLoader;"));

	jclass classCls = env->FindClass(XOR_STR("java/lang/Class"));
	jmethodID getNameMd = env->GetMethodID(classCls, XOR_STR("getName"), XOR_STR("()Ljava/lang/String;"));

	while (env->CallBooleanMethod(it, hasNextMd)) {
		jobject entry = env->CallObjectMethod(it, nextMd);
		jobject threadObj = env->CallObjectMethod(entry, getKeyMd);
		jobject loader = env->CallObjectMethod(threadObj, getContextMd);
		if (!loader) continue;

		jclass loaderCls = env->GetObjectClass(loader);
		jstring nameStr = (jstring)env->CallObjectMethod(loaderCls, getNameMd);
		const char* nameC = env->GetStringUTFChars(nameStr, nullptr);

		if (strcmp(nameC, cls_loader_name) == 0) {
			printf(XOR_STR("[INFO] Found class loader in thread %p\n"), threadObj);
			cheat::classloader_obj = env->NewGlobalRef(loader);
			env->ReleaseStringUTFChars(nameStr, nameC);
			env->DeleteLocalRef(nameStr);
			env->DeleteLocalRef(loaderCls);
			return true;
		}

		env->ReleaseStringUTFChars(nameStr, nameC);
		env->DeleteLocalRef(nameStr);
		env->DeleteLocalRef(loaderCls);
	}

	return false;
}

bool cheat::init_findcls() {
	if (findClsLoaderByThreads(cheat::jni, XOR_STR("net.fabricmc.loader.impl.launch.knot.KnotClassLoader"))
		|| findClsLoaderByThreads(cheat::jni, XOR_STR("cpw.mods.modlauncher.TransformingClassLoader"))
		|| findClsLoaderByThreads(cheat::jni, XOR_STR("net.minecraft.launchwrapper.LaunchClassLoader"))) {
		jclass knotCls = cheat::jni->GetObjectClass(cheat::classloader_obj);
		cheat::findclass_md = cheat::jni->GetMethodID(knotCls, XOR_STR("loadClass"), XOR_STR("(Ljava/lang/String;Z)Ljava/lang/Class;"));
		cheat::jni->DeleteLocalRef(knotCls);
		return cheat::findclass_md != nullptr;
	}
	return false;
}
