#pragma once

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp> // sf::Vector2f
#include <array>
#include <utility> // std::pair

using Pt = sf::Vector2f;
using PtPair = std::pair<Pt, Pt>;

struct Letter {
	std::array<PtPair, 5> ptPairs;
};

void drawLetter(sf::VertexArray&, const Letter&);

// headers beyond here exist SOLELY for testing purposes
float xDist(const Pt& first, const Pt& second);
float xDist(const PtPair& pair);

float slope(const Pt& first, const Pt& second);
float slope(const PtPair& pair);

void drawLn(sf::VertexArray& va, std::size_t start, const PtPair& pair);
