#pragma once
#include "gui.hpp"

auto c_gui::draw() -> void
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    POINT mPos;
    GetCursorPos(&mPos);
    ImVec2 window_size = ImVec2(500, 360);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowPos(ImVec2(GetSystemMetrics(SM_CXSCREEN) / 2 - window_size.x / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - window_size.y / 2), ImGuiCond_Once);
    if (vars.g_open)
    {
        if (ImGui::Begin("##MENU", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBackground))
        {
            #define min 60
            static auto barsize = min;
            static auto tab = 0;
            auto pos = ImGui::GetWindowPos();
            auto size = ImGui::GetWindowSize();
            bool isHovering = mPos.x >= pos.x && mPos.y >= pos.y && mPos.x <= (pos.x + size.x) && mPos.y <= (pos.y + size.y);

            if (isHovering)
                GAPI::EnableInput();
            else if (!isHovering)
                GAPI::DisableInput();

            ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + window_size.x, pos.y + window_size.y), ImColor(18, 18, 18, 255));
            ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + barsize, pos.y + window_size.y), ImColor(25, 25, 25, 255));

            ImGui::BeginChild("##TABS", ImVec2(barsize, window_size.y));
            {
                ImGui::BeginGroup();
                {
                    if (gui->create_tab("Aimbot", "B", 0 == tab)) tab = 0;
                    if (gui->create_tab("Visuals", "D", 1 == tab)) tab = 1;
                    if (gui->create_tab("Misc", "C", 2 == tab)) tab = 2;
                    if (gui->create_tab("Configs", "C", 3 == tab)) tab = 3;

                }
                ImGui::EndGroup();
            }
            ImGui::EndChild();
            if (ImGui::IsItemHovered())
            {
                if (barsize < 200 /*max size*/)
                    barsize += 5 /*speed of animation*/;
            }
            else
            {
                if (barsize > min)
                    barsize -= 5 /*speed of animation*/;
            }
            if (tab == 0)
            {
                ImGui::SetCursorPos(ImVec2(barsize + 10, 5));
                ImGui::Text("Aimbot");

                ImGui::SetCursorPos(ImVec2(barsize + 10, 45));
                ImGui::SetNextItemWidth(220);
                ImGui::Checkbox("nospread", &vars.nospread);
            }
            if (tab == 1)
            {
                ImGui::SetCursorPos(ImVec2(barsize + 10, 5));
                ImGui::Text("Visuals");

                //ImGui::SetCursorPos(ImVec2(barsize + 10, 45));
                //ImGui::SetNextItemWidth(220);
                //ImGui::Checkbox("Esp", &vars.esp);

                ImGui::SetCursorPos(ImVec2(barsize + 10, 45));
                ImGui::SetNextItemWidth(220);
                ImGui::SliderFloat("fov", &vars.fov_ammount, 25, 130);
            }
            if (tab == 2)
            {
                ImGui::SetCursorPos(ImVec2(barsize + 10, 5));
                ImGui::Text("Misc");

                ImGui::SetCursorPos(ImVec2(barsize + 10, 45));
                ImGui::Checkbox("no recoil", &vars.no_recoil);

                ImGui::SetCursorPos(ImVec2(barsize + 10, 75));
                ImGui::Checkbox("doublejump", &vars.doublejump);

                ImGui::SetCursorPos(ImVec2(barsize + 10, 105));
                ImGui::Checkbox("always_shoot", &vars.always_shoot);

                ImGui::SetCursorPos(ImVec2(barsize + 10, 135));
                ImGui::SetNextItemWidth(220);
                ImGui::SliderFloat("gravity ammount", &vars.gravity_ammount, 0.1f, 2.5f);

                ImGui::SetCursorPos(ImVec2(barsize + 10, 165));
                ImGui::Checkbox("spyderman", &vars.spyderman);

                ImGui::SetCursorPos(ImVec2(barsize + 10, 195));
                ImGui::Checkbox("admin flags", &vars.admin_flags);

                ImGui::SetCursorPos(ImVec2(barsize + 10, 225));
                ImGui::Checkbox("longeject", &vars.longeject);
                if (vars.longeject == true)
                {
                    ImGui::SameLine();
                    ImGui::KeyBind("##longeject bind", vars.longbind, ImVec2(60, 20));
                }

                ImGui::SetCursorPos(ImVec2(barsize + 10, 255));
                ImGui::Checkbox("speedhack", &vars.speedhack);
                if (vars.speedhack == true)
                {
                    ImGui::SameLine();
                    ImGui::KeyBind("##speedhack bind", vars.speedbind, ImVec2(60, 20));

                    ImGui::SetCursorPos(ImVec2(barsize + 10, 285));
                    ImGui::SetNextItemWidth(220);
                    ImGui::SliderFloat("speed", &vars.speedamount, 0, 100);
                }

                //ImGui::SetCursorPos(ImVec2(barsize + 10, 255));
                //ImGui::Checkbox("walkonwater", &vars.walkonwater);

                //ImGui::SetCursorPos(ImVec2(barsize + 10, 225));
                //ImGui::Checkbox("fly", &vars.fly);
                //if (vars.fly == true)
                //{
                //    ImGui::SameLine();
                //    ImGui::KeyBind("##fly bind", vars.flybind, ImVec2(50, 20));

                //    ImGui::SetCursorPos(ImVec2(barsize + 10, 255));
                //    ImGui::SetNextItemWidth(220);
                //    ImGui::SliderFloat("fly speed", &vars.flyspeed, 50, 125);
                //}


                //ImGui::SetCursorPos(ImVec2(barsize + 10, 285));
                //ImGui::Checkbox("Crosshair", &vars.crosshair);
                //if (vars.crosshair == true)
                //{
                //    ImGui::SameLine();
                //    ImGui::Combo("##CrossColor", &selectedCross, crossBR, IM_ARRAYSIZE(crossBR));
                //    if (selectedCross == 1)
                //    {
                //        clrprp = true;
                //    }
                //    if (selectedCross == 2)
                //    {
                //        clrgrn = true;
                //    }
                //    if (selectedCross == 3)
                //    {
                //        clrblu = true;
                //    }
                //    if (selectedCross == 4)
                //    {
                //        clrcyn = true;
                //    }
                //    if (selectedCross == 5)
                //    {
                //        clrred = true;
                //    }
                //}
            }
            if (tab == 3)
            {
                ImGui::SetCursorPos(ImVec2(barsize + 10, 5));
                ImGui::Text("Configs");


            }
        }
    }
	ImGui::End();
}