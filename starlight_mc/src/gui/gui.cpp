#include "imgui/imgui.h"
#include <variant>
#include "options.h"
#include <string>
#include <Windows.h>
#include "utils/valueObfuscation.h"
#include "cheat.hpp"
#include "modules/modules.hpp"
#include "rubik.hpp"

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...)->overloaded<Ts...>;

void setImguiStyle() {
    auto& colors = ImGui::GetStyle().Colors;

    //colors[ImGuiCol_ResizeGrip] = ImColor(0, 0, 0, 0);
    //colors[ImGuiCol_ResizeGripActive] = ImColor(0, 0, 0, 0);
    //colors[ImGuiCol_ResizeGripHovered] = ImColor(0, 0, 0, 0);

    //colors[ImGuiCol_CheckMark] = ImColor(0, 0, 0, 255);

    //colors[ImGuiCol_FrameBg] = ImColor(255, 255, 255);
    //colors[ImGuiCol_FrameBgActive] = ImColor(255, 255, 255);
    //colors[ImGuiCol_FrameBgHovered] = ImColor(255, 255, 255);

    //colors[ImGuiCol_PopupBg] = ImColor(255, 255, 255, 255);
    colors[ImGuiCol_ChildBg] = ImColor(12, 15, 26, 255);
    colors[ImGuiCol_WindowBg] = ImColor(16, 24, 32, 0);
    colors[ImGuiCol_ButtonHovered] = ImColor(100, 100, 100, 50);
    colors[ImGuiCol_Button] = ImColor(25, 26, 40, 255);
    colors[ImGuiCol_ButtonActive] = ImColor(31, 32, 48, 255);
    colors[ImGuiCol_SliderGrab] = ImColor(95, 100, 189, 255);
    colors[ImGuiCol_CheckMark] = ImColor(95, 100, 189, 255);
    colors[ImGuiCol_FrameBg] = ImColor(25, 26, 40, 255);
    colors[ImGuiCol_FrameBgHovered] = ImColor(31, 32, 48, 255);
    colors[ImGuiCol_FrameBgActive] = ImColor(31, 32, 48, 255);

    //colors[ImGuiCol_TitleBg] = ImColor(16, 24, 32, 255);
    //colors[ImGuiCol_TitleBgActive] = ImColor(16, 24, 32, 255);
    //colors[ImGuiCol_TitleBgCollapsed] = ImColor(16, 24, 32, 255);

    ImGuiStyle& style = ImGui::GetStyle();

    style.WindowBorderSize = 0.0f;
    style.ChildBorderSize = 0.0f;
    style.ChildRounding = 16.0f;
    style.FramePadding = ImVec2(0, 0);
    style.WindowPadding = ImVec2(0, 0);
    style.ItemSpacing = ImVec2(0, 0);
    style.WindowRounding = 0.f;
    style.FrameRounding = 8.0f;
    //style.GrabMinSize = 9.f;
    //style.GrabRounding = 100.f;
}

inline ImFont* iconsFont = nullptr;
inline ImFont* largeFont = nullptr;

void setupFonts() {
    static const ImWchar iconRanges[]{ ICON_MIN_FA, ICON_MAX_FA, 0 };

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.LogFilename = nullptr;

    static const ImWchar* glyphRanges = io.Fonts->GetGlyphRangesCyrillic();

    ImFont* fontLarge = io.Fonts->AddFontFromMemoryTTF((void*)custom_font, sizeof(custom_font), 19.f, nullptr, glyphRanges);

    largeFont = io.Fonts->AddFontFromMemoryTTF((void*)custom_font, sizeof(custom_font), 30.f);

    io.Fonts->AddFontFromMemoryTTF((void*)custom_font, sizeof(custom_font), 19.f);

    ImFontConfig iconsConfig;

    iconsConfig.MergeMode = true;
    iconsConfig.PixelSnapH = true;
    iconsConfig.OversampleH = 3;
    iconsConfig.OversampleV = 3;

    iconsFont = io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 22.0f, &iconsConfig, iconRanges);
}

