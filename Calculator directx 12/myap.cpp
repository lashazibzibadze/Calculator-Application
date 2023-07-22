#include "myap.h"

#include <imgui.h>
#include <string>
#include <iostream>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>



// Variables
std::string inputExpression = "";
std::string calculated= "";
float output = 0.0;
int count = 0;
std::string x = "";
std::string y = "";
float f_number = 0.0;
float s_number = 0.0;
bool plus = false, multiply = false, divide = false, minus = false;
bool test = false;


namespace Myapp
{

    void RenderUI() {
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar;
        
        
        
        ImGui::Begin(" LZ Development | Calculator ", nullptr, windowFlags);

        //ImGui::SetNextWindowSize(ImVec2(300, 400));
        
        ImGui::BulletText("Simple Calculator");

        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));

        // Display the input expression inside the black background
        ImGui::BeginChild("input_expression", ImVec2(ImGui::GetWindowContentRegionWidth(), 90), false, ImGuiWindowFlags_NoScrollbar);
        ImGui::SetWindowFontScale(1.5);
        ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), "         %s", inputExpression.c_str());
        ImGui::Text("");
        ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), "         %s", calculated.c_str());
        ImGui::EndChild();

        // Reset the background color
        ImGui::PopStyleColor();
        
        
        //for (int i = 0; i < 5; i++) {
        //    ImGui::PushID(i);
        //    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 7.0f, 0.6f, 0.6f));
        //    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 7.0f, 0.7f, 0.7f));
        //   ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 7.0f, 0.8f, 0.8f));
        //   ImGui::Button("Click");
        //    ImGui::PopStyleColor(3);
        //    ImGui::PopID();
        //}
        float availableWidth = ImGui::GetContentRegionAvail().x;
        float rounding = availableWidth * 0.1f;

        ImVec2 padding = ImVec2(availableWidth * 0.04f, availableWidth * 0.04f);

        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 12.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(32, 32));
        
        
        if (ImGui::Button("7")) {
            inputExpression += "7";
            if (test == false) {
                x += "7";
            }
            if (test == true){
                y += "7";
            }
        }

        ImGui::SameLine();
        
        if (ImGui::Button("8")) {
            inputExpression += "8";
            if (test == false) {
                x += "8";
            }
            if (test == true) {
                y += "8";
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("9")) {
            inputExpression += "9";
            if (test == false) {
                x += "9";
            }
            if (test == true) {
                y += "9";
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("/")) {
            inputExpression += "/";
            count++;
            test = true;
            divide = true;
        }

        if (ImGui::Button("4")) {
            inputExpression += "4";
            if (test == false) {
                x += "4";
            }
            if (test == true) {
                y += "4";
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("5")) {
            inputExpression += "5";
            if (test == false) {
                x += "5";
            }
            if (test == true) {
                y += "5";
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("6")) {
            inputExpression += "6";
            if (test == false) {
                x += "6";
            }
            if (test == true) {
                y += "6";
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("*")) {
            inputExpression += "*";
            count++;
            test = true;
            multiply = true;
        }

        if (ImGui::Button("1")) {
            inputExpression += "1";
            if (test == false) {
                x += "1";
            }
            if (test == true) {
                y += "1";
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("2")) {
            inputExpression += "2";
            if (test == false) {
                x += "2";
            }
            if (test == true) {
                y += "2";
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("3")) {
            inputExpression += "3";
            if (test == false) {
                x += "3";
            }
            if (test == true) {
                y += "3";
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("+")) {
            inputExpression += "+";
            count++;
            test = true;
            plus = true;
        }


        
        ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(7.0f, 0.6f, 0.6f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV( 7.0f, 0.7f, 0.7f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(7.0f, 0.8f, 0.8f));
        

        if (ImGui::Button("=")) {

            f_number = std::stof(x);
            s_number = std::stof(y);

            if (plus == true) {
                output = f_number + s_number;
                plus = false;
            }
            if (minus == true) {
                output = f_number - s_number;
                minus = false;
            }
            if (multiply == true) {
                output = f_number * s_number;
                multiply = false;
            }
            if (divide == true) {
                output = f_number / s_number;
                divide = false;
            }

            if (count != 1) {
                inputExpression = "";
                calculated = "Error! Syntax";
            }
            else {
                calculated = std::to_string(output);
            }

            x = "";
            y = "";
            f_number = 0.0;
            s_number = 0.0;
        }

        ImGui::PopStyleColor(3);

        ImGui::SameLine();
        if (ImGui::Button("0")) {
            inputExpression += "0";
            if (test == false) {
                x += "0";
            }
            if (test == true) {
                y += "0";
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("C")) {
            inputExpression = "";
            calculated = "";
            count = 0;
            test = false;
            plus = false;
            minus = false;
            divide = false;
            multiply = false;
            x = "";
            y = "";
            f_number = 0.0;
            s_number = 0.0;
        }

        ImGui::SameLine();
        if (ImGui::Button("-")) {
            inputExpression += "-";
            count++;
            test = true;
            minus = true;
        }

        //bool test = false;

        //for (int i = 0; i < inputExpression.size(); i++) {

         //   if (inputExpression[i] == '*' || inputExpression[i] == '+' || inputExpression[i] == '-' || inputExpression[i] == '/') {                
        //        test = true;
        //        break;
        //    }

        //    if(test == false){
        //        x += inputExpression[i];
        //    }
        //}

        

        ImGui::PopStyleVar();
        ImGui::PopStyleVar();


        






        ImGui::End();

    }

}
