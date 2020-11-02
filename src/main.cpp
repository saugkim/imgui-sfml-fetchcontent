#include <iostream>
#include <string>
#include <vector>

#include "imgui-SFML.h"
#include "imgui.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include "FileHandler.h"

int main() {
	
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Main Panel");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	
	sf::Texture texture_resistor, texture_capacitor, texture_inductor, texture_cvs;
    if ( !texture_resistor.loadFromFile("resources/resistor.png") ||
		 !texture_capacitor.loadFromFile("resources/capacitor.png") ||
		 !texture_inductor.loadFromFile("resources/inductor.png") || 
		 !texture_cvs.loadFromFile("resources/power.png") )
        return EXIT_FAILURE;
    sf::Sprite sprite1(texture_resistor);
	sf::Sprite sprite2(texture_capacitor);
	sf::Sprite sprite3(texture_inductor);
	sf::Sprite sprite4(texture_cvs);
    
    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
			
		static const auto size = ImVec2(150, 50);

        ImGui::SFML::Update(window, deltaClock.restart());
		
		ImGui::Begin("CIRCUIT ELEMENTS");
		ImGui::ImageButton(sprite1);
		ImGui::ImageButton(sprite2);
		ImGui::ImageButton(texture_inductor);
		ImGui::ImageButton(sprite4);
		ImGui::Spacing();
		ImGui::Button("SIMULATE", size);
		ImGui::End();
		
		
		static const auto size1 = ImVec2(100, 30);
        ImGui::Begin("FILE");
		
		static char savelength[20] = {};
		ImGui::InputText("filename###save", savelength, sizeof(savelength));
		ImGui::SameLine();
	
        if (ImGui::Button("SAVE", size1)) {
			
			std::string path = "resources/";
			std::string fname = savelength;
			std::cout << fname.length() << std::endl;
			fname = fname.length() >0 ? fname : "default";
			const char *ending = ".txt";
			std::string f = path + fname + ending;
		
			saveAsText(f);
			shape.setFillColor(sf::Color::Red);
		}
		
		ImGui::Spacing();
		
		static char loading[20] = {};
		ImGui::InputText("filename###load", loading, sizeof(loading));
		ImGui::SameLine();
		if (ImGui::Button("LOAD", size1) ){
			
			std::string path = "resources/";
			std::string a = loading;
			const char *b = ".txt";
			std::string f = path + a + b;
			
			loadFromFile(f);
			shape.setFillColor(sf::Color::Green);
		}	
        ImGui::End();
	
	
		static const auto size2 = ImVec2(150, 30);
		bool my_tool_active = false;
		ImGui::Begin("DEMO", &my_tool_active, ImGuiWindowFlags_MenuBar);
		if (ImGui::BeginMenuBar())
		{	
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open..", "Ctrl+O")) { 
					saveAsText("resources/test.txt"); 
				}
				if (ImGui::MenuItem("Save", "Ctrl+S"))   { 
					loadFromFile("resources/test.txt");
				}
				if (ImGui::MenuItem("Close", "Ctrl+W"))  { 
					my_tool_active = false; 
				}
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
		
		ImGui::Button("DEMO1", size2);
		ImGui::SameLine(150, 20);
		ImGui::Button("DEMO2", size2);
		ImGui::SameLine(320, 20);
		ImGui::Button("DEMO3", size2);
		ImGui::Spacing();
		
		ImGui::Text("Demo 1: ...\nVoltage 5V\nResistor 1, 10 ohm\n");
		ImGui::SameLine(150, 20);
		ImGui::Text("Demo 2: \nVoltage 10V\nCapacitor \n");
		ImGui::SameLine(320, 20);
		ImGui::Text("Demo 3: ...");
		
		ImGui::Spacing();
		
		//const float my_values[] = { 0.2f, 0.1f, 1.0f, 0.5f, 0.9f, 2.2f };
		//ImGui::PlotLines("Frame Times", my_values, IM_ARRAYSIZE(my_values));

		// Display contents in a scrolling region
		//ImGui::TextColored(ImVec4(1,1,0,1), "Important Stuff");
		//ImGui::BeginChild("Scrolling");
		//for (int n = 0; n < 10; n++)
		//	ImGui::Text("%04d: Some text", n);
		//ImGui::EndChild();
		ImGui::End();
		
		
        window.clear();
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}