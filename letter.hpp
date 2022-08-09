/*
 * letter.hpp
 *
 *  Created on: Aug 5, 2022
 *      Author: emily
 */

#ifndef LETTER_HPP_
#define LETTER_HPP_

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp> // sf::Vector2f
#include <array>
#include <utility> // std::pair

using Pt = sf::Vector2f;
using PtPair = std::pair<Pt, Pt>;

struct Letter {
	std::array<PtPair, 5> ptPairs;
	Pt origin;
};


void drawLetter(sf::VertexArray&, std::size_t, const Letter&);

// anything beyond here exists SOLELY for testing purposes

struct SlopeHelper {
	sf::Vector2f slope;
	int verticesNeeded;
};

SlopeHelper normSlope(const PtPair& pair);

float xDist(const Pt& first, const Pt& second);
float xDist(const PtPair& pair);

float slope(const Pt& first, const Pt& second);
float slope(const PtPair& pair);

void drawLn(sf::VertexArray&, std::size_t, const Pt& offset, const PtPair& pair);



#endif /* LETTER_HPP_ */
