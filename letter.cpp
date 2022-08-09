/*
 * letter.cpp
 *
 *  Created on: Aug 5, 2022
 *      Author: emily
 */
#include "letter.hpp"
#include <iostream>
#include <cmath>
/*
* returns slope, non normalized
*/
sf::Vector2f nonNormSlope(const PtPair& pair) {
	float rise = pair.first.y - pair.second.y;
	float run = pair.first.x - pair.second.x;
	return sf::Vector2f(rise, run);
}
/*
* returns a normalized vector representing slope
*/
SlopeHelper normSlope(const PtPair& pair) {
	sf::Vector2f slope = nonNormSlope(pair);
	float normalizer = -std::max(abs(slope.x), abs(slope.y));
	slope /= normalizer;
	SlopeHelper slopeHelp{slope, abs(static_cast<int>(normalizer))};
	return slopeHelp;
}
/*
* if required amount of vertices is greater than current length, resize
*/
void resizeIfNeeded(sf::VertexArray& va, std::size_t start, std::size_t vtxCount) {
	if (start + vtxCount > va.getVertexCount()) {
		va.resize(start + vtxCount);
	}
}

void drawLn(sf::VertexArray& va, std::size_t start, const Pt& offset, const PtPair& pair) {
	SlopeHelper helper = normSlope(pair);
	resizeIfNeeded(va, start, helper.verticesNeeded);
	for (std::size_t i = start; i < va.getVertexCount(); ++i) {
		Pt point = helper.slope * static_cast<float>(i) + offset;
		va[i] = sf::Vertex(point, sf::Color::White);
	}
}


/*

  calculates the slope of a line between the two points
float slope(const PtPair& pair) {
	return slope(pair.first, pair.second);
}
float slope(const Pt& first, const Pt& second) {
	float rise = first.y - second.y;
	float run = first.x - second.x;
	return rise / run;
}

  calculates distance between the x coords of the
float xDist(const PtPair& pair) {
	return xDist(pair.first, pair.second);
}
float xDist(const Pt& first, const Pt& second) {
	return first.x - second.x;
}

  puts a sequence of points that represent a line between the points in the pair
  into the vertex array, starting at start
void drawLn(sf::VertexArray& va, std::size_t start, const PtPair& pair) {
	// slope of line
	const float slp = slope(pair);
	// number of vertices needed
	const int vtxCount = static_cast<int>(-xDist(pair));
	if (start + vtxCount > va.getVertexCount()) {
		va.resize(start + vtxCount);
	}
	for (std::size_t i = start; i < va.getVertexCount(); ++i) {
		va[i] = sf::Vertex(sf::Vector2f(1.0f * i, slp * i));
	}
}
*/
