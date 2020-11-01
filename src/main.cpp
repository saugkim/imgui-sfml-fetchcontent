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
	
	sf::Texture texture1, texture2, texture_inductor, texture_cvs;
    if ( !texture1.loadFromFile("resources/resistor.png") ||
		 !texture2.loadFromFile("resources/capacitor.png") ||
		 !texture_inductor.loadFromFile("resources/inductor.png") || 
		 !texture_cvs.loadFromFile("resources/power.png") )
        return EXIT_FAILURE;
    sf::Sprite sprite1(texture1);
	sf::Sprite sprite4(texture_cvs);
    sf::Sprite sprite2(texture2);
    //sprite1.setOrigin(sf::Vector2f(texture1.getSize()) / 2.f);
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

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("MENU");
		ImGui::ImageButton(sprite1);
		ImGui::ImageButton(texture2);
		ImGui::ImageButton(texture_inductor);
		ImGui::ImageButton(sprite4);
		ImGui::Button("Simulate");
        ImGui::Button("SAVE");
		ImGui::Button("LOAD");
        ImGui::End();

        window.clear();
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}