i_module* waiting_for_rebind = nullptr;

void moduleToggle(std::unique_ptr<i_module>& mod_ptr, const ImVec2& buttonSize)
{
    ImGui::PushID(mod_ptr->get_name().c_str());
    ImGui::BeginGroup();

    float settingsHeight = 0.0f;
    const float rowH = 30.0f;
    const float paddingV = 10.0f;
    settingsHeight = paddingV * 2 + mod_ptr->settings.size() * rowH;

    ImVec2 totalSize = { buttonSize.x, buttonSize.y + settingsHeight };
    ImGui::InvisibleButton(XOR_STR("##module_item"), totalSize);

    ImVec2 pos = ImGui::GetItemRectMin();
    pos.x += 5.f;
    auto* drawList = ImGui::GetWindowDrawList();

    drawList->AddRectFilled(
        pos,
        ImVec2(pos.x + totalSize.x, pos.y + totalSize.y),
        IM_COL32(25, 26, 40, 255),
        16.0f
    );
    drawList->AddRect(
        pos,
        ImVec2(pos.x + totalSize.x, pos.y + totalSize.y),
        IM_COL32(31, 32, 48, 255),
        16.0f,
        true,
        2.f
    );

    float padding = 8.0f;
    ImVec2 textPos = {
        pos.x + padding,
        pos.y + (buttonSize.y - ImGui::GetFontSize()) * 0.5f
    };
    drawList->AddText(textPos, ImGui::GetColorU32(ImGuiCol_Text), mod_ptr->get_name().c_str());

    float boxSize = buttonSize.y * 0.6f;
    ImVec2 boxMin = {
        pos.x + buttonSize.x - boxSize - padding,
        pos.y + (buttonSize.y - boxSize) * 0.5f
    };
    ImVec2 boxMax = { boxMin.x + boxSize, boxMin.y + boxSize };
    drawList->AddRect(boxMin, boxMax, ImGui::GetColorU32(ImGuiCol_Border), 2.0f);
    if (mod_ptr->enabled)
        drawList->AddRectFilled(boxMin, boxMax, IM_COL32(95, 100, 189, 255), 4.0f);

    if (ImGui::IsItemClicked())
        mod_ptr->enabled = !mod_ptr->enabled;

    padding = 2.f;

    ImGui::SetCursorScreenPos({ pos.x + padding, pos.y + buttonSize.y + padding });
    ImGui::BeginChild(XOR_STR("settings"),
        { buttonSize.x - 2 * padding, settingsHeight - 2 * padding },
        true
    );
    ImGui::Dummy({ 0, 10.f });
    ImGui::Indent(5.f);

    std::string full_label = XOR_STR("  Key bind: ");
    full_label += ImGui::GetKeyName(static_cast<ImGuiKey>(mod_ptr->key_bind));
    full_label += XOR_STR("  ");

    if (waiting_for_rebind == mod_ptr.get()) {
        full_label = XOR_STR("  Press key...  ");

        for (int key = 0; key < ImGuiKey_COUNT; ++key)
        {
            if (ImGui::IsKeyPressed((ImGuiKey)key, false))
            {
                mod_ptr->key_bind = key;
                waiting_for_rebind = nullptr;
                break;
            }
        }
    }

    if (ImGui::Button(full_label.c_str())) waiting_for_rebind = mod_ptr.get();

    ImGui::Dummy({ 0,10 });
    for (auto& s : mod_ptr->settings)
    {
        std::visit(overloaded{
            [&](const BoolSetting& b) {
                ImGui::Checkbox(b.name.c_str(), &b.ref);
            },
            [&](const FloatSetting& f) {
                ImGui::SliderFloat(f.name.c_str(), &f.ref, f.min, f.max);
            },
            [&](const BindSetting& f) {

            },
            [&](const IntSetting& i) {
                ImGui::SliderInt(i.name.c_str(), &i.ref, i.min, i.max);
            }
            }, s);
        ImGui::Dummy({ 0,5 });
    }

    ImGui::EndChild();

    ImGui::EndGroup();
    ImGui::PopID();
}

