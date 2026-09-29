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
            bool Begin(const char* name, bool* p_open = NULL, ImGuiWindowFlags flags = 0) { ImGui::Begin(name, p_open, flags); }
            void End() { ImGui::End(); }

            //Child Windows
            bool BeginChild(const char* str_id, const ImVec2& size = ImVec2(0, 0), ImGuiChildFlags child_flags = 0, ImGuiWindowFlags window_flags = 0) { ImGui::BeginChild(str_id, size, child_flags, window_flags); }
            bool BeginChild(ImGuiID id, const ImVec2& size = ImVec2(0, 0), ImGuiChildFlags child_flags = 0, ImGuiWindowFlags window_flags = 0) { ImGui::BeginChild(id, size, child_flags, window_flags); }

            //Window uilities
            bool IsWindowAppearing() { ImGui::IsWindowAppearing(); }
            bool IsWindowCollapsed() { ImGui::IsWindowCollapsed(); }
            bool IsWindowFocused(ImGuiFocusedFlags flags=0) { ImGui::IsWindowFocused(flags); }
            bool IsWindowHovered(ImGuiHoveredFlags flags=0) { ImGui::IsWindowHovered(flags); }
            ImDrawList* GetWindowDrawList() { ImGui::GetWindowDrawList(); }
            float GetWindowDpiScale() { ImGui::GetWindowDpiScale(); }
            ImVec2 GetWindowPos() { ImGui::GetWindowPos(); }
            ImVec2 GetWindowSize() { ImGui::GetWindowSize(); }
            float GetWindowWidtht() { ImGui::GetWindowWidth(); }
            float GetWindowHeight() { ImGui::GetWindowHeight(); }
            ImGuiViewport* GetWindowViewport();

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


        private:
            float m_mainScale = 1.0f;
            ImGuiIO* m_io = nullptr;
    };
}
