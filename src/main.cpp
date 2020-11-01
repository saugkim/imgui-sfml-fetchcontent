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
			
		static const auto size = ImVec2(150, 40);

        ImGui::SFML::Update(window, deltaClock.restart());
		
		ImGui::Begin("CIRCUIT ELEMENTS");
		ImGui::ImageButton(sprite1);
		ImGui::ImageButton(texture_capacitor);
		ImGui::ImageButton(texture_inductor);
		ImGui::ImageButton(sprite4);
		
		ImGui::Button("SIMULATE", size);
		ImGui::End();
		
		
        ImGui::Begin("FILE");
		//ImGui::ImageButton(sprite1);
		//ImGui::ImageButton(texture_capacitor);
		//ImGui::ImageButton(texture_inductor);
		//ImGui::ImageButton(sprite4);
		//ImGui::Button("SIMULATE", size);
			
		static char inputlength[20] = {};
		ImGui::InputText("savename", inputlength, sizeof(inputlength));
	
        if (ImGui::Button("SAVE", size)) {
			
			std::string path = "resources/";
			std::string fname = inputlength;
			const char *ending = ".txt";
			std::string f = path + fname + ending;
		
			saveAsText(f);
			shape.setFillColor(sf::Color::Red);
		}
		
		static char loading[20] = {};
		ImGui::InputText("loadname", loading, sizeof(loading));
			
		if (ImGui::Button("LOAD", size) ){
			
			std::string path = "resources/";
			std::string a = loading;
			const char *b = ".txt";
			std::string f = path + a + b;
			
			loadFromFile(f);
			shape.setFillColor(sf::Color::Green);
		}	
        ImGui::End();
	
	
	
		bool my_tool_active = false;
		ImGui::Begin("FILE HANDLING", &my_tool_active, ImGuiWindowFlags_MenuBar);
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
		
		const float my_values[] = { 0.2f, 0.1f, 1.0f, 0.5f, 0.9f, 2.2f };
		ImGui::PlotLines("Frame Times", my_values, IM_ARRAYSIZE(my_values));

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