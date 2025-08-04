#include "modules.hpp"

void i_module::run()
{
}

 std::vector<std::unique_ptr<i_module>> cheat_modules = []() {
    std::vector<std::unique_ptr<i_module>> v;
    v.emplace_back(std::make_unique<aimassist>());
    v.emplace_back(std::make_unique<triggerbot>());
    //v.emplace_back(std::make_unique<obs_bypass>());
    return v;
}();