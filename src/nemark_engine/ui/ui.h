#pragma once

#include <string>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace Nemark {
    enum UI_STYLE_COLORS {
        LIGHT,
        DARK,
        CLASSIC
    };

    class UI {
        public:
            void initUserInterface();
            void startUserInterface();
            void endUserInterface();
            void destroyUserInterface();
            void setToDefault();

            void setStyleColors(UI_STYLE_COLORS theme);

            //ImGUI WIRE-UPS
            //Windows
            bool Begin(const char* name, bool* p_open = NULL, ImGuiWindowFlags flags = 0) { return ImGui::Begin(name, p_open, flags); }
            void End() { ImGui::End(); }

            //Child Windows
            bool BeginChild(const char* str_id, const ImVec2& size = ImVec2(0, 0), ImGuiChildFlags child_flags = 0, ImGuiWindowFlags window_flags = 0) { return ImGui::BeginChild(str_id, size, child_flags, window_flags); }
            bool BeginChild(ImGuiID id, const ImVec2& size = ImVec2(0, 0), ImGuiChildFlags child_flags = 0, ImGuiWindowFlags window_flags = 0) { return ImGui::BeginChild(id, size, child_flags, window_flags); }
            void EndChild() { ImGui::EndChild(); }

            //Window uilities
            bool IsWindowAppearing() { return ImGui::IsWindowAppearing(); }
            bool IsWindowCollapsed() { return ImGui::IsWindowCollapsed(); }
            bool IsWindowFocused(ImGuiFocusedFlags flags=0) { return ImGui::IsWindowFocused(flags); }
            bool IsWindowHovered(ImGuiHoveredFlags flags=0) { return ImGui::IsWindowHovered(flags); }
            ImDrawList* GetWindowDrawList() { return ImGui::GetWindowDrawList(); }
            float GetWindowDpiScale() { return ImGui::GetWindowDpiScale(); }
            ImVec2 GetWindowPos() { return ImGui::GetWindowPos(); }
            ImVec2 GetWindowSize() { return ImGui::GetWindowSize(); }
            float GetWindowWidtht() { return ImGui::GetWindowWidth(); }
            float GetWindowHeight() { return ImGui::GetWindowHeight(); }
            ImGuiViewport* GetWindowViewport() { return ImGui::GetWindowViewport(); };

            //Window manipulation
            void SetNextWindowPos(const ImVec2& pos, ImGuiCond cond = 0, const ImVec2& pivot = ImVec2(0, 0)) { ImGui::SetNextWindowPos(pos, cond, pivot); }
            void SetNextWindowSize(const ImVec2& size, ImGuiCond cond = 0) { ImGui::SetNextWindowSize(size, cond); }                  
            void SetNextWindowSizeConstraints(const ImVec2& size_min, const ImVec2& size_max, ImGuiSizeCallback custom_callback = NULL, void* custom_callback_data = NULL) { ImGui::SetNextWindowSizeConstraints(size_min, size_max, custom_callback, custom_callback_data); }
            void SetNextWindowContentSize(const ImVec2& size) { ImGui::SetNextWindowContentSize(size); }                          
            void SetNextWindowCollapsed(bool collapsed, ImGuiCond cond = 0) { ImGui::SetWindowCollapsed(collapsed, cond); }
            void SetNextWindowFocus() { ImGui::SetNextWindowFocus(); }
            void SetNextWindowScroll(const ImVec2& scroll);                                  
            void SetNextWindowBgAlpha(float alpha);                                          
            void SetNextWindowViewport(ImGuiID viewport_id);                                 
            void SetWindowPos(const ImVec2& pos, ImGuiCond cond = 0);                         
            void SetWindowSize(const ImVec2& size, ImGuiCond cond = 0);                       
            void SetWindowCollapsed(bool collapsed, ImGuiCond cond = 0);                     
            void SetWindowFocus();                                                           
            void SetWindowPos(const char* name, const ImVec2& pos, ImGuiCond cond = 0);      
            void SetWindowSize(const char* name, const ImVec2& size, ImGuiCond cond = 0);    
            void SetWindowCollapsed(const char* name, bool collapsed, ImGuiCond cond = 0);   
            void SetWindowFocus(const char* name);            
            
            // Windows Scrolling
            float GetScrollX() {  return ImGui::GetScrollX(); }
            float GetScrollY() {  return ImGui::GetScrollY(); }
            void SetScrollX(float scroll_x) { ImGui::SetScrollX(scroll_x); }
            void SetScrollY(float scroll_y) { ImGui::SetScrollX(scroll_y); }
            float GetScrollMaxX() {  return ImGui::GetScrollMaxX(); }
            float GetScrollMaxY() {  return ImGui::GetScrollMaxY(); }
            void SetScrollHereX(float center_x_ratio = 0.5f) { ImGui::SetScrollHereX(center_x_ratio); };
            void SetScrollHereY(float center_y_ratio = 0.5f) { ImGui::SetScrollHereY(center_y_ratio); };
            void SetScrollFromPosX(float local_x, float center_x_ratio = 0.5f) { ImGui::SetScrollFromPosX(local_x, center_x_ratio); }
            void SetScrollFromPosY(float local_y, float center_y_ratio = 0.5f) { ImGui::SetScrollFromPosY(local_y, center_y_ratio); }

            // Parameters stacks (font)
            
            // Parameters stacks (shared)

            // Parameters stacks (current window)

            // Layout cursor positioning

            //Other layout functions
            void Separator() { ImGui::Separator(); }
            void SameLine(float offset_from_start_x=0.0f, float spacing=-1.0f) { ImGui::SameLine(offset_from_start_x, spacing); }
            void NewLine() { ImGui::NewLine(); }
            void Spacing() { ImGui::Spacing(); }
            void Dummy(const ImVec2& size) { ImGui::Dummy(size); }
            void Indent(float indent_w = 0.0f) { ImGui::Indent(indent_w); }
            void Unindent(float indent_w = 0.0f) { ImGui::Unindent(indent_w); }
            void BeginGroup() { ImGui::BeginGroup(); }
            void EndGroup() { ImGui::EndGroup(); }
            void AlignTextToFramePadding() { ImGui::AlignTextToFramePadding(); }
            void GetTextLineHeight() { ImGui::GetTextLineHeight(); }
            void GetTextLineHeightWithSpacing() { ImGui::GetTextLineHeightWithSpacing(); }
            void GetFrameHeight() { ImGui::GetFrameHeight(); }
            void GetFrameHeightWithSpacing() { ImGui::GetFrameHeightWithSpacing(); }

            //Widgets: Text
            void TextUnformatted(const char* text, const char* text_end = NULL) { ImGui::TextUnformatted(text, text_end); }
            void Text(const char* text) { ImGui::Text(text); }
            void TextColored(const ImVec4& color, const char* text) { ImGui::TextColored(color, text); }
            void TextDisabled(const char* text) { ImGui::TextDisabled(text); }
            void TextWrapped(const char* text) { ImGui::TextWrapped(text); }
            void LabelText(const char* label, const char* text) { ImGui::LabelText(label, text); }
            void BulletText(const char* text) { ImGui::BulletText(text); }
            void SeparatorText(const char* label) { ImGui::SeparatorText(label); }

            //Widgets: Main
            bool Button(const char* label, const ImVec2& size = ImVec2(0, 0)) { return ImGui::Button(label, size); }
            bool SmallButton(const char* label) { return ImGui::SmallButton(label); }
            bool InvisibleButton(const char* str_id, const ImVec2& size, ImGuiButtonFlags flags = 0) { return ImGui::InvisibleButton(str_id, size, flags); }
            bool ArrowButton(const char* str_id, ImGuiDir dir) { return ImGui::ArrowButton(str_id, dir); }
            bool Checkbox(const char* label, bool* v) { return ImGui::Checkbox(label, v); }
            bool CheckboxFlags(const char* label, int* flags, int flags_value) { return ImGui::CheckboxFlags(label, flags, flags_value); }
            bool CheckboxFlags(const char* label, unsigned int* flags, unsigned int flags_value) { return ImGui::CheckboxFlags(label, flags, flags_value); }
            bool RadioButton(const char* label, bool active) { return ImGui::RadioButton(label, active); }
            bool RadioButton(const char* label, int* v, int v_button) { return ImGui::RadioButton(label, v, v_button); }
            void ProgressBar(float fraction, const ImVec2& size_arg = ImVec2(-FLT_MIN, 0), const char* overlay = NULL) { ImGui::ProgressBar(fraction, size_arg, overlay); }
            void Bullet() { ImGui::Bullet(); }
            bool TextLink(const char* label) { return ImGui::TextLink(label); }
            bool TextLinkOpenURL(const char* label, const char* url = NULL) { return ImGui::TextLinkOpenURL(label, url); }

            // Widgets: Images
            void Image(ImTextureRef tex_ref, const ImVec2& image_size, const ImVec2& uv0 = ImVec2(0, 0), const ImVec2& uv1 = ImVec2(1, 1)) { ImGui::Image(tex_ref, image_size, uv0, uv1); }
            void ImageWithBg(ImTextureRef tex_ref, const ImVec2& image_size, const ImVec2& uv0 = ImVec2(0, 0), const ImVec2& uv1 = ImVec2(1, 1), const ImVec4& bg_col = ImVec4(0, 0, 0, 0), const ImVec4& tint_col = ImVec4(1, 1, 1, 1)) { ImGui::ImageWithBg(tex_ref, image_size, uv0, uv1, bg_col, tint_col); }
            void ImageButton(const char* str_id, ImTextureRef tex_ref, const ImVec2& image_size, const ImVec2& uv0 = ImVec2(0, 0), const ImVec2& uv1 = ImVec2(1, 1), const ImVec4& bg_col = ImVec4(0, 0, 0, 0), const ImVec4& tint_col = ImVec4(1, 1, 1, 1)) { ImGui::ImageButton(str_id, tex_ref, image_size, uv0, uv1, bg_col, tint_col); }

            // Widgets: Combo Box (Dropdown)
            bool BeginCombo(const char* label, const char* preview_value, ImGuiComboFlags flags = 0) { return ImGui::BeginCombo(label, preview_value, flags); }
            void EndCombo() { ImGui::EndCombo(); }
            bool Combo(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items = -1) { return ImGui::Combo(label, current_item, items, items_count, popup_max_height_in_items); }
            bool Combo(const char* label, int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items = -1) { return ImGui::Combo(label, current_item, items_separated_by_zeros, popup_max_height_in_items); }   
            bool Combo(const char* label, int* current_item, const char* (*getter)(void* user_data, int idx), void* user_data, int items_count, int popup_max_height_in_items = -1) { return ImGui::Combo(label, current_item, getter, user_data, items_count, popup_max_height_in_items); }

            // Widgets: Drag Sliders
            bool DragFloat(const char* label, float* v, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0) { return ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, flags); }
            bool DragFloat2(const char* label, float v[2], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0) { return ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, flags); }
            bool DragFloat3(const char* label, float v[3], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0) { return ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, flags); }
            bool DragFloat4(const char* label, float v[4], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0) { return ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, flags); }
            bool DragFloatRange2(const char* label, float* v_current_min, float* v_current_max, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", const char* format_max = NULL, ImGuiSliderFlags flags = 0) { return ImGui::DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, flags); }
            bool DragInt(const char* label, int* v, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0) { return ImGui::DragInt(label, v, v_speed, v_min, v_max, format, flags); }  
            bool DragInt2(const char* label, int v[2], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0) { return ImGui::DragInt(label, v, v_speed, v_min, v_max, format, flags); }
            bool DragInt3(const char* label, int v[3], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0) { return ImGui::DragInt(label, v, v_speed, v_min, v_max, format, flags); }
            bool DragInt4(const char* label, int v[4], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0) { return ImGui::DragInt(label, v, v_speed, v_min, v_max, format, flags); }
            bool DragIntRange2(const char* label, int* v_current_min, int* v_current_max, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", const char* format_max = NULL, ImGuiSliderFlags flags = 0) { return ImGui::DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, flags); }
            bool DragScalar(const char* label, ImGuiDataType data_type, void* p_data, float v_speed = 1.0f, const void* p_min = NULL, const void* p_max = NULL, const char* format = NULL, ImGuiSliderFlags flags = 0) { return ImGui::DragScalar(label, data_type, p_data, v_speed, p_min, p_max, format, flags); }
            bool DragScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, float v_speed = 1.0f, const void* p_min = NULL, const void* p_max = NULL, const char* format = NULL, ImGuiSliderFlags flags = 0) { return ImGui::DragScalar(label, data_type, p_data, v_speed, p_min, p_max, format, flags); }

            // Widgets: Regular Sliders
            bool SliderFloat(const char* label, float* v, float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0) { return ImGui::SliderFloat(label, v, v_min, v_max, format, flags); }
            bool SliderFloat2(const char* label, float v[2], float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0) { return ImGui::SliderFloat(label, v, v_min, v_max, format, flags); }
            bool SliderFloat3(const char* label, float v[3], float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0) { return ImGui::SliderFloat(label, v, v_min, v_max, format, flags); }
            bool SliderFloat4(const char* label, float v[4], float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0) { return ImGui::SliderFloat(label, v, v_min, v_max, format, flags); }
            bool SliderAngle(const char* label, float* v_rad, float v_degrees_min = -360.0f, float v_degrees_max = +360.0f, const char* format = "%.0f deg", ImGuiSliderFlags flags = 0) { return ImGui::SliderAngle(label, v_rad, v_degrees_min, v_degrees_max, format, flags); }
            bool SliderInt(const char* label, int* v, int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0) { return ImGui::SliderInt(label, v, v_min, v_max, format, flags); }
            bool SliderInt2(const char* label, int v[2], int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0) { return ImGui::SliderInt(label, v, v_min, v_max, format, flags); }
            bool SliderInt3(const char* label, int v[3], int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0) { return ImGui::SliderInt(label, v, v_min, v_max, format, flags); }
            bool SliderInt4(const char* label, int v[4], int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0) { return ImGui::SliderInt(label, v, v_min, v_max, format, flags); }
            bool SliderScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format = NULL, ImGuiSliderFlags flags = 0) { return ImGui::SliderScalar(label, data_type, p_data, p_min, p_max, format, flags); }
            bool SliderScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_min, const void* p_max, const char* format = NULL, ImGuiSliderFlags flags = 0) { return ImGui::SliderScalarN(label, data_type, p_data, components, p_min, p_max, format, flags); }
            bool VSliderFloat(const char* label, const ImVec2& size, float* v, float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0) { return ImGui::VSliderFloat(label, size, v, v_min, v_max, format, flags); }
            bool VSliderInt(const char* label, const ImVec2& size, int* v, int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0) { return ImGui::VSliderInt(label, size, v, v_min, v_max, format, flags); }
            bool VSliderScalar(const char* label, const ImVec2& size, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format = NULL, ImGuiSliderFlags flags = 0) { return ImGui::VSliderScalar(label, size, data_type, p_data, p_min, p_max, format, flags); }

            // Widgets: Input with Keyboard
            bool InputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL) { return ImGui::InputText(label, buf, buf_size, flags); }
            bool InputTextMultiline(const char* label, char* buf, size_t buf_size, const ImVec2& size = ImVec2(0, 0), ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL) { return ImGui::InputTextMultiline(label, buf, buf_size, size, flags, callback, user_data); }
            bool InputTextWithHint(const char* label, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL) { return ImGui::InputTextWithHint(label, hint, buf, buf_size, flags, callback, user_data); }
            bool InputFloat(const char* label, float* v, float step = 0.0f, float step_fast = 0.0f, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) { return ImGui::InputFloat(label, v, step, step_fast, format, flags); }
            bool InputFloat2(const char* label, float v[2], const char* format = "%.3f", ImGuiInputTextFlags flags = 0) { return ImGui::InputFloat2(label, v, format, flags); }
            bool InputFloat3(const char* label, float v[3], const char* format = "%.3f", ImGuiInputTextFlags flags = 0) { return ImGui::InputFloat3(label, v, format, flags); }
            bool InputFloat4(const char* label, float v[4], const char* format = "%.3f", ImGuiInputTextFlags flags = 0) { return ImGui::InputFloat4(label, v, format, flags); }
            bool InputInt(const char* label, int* v, int step = 1, int step_fast = 100, ImGuiInputTextFlags flags = 0) { return ImGui::InputInt(label, v, step, step_fast, flags); }
            bool InputInt2(const char* label, int v[2], ImGuiInputTextFlags flags = 0) { return ImGui::InputInt2(label, v, flags); }
            bool InputInt3(const char* label, int v[3], ImGuiInputTextFlags flags = 0) { return ImGui::InputInt3(label, v, flags); }
            bool InputInt4(const char* label, int v[4], ImGuiInputTextFlags flags = 0) { return ImGui::InputInt4(label, v, flags); }
            bool InputDouble(const char* label, double* v, double step = 0.0, double step_fast = 0.0, const char* format = "%.6f", ImGuiInputTextFlags flags = 0) { return ImGui::InputDouble(label, v, step, step_fast, format, flags); }
            bool InputScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_step = NULL, const void* p_step_fast = NULL, const char* format = NULL, ImGuiInputTextFlags flags = 0) { return ImGui::InputScalar(label, data_type, p_data, p_step, p_step_fast, format, flags); }
            bool InputScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_step = NULL, const void* p_step_fast = NULL, const char* format = NULL, ImGuiInputTextFlags flags = 0) { return ImGui::InputScalarN(label, data_type, p_data, components, p_step, p_step_fast, format, flags); }
        
            // Widgets: Color Editor/Picker

            // Widgets: Trees

            // Widgets: Selectables

            // Widgets: List Boxes

            // Widgets: Data Plotting

            // Widgets: Menus
            bool BeginMenuBar() { return ImGui::BeginMenuBar(); }                                         
            void EndMenuBar() { ImGui::EndMenuBar(); }                                          
            bool BeginMainMenuBar() { return ImGui::BeginMainMenuBar(); }                                              
            void EndMainMenuBar() { ImGui::EndMainMenuBar(); }                                                
            bool BeginMenu(const char* label, bool enabled = true) { return ImGui::BeginMenu(label, enabled); }              
            void EndMenu() { ImGui::EndMenu(); }                                    
            bool MenuItem(const char* label, const char* shortcut = NULL, bool selected = false, bool enabled = true) { return ImGui::MenuItem(label, shortcut, selected, enabled); }
            bool MenuItem(const char* label, const char* shortcut, bool* p_selected, bool enabled = true) { return ImGui::MenuItem(label, shortcut, p_selected, enabled); }           
        private:
            float m_mainScale = 1.0f;
            ImGuiIO* m_io = nullptr;
    };
}