ImVec2 menuSize(370, 440);
ImVec2 moduleSize(290, 35);
ImVec2 paddings(0.f, 16.f);
ImVec2 category_spacing(0.f, 6.f);
float leftMargin = 15.f;
ImVec2 buttons_spacing(0, 5.0f);

bool waitingForTriggerbotKey = false;
bool waitingForMenuKey = false;

bool keyPressed = false;

short current_category = COMBAT_CAT;

void renderGui()
{
    const ImVec2 winSize = { 600, 400 };
    ImVec2 viewportSize = ImGui::GetMainViewport()->Size;
    ImVec2 winPos = {
        (viewportSize.x - winSize.x) * 0.5f,
        (viewportSize.y - winSize.y) * 0.5f
    };

    ImGui::SetNextWindowPos(winPos, ImGuiCond_Always);
    ImGui::SetNextWindowSize(winSize, ImGuiCond_Always);
    ImGui::Begin("#mm", nullptr,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoBringToFrontOnFocus
    );

    // ---- ПРАВАЯ ПАНЕЛЬ ----
    ImVec2 rightPanelSize = ImGui::GetContentRegionAvail();
    ImVec2 rightPanelPos = ImGui::GetCursorScreenPos();
    ImGui::SetCursorScreenPos(rightPanelPos);

    ImGui::BeginChild("#rp", rightPanelSize, true);

    ImGui::Dummy(ImVec2(0, 5.f));
    ImGui::SeparatorText(XOR_STR("Combat"));
    ImGui::Dummy(ImVec2(0, 8.f));

    ImVec2 startPos = ImGui::GetCursorScreenPos();
    float spacing = 8.f;  // отступ между модулями
    int idx = 0;              // номер модуля в рамках текущей категории

    for (auto& mod_ptr : cheat_modules)
    {
        if (mod_ptr->get_category() != current_category)
            continue;

        int row = idx / 2;
        bool isRight = (idx % 2 == 1);

        float x = startPos.x + (moduleSize.x + spacing) * (isRight ? 1 : 0);
        float y = startPos.y + (moduleSize.y + spacing) * row;

        ImGui::SetCursorScreenPos({ x, y });
        moduleToggle(mod_ptr, moduleSize);

        idx++;
    }

    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + ImGui::GetContentRegionAvail().y - 40.0f);

    // Центрирование кнопки
    float buttonWidth = 120.0f;
    float buttonHeight = 30.0f;
    float buttonX = (ImGui::GetContentRegionAvail().x - buttonWidth) * 0.5f;
    ImGui::SetCursorPosX(buttonX);

    if (ImGui::Button(XOR_STR("Hide"), ImVec2(buttonWidth, buttonHeight)))
    {
        cheat::is_hiden = true;
        options::menu::isMenuVisible = false;
    }

    ImGui::SetCursorPosX(buttonX + buttonWidth + 10.f);

    ImGui::SameLine();

    ImGui::Indent(10.0f);
    ImGui::SetNextItemWidth(90.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(8.0f, 0.0f));
    ImGui::InputText(" secret", options::menu::hide_word, 10);
    ImGui::PopStyleVar();
    ImGui::Unindent(10.0f);

    ImGui::EndChild();

    ImGui::End();
}

void renderMisc() {
    /*for (auto& mod_ptr : cheat_modules) {
        if (mod_ptr->get_category() == HUD_CAT) mod_ptr->run();
    }*/
}

void renderAll() {
    if (options::menu::isMenuVisible) {
        renderGui(); 
    }
    //renderMisc();
}