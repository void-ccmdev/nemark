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
