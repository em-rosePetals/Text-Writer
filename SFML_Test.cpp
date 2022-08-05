
#include <SFML/Graphics/RenderWindow.hpp> // sf::RenderWindow, sf::VideoMode for constructor of former
#include <SFML/Window/Event.hpp> // sf::Event
#include <array> // std::array
#include <iostream> // std::cout 

#include "Letter.h"

int main() {

	const Pt pt0(0.0f, 0.0f);
	const Pt pt1(50.0f, 400.0f);
	
	sf::VertexArray va(sf::Points, 100);
	drawLn(va, 0, PtPair(pt0, pt1));

	sf::RenderWindow window(sf::VideoMode(400, 400), "test");
	while (window.isOpen()) {
		// event
		sf::Event event;
		// asks for an event
		while (window.pollEvent(event)) {
			// if it needs closed
			if (event.type == sf::Event::Closed) {
				// close it
				window.close();
			}
		}
		// everything goes blank
		window.clear();
		window.draw(va);
		window.display();
	}
	
	return 0;
}