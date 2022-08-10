#ifndef LETTER_HPP
#define LETTER_HPP

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp> // sf::Vector2f
#include <array>
#include <utility> // std::pair
#include <iostream>
#include <memory>

using Pt = sf::Vector2f;
using PtPair = std::pair<Pt, Pt>;

struct Letter {
	std::array<std::unique_ptr<PtPair>, 4> ptPairs;
	Pt origin;
	// pass by value so letter manages itself
	Letter(const Pt& origin, const std::array<PtPair, 4>& pairs);
	~Letter();
};

void drawLetter(sf::VertexArray&, std::size_t start, const Letter& letter);

std::ostream& operator<<(std::ostream&, const Pt&);
std::ostream& operator<<(std::ostream&, const PtPair&);
std::ostream& operator<<(std::ostream&, const Letter&);

// anything beyond here exists SOLELY for testing purposes

struct SlopeHelper {
	sf::Vector2f slope;
	int verticesNeeded;
};

SlopeHelper normSlope(const PtPair& pair);

void drawLn(sf::VertexArray& va, std::size_t start, const Pt& offset, const PtPair& pair);

#endif 
