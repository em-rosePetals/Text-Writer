#include <SFML/Graphics/RenderWindow.hpp> // sf::RenderWindow, sf::VideoMode for constructor of former
#include <SFML/Window/Event.hpp> // sf::Event
#include <array> // std::array
#include <iostream> // std::cout
#include <cctype> // isupper()

#include "letter.hpp"
// width of window
const int windowW = 2560;
// height of window
const int windowH = 1600;
// width of letter
const int letterW = 110;

void drawString(sf::VertexArray& va, const std::string& str);
// pass by value because it's gonna get copied anyway
std::string sanitize(std::string str);

int main() {
	// vertex array to be interpreted as points, starting with capacity 0
	sf::VertexArray va(sf::Points, 0);
	// draw the string onto the vertex array
	drawString(va, "happy\nbirthday\nmiles!!!!\nhope your had a wonderful year\nand heres to many more!");
	// index of the point to be revealed
	std::size_t index = 0;
	// makes a window to be drawn onto
	sf::RenderWindow window(sf::VideoMode(windowW, windowH),
			"did you notice this?");
	// number of points revealed per second (this can go very high)
	window.setFramerateLimit(300);
	while (window.isOpen()) {
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
		// reveals current point by turning it white
		va[index].color = sf::Color::White;
		// draws the vertices
		window.draw(va);
		// draws the window onto the screen
		window.display();
		// needs to not hit the vtx count
		if (index < va.getVertexCount() - 1) { ++index; }
	}
	return 0;
}

bool isAllowed(char c);
/*
 * takes in a string, modifies it so that only acceptable inputs are in there
 */
std::string sanitize(std::string str) {
	for (std::size_t i = 0; i < str.size(); ++i) {
		char& c = str[i];
		if (isupper(c)) {
			// uppercase letters are 32 ascii values after lowercase ones
			c += 32;
		}
		if (!isAllowed(c)) {
			// invalid character marker
			c = '?';
		}
	}
	return str;
}
bool isAllowed(char c) {
	// set of allowed chars, plus lowercase letters
	return c == ' ' || c == '\n' || c == '!' || islower(c);
}
/*
 * draws a string onto the vertex array, with the proper spacing
 */
void drawString(sf::VertexArray& va, const std::string& str) {
	// makes and clean string
	const std::string cleanStr = sanitize(str);
	// left boundary for the x
	const int xReset = 20;
	// initially at left boundary
	int xOff = xReset;
	// top boundary for the x
	int yOff = 20;
	for (std::size_t i = 0; i < cleanStr.size(); ++i) {
		if (cleanStr[i] == '\n') {
			// go to next line
			yOff += letterW;
			// sets the x value back to the left bound
			xOff = xReset;
			continue;
		}
		// draws letter onto the canvas
		drawLetter(va, 0, letters::byChar(cleanStr[i]), Pt(xOff, yOff));
		// moves to the spot where the next letter will be
		xOff += letterW;
		// if the x is getting too far to the right
		if (xOff > windowW - letterW) {
			// go to new line
			yOff += letterW;
		}
		// makes sure the x never gets too far to the right
		xOff %= windowW - letterW;
	}
}
