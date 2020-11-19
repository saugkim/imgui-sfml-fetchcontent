#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "imgui-SFML.h"
#include "imgui.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include "FileHandler.h"
//https://ns-electric.com/design-tools/circuit-simulator/

struct ui_component
{
	int ui_index;
    std::string ui_name;
	
    int ui_pos_x = 0;
	int ui_pos_y = 0;
		
	float ui_value;
	
	friend std::istream& operator >>(std::istream& in, ui_component& ui) {
        char c = ' ';
        in >> ui.ui_index >> c >> ui.ui_name >> c >> ui.ui_pos_x >> c >> ui.ui_pos_y >> c >> ui.ui_value;
        return in;
    }
};


int main() 
{
	
	static int index = 0;
	
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Main Panel");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
	
	
	//Variables
	int columns = 7;
	int rows = 7;
	int gridsize = 80;
	sf::RectangleShape grid[columns][rows];
	double offsetX = 3;
	double offsetY = 2.5;
	
	//Event object holding all events
    sf::Event event;

    //States for button/events
    bool mouseClicked = false;
    bool mouseInsideRect = false;
    bool dragging = false ;

    sf::Vector2f mouseRectOffset ;

    int mouseX = 0;
    int mouseY = 0;
	
	//button images (not necessary, text only will do)
	sf::Texture texture_resistor, texture_capacitor, texture_inductor, texture_cvs, texture_wire, texture_wireH,  texture_wireV ;
    if ( !texture_resistor.loadFromFile("resources/resistor.png") ||
		 !texture_capacitor.loadFromFile("resources/capacitor.png") ||
		 !texture_inductor.loadFromFile("resources/inductor.png") || 
		 !texture_wire.loadFromFile("resources/wire.png") ||
		 !texture_wireH.loadFromFile("resources/wire_h.png") ||
		 !texture_wireV.loadFromFile("resources/wire_v.png") ||
		 !texture_cvs.loadFromFile("resources/power.png") )
        return EXIT_FAILURE;
	
	// UI Images
	sf::Texture image_R, image_C, image_I, image_V, image_WH, image_WV;
    if ( !image_R.loadFromFile("resources/R2.png") ||
		 !image_C.loadFromFile("resources/C2.png") ||
		 !image_I.loadFromFile("resources/C2.png") || 
		 !image_WH.loadFromFile("resources/wireh.png") ||
		 !image_WV.loadFromFile("resources/wirev.png") ||
		 !image_V.loadFromFile("resources/v2.png") )
        return EXIT_FAILURE;
		
    //sf::Sprite sprite1(texture_resistor);
	//sf::Sprite sprite2(texture_capacitor);
	//sf::Sprite sprite3(texture_inductor);
	std::vector<sf::Sprite> sprites;
	
    std::vector<ui_component> ui_elements;
	ui_component ui_;
	
	
	bool element_clicked = false;
	bool removing_element = false;
	int selected_element = -1;
    
    sf::Clock deltaClock;
    while (window.isOpen()) 
	{
		
		sf::Vector2f cellSize(80.0f, 80.0f);

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                grid[i][j].setSize(cellSize);
                grid[i][j].setOutlineColor(sf::Color::White);
                grid[i][j].setOutlineThickness(1.0f);
				grid[i][j].setFillColor(sf::Color::Transparent);

                grid[i][j].setPosition((i+offsetX)*cellSize.x + 1.0f, (j+offsetY)*cellSize.y + 1.0f);
            }
        }
			
        while (window.pollEvent(event)) 
		{
            ImGui::SFML::ProcessEvent(event);
			
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = true;

				if (element_clicked)
				{
                    dragging = true;
					std::cout << "dragging at creating " << std::endl;
                }
				
				for (int i=0; i<sprites.size(); i++) {
					if ( sprites[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) ) {
						selected_element = i ;
						dragging = true ;
						std::cout << "dragging after created ? " << std::endl;
					}
				}
            }
			
			for (int i=0; i<sprites.size(); i++) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {		
					if ( sprites[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) ) {
						std::cout << "i am in " << i << std::endl;
						selected_element = i ;
						std::cout << "Removing" << std::endl;
						removing_element = true;
						break;
					}
				}
			}
					
					
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {

				std::cout << "mouse released" << std::endl;
                mouseClicked = false;
                dragging = false ;
				element_clicked = false;
            }


            if (event.type == sf::Event::MouseMoved) {
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
            }
			

            if (event.type == sf::Event::Closed) {
				
                window.close();
            }
        }
			
		
			
		static const auto buttonsize = ImVec2(150, 50);
        ImGui::SFML::Update(window, deltaClock.restart());
		
		ImGui::Begin("CIRCUIT ELEMENTS");
		if (ImGui::ImageButton(texture_resistor) ){
			
			//create_resistor();
			
			selected_element = index;
			index++;
			sf::Sprite sprite(image_R);
			sprite.setPosition(event.mouseMove.x, event.mouseMove.y);
			sprites.push_back(sprite);
			element_clicked = true;
			
			ui_component ui;
			ui.ui_index = selected_element;
			ui.ui_name = "R";
			ui.ui_pos_x = 1;
			ui.ui_pos_y = 1;
			ui.ui_value = 5.0f;
			ui_elements.push_back(ui);
			
		};
		
		if (ImGui::ImageButton(texture_capacitor) ){
			
			selected_element = sprites.size();
			sf::Sprite sprite(image_C);
			sprite.setPosition(event.mouseMove.x, event.mouseMove.y);
			sprites.push_back(sprite);
			element_clicked = true;
		}
		
		if (ImGui::ImageButton(texture_inductor) ){
			
			selected_element = sprites.size();
			sf::Sprite sprite(image_I);
			sprite.setPosition(event.mouseMove.x, event.mouseMove.y);
			sprites.push_back(sprite);
			element_clicked = true;
		}
		
		if (ImGui::ImageButton(texture_cvs) ){
		
			selected_element = sprites.size();
			sf::Sprite sprite(image_V);
			sprite.setPosition(event.mouseMove.x, event.mouseMove.y);
			sprites.push_back(sprite);
			element_clicked = true;
		}

		if (ImGui::ImageButton(texture_wireH) ){
		
			selected_element = sprites.size();
			sf::Sprite sprite(image_WH);
			sprite.setPosition(event.mouseMove.x, event.mouseMove.y);
			sprites.push_back(sprite);
			element_clicked = true;
		}
		
		if (ImGui::ImageButton(texture_wireV) ){
		
			selected_element = sprites.size();
			sf::Sprite sprite(image_WV);
			sprite.setPosition(event.mouseMove.x, event.mouseMove.y);
			sprites.push_back(sprite);
			// instantiate voltage component object
			
			element_clicked = true;
		}
		
		ImGui::Spacing();
		ImGui::Button("SIMULATE", buttonsize);
		ImGui::Button("RESET", buttonsize);
		ImGui::End();
		
		
		
		static const auto buttonsize1 = ImVec2(100, 30);
        ImGui::Begin("FILE");
		
		static char filenameinput[20] = {};
		ImGui::InputText("filename###save", filenameinput, sizeof(filenameinput));
		ImGui::SameLine();
	
        if (ImGui::Button("SAVE", buttonsize1)) {
			
			std::string fname = filenameinput;
			fname = fname.length() >0 ? fname : "default";

			std::string output_string;
			std::ostringstream oss;
			for (unsigned int i=0; i<sprites.size();i++){
				oss << ui_elements[i].ui_index << " " << ui_elements[i].ui_name;
				oss << '\n' ;
			}
			output_string = oss.str();
			saveAsText(fname, output_string);
		}
		
		ImGui::Spacing();
		
		static char filename_toload[20] = {};
		ImGui::InputText("filename###load", filename_toload, sizeof(filename_toload));
		ImGui::SameLine();
		if (ImGui::Button("LOAD", buttonsize1) ){
			
			std::string input_string = loadFromFile(filename_toload);
			if (input_string.empty()) {
				break;
			}
			//clean_screen();
			//ui_elements.clear();
			//sprites.clear();
			
			std::stringstream ss;
			std::string line;
			ss.str(input_string);
			
			ui_component ui;
			while(getline(ss, line)){  //??
				std::istringstream iss(line);
				iss >> ui.ui_index >> ui.ui_name ;
				ui_elements.push_back(ui);
			}
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
					//saveAsText("resources/test.txt", "hello"); 
					continue;
				}
				if (ImGui::MenuItem("Save", "Ctrl+S"))   { 
					//loadFromFile("resources/test.txt");
					continue;
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
		ImGui::End();
	
	
		window.clear();	
		 
		if (dragging == true) {
			
			unsigned int i = 0;
			unsigned int j = 0;
			
			i = int((mouseX - (offsetX-1)*gridsize)/(gridsize*2)) * 2;
			j = int((mouseY - (offsetY-1)*gridsize)/(gridsize*2)) * 2;
			sf::Vector2f pos = grid[i][j].getPosition(); 
			sprites[selected_element].setPosition(pos);
			
			/*
			for (int i=0;i<columns;i++){
				for (int j=0;j<rows;j++){
					if(grid[i][j].getGlobalBounds().contains(mouseX, mouseY)) {
						sf::Vector2f position = grid[i][j].getPosition(); 
						sprites[selected_element].setPosition(position);
					}
				}
			}
			*/
			//sprites[selected_element].setPosition(mouseX, mouseY);
		}
		
		if (removing_element == true) {
			sprites.erase(sprites.begin() + selected_element);
			removing_element = false;
		}
		
		for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
				
				window.draw(grid[i][j]);
            }		
        }
		
		for (unsigned int i = 0; i < sprites.size() ; i++) {
			
			window.draw(sprites[i]);
		}
		
        ImGui::SFML::Render(window);
        window.display();
    }
	

    ImGui::SFML::Shutdown();

    return 0;
	
}