#pragma once
#include <string>
#include <variant>
#include <vector>
#include "classes/java_classes.hpp"
#include "utils/valueObfuscation.h"

enum {
    COMBAT_CAT,
    /*RENDER_CAT,
    PLAYER_CAT,
    HUD_CAT,
    MISC_CAT,*/
    INVISIBLE_CAT
};

struct BoolSetting { std::string name; bool& ref; };
struct FloatSetting { std::string name; float& ref; float min, max; };
struct IntSetting { std::string name; int& ref; int   min, max; };
struct BindSetting { std::string name; int& ref; int   min, max; };
using Setting = std::variant<BoolSetting, FloatSetting, IntSetting, BindSetting>;

class i_module {
public:
    i_module(int category, std::string name = "", std::string description = "") : name(name), description(description), category(category) {}

    virtual ~i_module() = default;

    int     get_category() const { return category; }
    std::string get_name() const { return name; }

    bool is_enabled() const { return enabled; }
    void set_enabled(bool e) { enabled = e; }

    virtual void run();

    std::atomic<bool> enabled = false;
    int key_bind = 0x0;
    int category = INVISIBLE_CAT;
    std::vector<Setting> settings;

private:
    std::string name;
    std::string description;
};

class aimassist : public i_module {
public:
    aimassist() : i_module(COMBAT_CAT, XOR_STR("AimAssist"), XOR_STR(" it's omagad")) {
        settings.push_back(FloatSetting{ XOR_STR("Distance"), maxDistance, 1.f, 10.f });
        settings.push_back(FloatSetting{ XOR_STR("Angle"), maxAngle, 30.f, 360.f });
        settings.push_back(FloatSetting{ XOR_STR("Speed X"), multiYaw, 0.f, 4.f });
        settings.push_back(BoolSetting{ XOR_STR("Enable Y"), usePitch });
        settings.push_back(FloatSetting{ XOR_STR("Speed Y"), multiPitch, 0.f, 4.f });
    }

    c_entity prev_selected_target;
    bool usePitch = true;
    float maxDistance{ 4.0f };
    
    float prev_yaw_step = 0.0;
    float prev_pitch_step{ 0.0f };

    float maxAngle{ 70.f };
    float multiYaw{ 2.0f };
    float multiPitch{ 0.5f };
    void run();
};

class triggerbot : public i_module {
public:
    triggerbot() : i_module(COMBAT_CAT, XOR_STR("Triggerbot"), XOR_STR("aiaming just")) {
        settings.push_back(IntSetting{ XOR_STR("Randomize"), randomFactorMs, 0, 100 });
        settings.push_back(FloatSetting{ XOR_STR("Distance"), maxDistance, 1.f, 4.f });
        settings.push_back(BoolSetting{ XOR_STR("Mobs"), attackMobs });
        settings.push_back(BoolSetting{ XOR_STR("Players"), attackPlayers });
        settings.push_back(BoolSetting{ XOR_STR("Invisibles"), attackInvisibles });
        settings.push_back(BoolSetting{ XOR_STR("OnlyCrits"), onlyCrits });
    }

    int randomFactorMs{ 70 };
    float maxDistance{ 4.f };
    bool attackMobs{ false };
    bool attackPlayers{ true };
    bool attackInvisibles{ false };
    bool onlyCrits{ false };
    bool check_entity(c_entity& entity);
    void run();
};


extern std::vector<std::unique_ptr<i_module>> cheat_modules;