#include "imgui-SFML.h"
#include "imgui.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "ImGui + SFML = <3");
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
    
    //sprite1.setOrigin(sf::Vector2f(texture_resistor.getSize()) / 2.f);
    //sprite1.setPosition(sprite1.getOrigin());

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

        ImGui::Begin("MENU");
		ImGui::ImageButton(sprite1);
		ImGui::ImageButton(texture_capacitor);
		ImGui::ImageButton(texture_inductor);
		ImGui::ImageButton(sprite4);
		ImGui::Button("SIMULATE", size);
        if (ImGui::Button("SAVE", size)) {
			shape.setFillColor(sf::Color::Red);
		}
		
		if (ImGui::Button("LOAD", size) ){
			shape.setFillColor(sf::Color::Green);
		}
		
        ImGui::End();

        window.clear();
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}