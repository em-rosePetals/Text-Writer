#include <SFML/Graphics/RenderWindow.hpp> // sf::RenderWindow, sf::VideoMode for constructor of former
#include <SFML/Window/Event.hpp> // sf::Event
#include <array> // std::array
#include <iostream> // std::cout

#include "letter.hpp"

int main() {
	/*
	const Pt pt0(0.0f, 0.0f);
	const Pt pt1(100.0f, 500.0f);

	SlopeHelper helper = normSlope(PtPair(pt0, pt1));

	std::cout << "slope: " << helper.slope.y << " / " << helper.slope.x << '\n';
	std::cout << "vertices needed: " << helper.verticesNeeded;

	sf::VertexArray va(sf::Points, 0);
	drawLn(va, 0, Pt(100.0f, 100.0f), PtPair(pt0, pt1));
	*/
	const Pt pt0(100.0f, 100.0f);
	const Pt pt1(75.0f, 0.0f);
	const Pt pt2(0.0f, 50.0f);
	const Pt pt3(75.0f, 100.0f);
	const Pt pt4(100.0f, 0.0f);

	Letter l(Pt(0, 0), std::array<PtPair, 4>{PtPair(pt0, pt1), PtPair(pt1, pt2), PtPair(pt2, pt3), PtPair(pt3, pt4)});
	std::cout << l;
	sf::VertexArray va(sf::Points, 100);
	drawLetter(va, 0, l);
	
	// 800 x 800
	sf::RenderWindow window(sf::VideoMode(800, 800), "test");
	window.setFramerateLimit(60);
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
