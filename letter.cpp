#include <iostream>
#include <initializer_list>
#include <cmath> // max, abs
#include <memory>
#include "letter.hpp"

void drawLetter(sf::VertexArray& va, std::size_t start, const Letter& letter) {
	for (std::size_t i = 0; i < letter.ptPairs.size(); ++i) {
		drawLn(va, va.getVertexCount(), letter.origin, *letter.ptPairs[i]);
	}
}

SlopeHelper normSlope(const PtPair& pair);
void resizeIfNeeded(sf::VertexArray& va, std::size_t start, std::size_t vtxCount);
/*
* draws a line between the given points starting at the offset,
and puts the component points into the vertex array starting at start
*/
void drawLn(sf::VertexArray& va, std::size_t start, const Pt& offset, const PtPair& pair) {
	std::cout << "called drawLn: " << pair << '\n';
	SlopeHelper helper = normSlope(pair);
	std::cout << "norm slope: " << helper.slope << '\n';
	std::cout << "before resize: " << va.getVertexCount();
	resizeIfNeeded(va, start, helper.verticesNeeded);
	std::cout << "after resize: " << va.getVertexCount() << '\n';
	for (std::size_t i = start; i < va.getVertexCount(); ++i) {
		Pt point = helper.slope * static_cast<float>(i) + offset;
		va[i] = sf::Vertex(point, sf::Color::White);
	}
}

Letter::Letter(const Pt& origin, const std::array<PtPair, 4>& pairs) {
	this->origin = origin;
	for (std::size_t i = 0; i < pairs.size(); ++i) {
		this->ptPairs[i] = std::move(std::make_unique<PtPair>(pairs[i]));
	}
}
Letter::~Letter() {
	for (std::size_t i = 0; i < ptPairs.size(); ++i) {
		ptPairs[i].reset();
	}
}

std::ostream& operator<<(std::ostream& out, const Pt& point) {
	out << "x: " << point.x << " y: " << point.y;
	return out;
}
std::ostream& operator<<(std::ostream& out, const PtPair& pair) {
	out << "first: " << pair.first << " second: " << pair.second;
	return out;
}
std::ostream& operator<<(std::ostream& out, const Letter& letter) {
	out << "origin:\n" << "    " << letter.origin << '\n';
	out << "pairs:\n";
	for (const std::unique_ptr<PtPair>& pair : letter.ptPairs) {
		out << "    " << pair->first << " , " << pair->second << '\n';
	}
	return out;
}

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
	SlopeHelper slopeHelp{ slope, abs(static_cast<int>(normalizer)) };
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
