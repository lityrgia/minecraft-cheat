#include "modules.hpp"
#include "imgui/imgui.h"

//void watermark::run() {
//    if (!enabled) return;
//    ImDrawList* draw_list = ImGui::GetBackgroundDrawList();
//
//    // Размеры и отступ
//    const float width = 40.0f;
//    const float height = 40.0f;
//    const float padding = 5.0f;
//    ImVec2 p_min = ImVec2(padding, padding);
//    ImVec2 p_max = ImVec2(p_min.x + width, p_min.y + height);
//
//    // Цвета
//    ImU32 rect_col = IM_COL32(10, 10, 80, 180);   // фон
//    ImU32 border_col = IM_COL32(255, 255, 255, 100); // полупрозрачная рамка
//    ImU32 text_col = IM_COL32(255, 215, 0, 255);   // текст
//
//    // Радиус скругления
//    const float rounding = 2.0f;
//
//    // Рисуем заполненный прямоугольник с радиусом
//    //draw_list->AddRectFilled(p_min, p_max, rect_col, rounding);
//}
