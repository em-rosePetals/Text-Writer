#include <unordered_map> // std::unordered_map
#include <cmath> // std::max, abs
#include "letter.hpp" /* also includes:
					   * SFML/Graphics/VertexArray.hpp,
					   * SFML/System/Vector2.hpp,
					   * array,
					   * utility,
					   * iostream,
					   * memory
					   */
/*
* contains a vector representing slope, along with the vertices needed to draw
*  the line properly
*/
struct SlopeHelper {
	sf::Vector2f slope;
	std::size_t verticesNeeded;
	SlopeHelper(const sf::Vector2f& slp, std::size_t vtxsNeeded);
};
// a few useful headers
void drawLn(sf::VertexArray& va, std::size_t start, const Pt& offset, const PtPair& pair);
SlopeHelper normSlope(const PtPair& pair);
void resizeIfNeeded(sf::VertexArray& va, std::size_t start, std::size_t vtxCount);
/*
* takes in a character, outputs the corresponding Letter
*/
const Letter& letters::byChar(char c) {
	// maps chars to their corresponding representation
	const std::unordered_map<char, const Letter&> lmap = {
		{'a', letters::A}, {'b', letters::B}, {'c', letters::C},
		{'d', letters::D}, {'e', letters::E}, {'f', letters::F},
		{'g', letters::G}, {'h', letters::H}, {'i', letters::I},
		{'j', letters::J}, {'k', letters::K}, {'l', letters::L},
		{'m', letters::M}, {'n', letters::N}, {'o', letters::O},
		{'p', letters::P}, {'q', letters::Q}, {'r', letters::R},
		{'s', letters::S}, {'t', letters::T}, {'u', letters::U},
		{'v', letters::V}, {'w', letters::W}, {'x', letters::X},
		{'y', letters::Y}, {'z', letters::Z}, {'!', letters::EXCL},
		{' ', letters::SPACE}, {'?', letters::INVAL}
	};
	return lmap.at(c);
}
/*
* draws a given letter onto the given vertex array, starting at start
*/
void drawLetter(sf::VertexArray& va, std::size_t start, const Letter& letter,
		const Pt& offset) {
	for (std::size_t i = 0; i < letter.ptPairs.size(); ++i) {
		// draws a line between the point pair, starting at the offset
		drawLn(va, va.getVertexCount(), offset, *letter.ptPairs[i]);
	}
}
/*
* draws a line between the given points starting at the offset,
and puts the component points into the vertex array starting at start
*/
void drawLn(sf::VertexArray& va, std::size_t start, const Pt& offset, const PtPair& pair) {
	// gets useful slope data
	SlopeHelper helper = normSlope(pair);
	// the function name is kinda self explanatory
	resizeIfNeeded(va, start, helper.verticesNeeded);
	// loops through the line
	for (std::size_t i = start; i < va.getVertexCount(); ++i) {
		// "marches" along the line, starting at the first point in the pair, then adds the offset
		Pt point = (helper.slope * static_cast<float>(i - start)) + pair.first + offset;
		// creates vertex at appropriate index
		va[i] = sf::Vertex(point, sf::Color::Black);
	}
}
/*
* conSTRUCTS (haha) a letter with origin = origin and pt pairs equal to the point pairs
*/
Letter::Letter(const std::array<PtPair, 4>& pairs) {
	for (std::size_t i = 0; i < pairs.size(); ++i) {
		// copies the stuff from the input array
		this->ptPairs[i] = std::make_unique<PtPair>(pairs[i]);
	}
}
/*
* constructs a slope helper
*/
SlopeHelper::SlopeHelper(const sf::Vector2f& slp, std::size_t vtxsNeeded) {
	slope = sf::Vector2f(slp);
	verticesNeeded = vtxsNeeded;
}
/*
* outputs a point in a pretty way
*/
std::ostream& operator<<(std::ostream& out, const Pt& point) {
	out << "x: " << point.x << " y: " << point.y;
	return out;
}
/*
* outputs a point pair in a pretty way
*/
std::ostream& operator<<(std::ostream& out, const PtPair& pair) {
	out << "first: " << pair.first << " second: " << pair.second;
	return out;
}
/*
*  outputs a letter in a pretty way
*/
std::ostream& operator<<(std::ostream& out, const Letter& letter) {
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
	float rise = pair.second.y - pair.first.y;
	float run = pair.second.x - pair.first.x;
	return sf::Vector2f(run, rise);
}
/*
* returns a normalized vector representing slope,
* along with helpful counter for num vertices needed
*/
SlopeHelper normSlope(const PtPair& pair) {
	// vector representing change in x and y
	sf::Vector2f slope = nonNormSlope(pair);
	// the larger absolute value of x and y
	float normalizer = std::max(abs(slope.x), abs(slope.y));
	// normalizes the slope
	slope /= normalizer;
	// constructs a slope helper with all the necessary info
	return SlopeHelper(slope, static_cast<int>(normalizer));
}
/*
* if required amount of vertices is greater than current length, resize
*/
void resizeIfNeeded(sf::VertexArray& va, std::size_t start, std::size_t vtxCount) {
	if (start + vtxCount > va.getVertexCount()) {
		va.resize(start + vtxCount);
	}
}
