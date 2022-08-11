#include <SFML/Graphics/RenderWindow.hpp> // sf::RenderWindow, sf::VideoMode for constructor of former
#include <SFML/Window/Event.hpp> // sf::Event
#include <array> // std::array
#include <iostream> // std::cout
#include <cctype>

#include "letter.hpp"

void drawString(sf::VertexArray& va, const std::string& str);
//void sanitize(std::string& str);

const int windowW = 1200;
const int windowH = 1000;

const int letterW = 110;
const int letterH = 110;

int main() {
	sf::VertexArray va(sf::Points, 0);
	drawString(va, "hi tori\nand mercer\nand tt");
	std::size_t index = 0;
	// 800 x 800
	sf::RenderWindow window(sf::VideoMode(windowW, windowH), "test");
	window.setFramerateLimit(300);
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
		va[index].color = sf::Color::White;
		window.draw(va);
		window.display();
		// needs to not hit the vtx count
		if (index < va.getVertexCount() - 1) { ++index; }
	}
	return 0;
}
void drawString(sf::VertexArray& va, const std::string& str) {
	const int xReset = 20;
	int xOff = xReset;
	int yOff = 0;
	for (std::size_t i = 0; i < str.size(); ++i) {
		if (str[i] == ' ') {
			xOff += letterW;
			continue;
		} else if (str[i] == '\n') {
			yOff += letterW;
			xOff = xReset;
			continue;
		}
		drawLetter(va, 0, letters::byChar(str[i]), Pt(static_cast<float>(xOff), static_cast<float>(yOff)));
		xOff += letterW;
		if (xOff > windowW - letterW) {
			yOff += letterW;
		}
		xOff %= windowW - letterW;
		
	}
}
