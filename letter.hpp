#ifndef LETTER_HPP
#define LETTER_HPP

#include <SFML/Graphics/VertexArray.hpp> // sf::VertexArray
#include <SFML/System/Vector2.hpp> // sf::Vector2f
#include <array> // std::array
#include <utility> // std::pair
#include <iostream> // std::ostream
#include <memory> // std::unique_ptr

using Pt = sf::Vector2f;
using PtPair = std::pair<Pt, Pt>;

struct Letter {
	std::array<std::unique_ptr<PtPair>, 4> ptPairs;
	Letter(const std::array<PtPair, 4>& pairs);
};
void drawLetter(sf::VertexArray&, std::size_t start, const Letter& letter,
		const Pt& offset);

std::ostream& operator<<(std::ostream&, const Pt&);
std::ostream& operator<<(std::ostream&, const PtPair&);
std::ostream& operator<<(std::ostream&, const Letter&);

namespace {

const std::array<Pt, 5> aPts = {Pt(100.0f, 100.0f), Pt(75.0f, 0.0f),
	Pt(0.0f, 50.0f), Pt(75.0f, 100.0f), Pt(100.0f, 0.0f)};
const std::array<Pt, 5> bPts = {Pt(0.0f, 0.0f), Pt(33.3f, 100.0f),
	Pt(100.0f, 75.0f), Pt(33.3f, 50.0f), Pt(0.0f, 100.0f)};
const std::array<Pt, 5> cPts = {Pt(100.0f, 25.0f), Pt(50.0f, 0.0f),
	Pt(0.0f, 50.0f), Pt(50.0f, 100.0f), Pt(100.0f, 75.0f)};
const std::array<Pt, 5> dPts = {Pt(100.0f, 0.0f), Pt(66.6f, 100.0f),
	Pt(0.0f, 75.0f), Pt(66.6f, 50.0f), Pt(100.0f, 100.0f)};
const std::array<Pt, 5> ePts = {Pt(50.0f, 100.0f), Pt(0.0f, 50.0f),
	Pt(50.0f, 0.0f), Pt(100.0f, 50.0f), Pt(0.0f, 50.0f)};
const std::array<Pt, 6> fPts = {Pt(0.0f, 50.0f), Pt(100.0f, 50.0f),
	Pt(33.3f, 100.0f), Pt(33.3f, 25.0f), Pt(55.5f, 10.0f), Pt(77.7f, 25.5f)};
const std::array<Pt, 5> gPts = { Pt(50.0f, 0.0f), Pt(0.0f, 50.0f),
	Pt(50.0f, 100.0f), Pt(100.0f, 50.0f), Pt(50.0f, 50.0f) };
const std::array<Pt, 6> hPts = {Pt(0.0f, 0.0f), Pt(0.0f, 100.0f),
	Pt(25.0f, 50.0f), Pt(75.0f, 50.0f), Pt(100.0f, 100.0f)};
const std::array<Pt, 4> iPts = { Pt(50.0f, 0.0f), Pt(50.0f, 25.0f),
	Pt(50.0f, 50.0f), Pt(50.0f, 100.0f) };
const std::array<Pt, 5> jPts = {Pt(50.0f, 0.0f), Pt(50.0f, 25.0f),
	Pt(50.0f, 50.0f), Pt(50.0f, 75.0f), Pt(33.3f, 100.0f)};
const std::array<Pt, 5> kPts = { Pt(0.0f, 0.0f), Pt(0.0f, 100.0f),
	Pt(0.0f, 62.5f), Pt(100.0f, 25.0f), Pt(100.0f, 100.f) };
const std::array<Pt, 2> lPts = { Pt(50.0f, 0.0f), Pt(50.0f, 100.0f) };
const std::array<Pt, 5> mPts = { Pt(0.0f, 100.0f), Pt(25.0f, 0.0f),
	Pt(50.0f, 100.0f), Pt(75.0f, 0.0f), Pt(100.0f, 100.0f) };
const std::array<Pt, 5> nPts = { Pt(0.0f, 38.5f), Pt(0.0f, 100.0f),
	Pt(25.0f, 50.0f), Pt(75.0f, 50.0f), Pt(100.0f, 100.0f) };
const std::array<Pt, 4> oPts = { Pt(0.0f, 50.0f), Pt(50.0f, 0.0f),
	Pt(100.0f, 50.0f), Pt(50.0f, 100.0f) };
const std::array<Pt, 5> pPts = { Pt(0.0f, 0.0f), Pt(33.3f, 50.0f),
	Pt(100.0f, 25.0f), Pt(33.3f, 0.0f), Pt(0.0f, 100.0f) };
const std::array<Pt, 5> qPts = { Pt(50.0f, 50.0f), Pt(100.0f, 100.0f),
	Pt(0.0f, 100.0f), Pt(100.0f, 50.0f), Pt(33.0f, 0.0f) };
const std::array<Pt, 5> rPts = { Pt(0.0f, 38.5f), Pt(0.0f, 100.0f),
	Pt(12.5f, 50.0f), Pt(50.0f, 38.5f), Pt(87.5f, 50.0f) };
const std::array<Pt, 4> sPts = { Pt(50.0f, 0.0f), Pt(0.0f, 50.0f),
	Pt(100.0f, 50.0f), Pt(50.0f, 100.0f) };
const std::array<Pt, 4> tPts = { Pt(12.5f, 50.0f), Pt(87.5f, 50.0f),
	Pt(50.0f, 0.0f), Pt(50.0f, 100.0f) };
const std::array<Pt, 5> uPts = { Pt(0.0f, 0.0f), Pt(0.0f, 62.5f),
	Pt(50.0f, 100.0f), Pt(100.0f, 62.5f), Pt(100.0f, 0.0f) };
const std::array<Pt, 3> vPts = { Pt(0.0f, 0.0f), Pt(50.0f, 100.0f),
	Pt(100.0f, 0.0f) };
const std::array<Pt, 5> wPts = { Pt(0.0f, 0.0f), Pt(25.0f, 100.0f),
	Pt(50.0f, 0.0f), Pt(75.0f, 100.0f), Pt(100.0f, 0.0f) };
const std::array<Pt, 4> xPts = { Pt(0.0f, 0.0f), Pt(100.0f, 100.0f),
	Pt(100.0f, 0.0f), Pt(0.0f, 100.0f) };
const std::array<Pt, 4> yPts = { Pt(0.0f, 0.0f), Pt(50.0f, 50.0f),
	Pt(0.0f, 100.0f), Pt(100.0f, 0) };
const std::array<Pt, 4> zPts = { Pt(0.0f, 0.0f), Pt(100.f, 0.0f),
	Pt(0.0f, 100.0f), Pt(100.0f, 100.0f) };
const std::array<Pt, 4> exclPts = { Pt(50.0f, 0.0f), Pt(50.0f, 66.6f),
	Pt(50.0f, 77.7f), Pt(50.0f, 100.0f) };
/*
 * note: the points themselves are valid, they're just used for the null char
 */
const std::array<Pt, 4> invalPts = { Pt(0.0f, 0.0f), Pt(100.0f, 0.0f),
	Pt(100.0f, 100.0f), Pt(0, 100.0f) };
} // namespace

namespace letters {

const Letter& byChar(char c);
// letter a
const Letter A(std::array<PtPair, 4>{ PtPair(aPts[0], aPts[1]),
	PtPair(aPts[1], aPts[2]), PtPair(aPts[2], aPts[3]),
	PtPair(aPts[3], aPts[4]) });
// letter b
const Letter B(std::array<PtPair, 4>{ PtPair(bPts[0], bPts[1]),
	PtPair(bPts[1], bPts[2]), PtPair(bPts[2], bPts[3]),
	PtPair(bPts[3], bPts[4]) });
// letter c
const Letter C(std::array<PtPair, 4>{ PtPair(cPts[0], cPts[1]),
	PtPair(cPts[1], cPts[2]), PtPair(cPts[2], cPts[3]),
	PtPair(cPts[3], cPts[4]) });
// letter d
const Letter D(std::array<PtPair, 4>{PtPair(dPts[0], dPts[1]),
	PtPair(dPts[1], dPts[2]), PtPair(dPts[2], dPts[3]),
	PtPair(dPts[3], dPts[4]) });
// letter e
const Letter E(std::array<PtPair, 4>{ PtPair(ePts[0], ePts[1]),
	PtPair(ePts[1], ePts[2]), PtPair(ePts[2], ePts[3]),
	PtPair(ePts[3], ePts[4]) });
// letter f
const Letter F(std::array<PtPair, 4>{ PtPair(fPts[0], fPts[1]),
	PtPair(fPts[2], fPts[3]), PtPair(fPts[3], fPts[4]),
	PtPair(fPts[4], fPts[5]) });
// letter g
const Letter G(std::array<PtPair, 4>{ PtPair(gPts[0], gPts[1]),
	PtPair(gPts[1], gPts[2]), PtPair(gPts[2], gPts[3]),
	PtPair(gPts[3], gPts[4]) });
// letter h
const Letter H(std::array<PtPair, 4>{ PtPair(hPts[0], hPts[1]),
	PtPair(hPts[1], hPts[2]), PtPair(hPts[2], hPts[3]),
	PtPair(hPts[3], hPts[4]) });
// letter i
const Letter I(std::array<PtPair, 4>{ PtPair(iPts[0], iPts[1]),
	PtPair(iPts[2], iPts[3]) });
// letter j
const Letter J(std::array<PtPair, 4>{ PtPair(jPts[0], jPts[1]),
	PtPair(jPts[2], jPts[3]), PtPair(jPts[3], jPts[4]) });
// letter k
const Letter K(std::array<PtPair, 4>{ PtPair(kPts[0], kPts[1]),
	PtPair(kPts[2], kPts[3]), PtPair(kPts[2], kPts[4]) });
// letter l
const Letter L(std::array<PtPair, 4>{ PtPair(lPts[0], lPts[1]) });
// letter m
const Letter M(std::array<PtPair, 4>{ PtPair(mPts[0], mPts[1]),
	PtPair(mPts[1], mPts[2]), PtPair(mPts[2], mPts[3]),
	PtPair(mPts[3], mPts[4]) });
// letter n
const Letter N(std::array<PtPair, 4>{ PtPair(nPts[0], nPts[1]),
	PtPair(nPts[1], nPts[2]), PtPair(nPts[2], nPts[3]),
	PtPair(nPts[3], nPts[4]) });
// letter o
const Letter O(std::array<PtPair, 4>{ PtPair(oPts[0], oPts[1]),
	PtPair(oPts[1], oPts[2]), PtPair(oPts[2], oPts[3]),
	PtPair(oPts[3], oPts[0]) });
// letter p
const Letter P(std::array<PtPair, 4>{ PtPair(pPts[0], pPts[1]),
	PtPair(pPts[1], pPts[2]), PtPair(pPts[2], pPts[3]),
	PtPair(pPts[3], pPts[4]) });
// letter q
const Letter Q(std::array<PtPair, 4>{ PtPair(qPts[0], qPts[1]),
	PtPair(qPts[2], qPts[3]), PtPair(qPts[3], qPts[4]),
	PtPair(qPts[2], qPts[4]) });
// letter r
const Letter R(std::array<PtPair, 4>{ PtPair(rPts[0], rPts[1]),
	PtPair(rPts[1], rPts[2]), PtPair(rPts[2], rPts[3]),
	PtPair(rPts[3], rPts[4]) });
// letter s
const Letter S(std::array<PtPair, 4>{ PtPair(sPts[0], sPts[1]),
	PtPair(sPts[1], sPts[2]), PtPair(sPts[2], sPts[3])});
// letter t
const Letter T(std::array<PtPair, 4>{ PtPair(tPts[0], tPts[1]),
	PtPair(tPts[2], tPts[3]) });
// letter u
const Letter U(std::array<PtPair, 4>{ PtPair(uPts[0], uPts[1]),
	PtPair(uPts[1], uPts[2]), PtPair(uPts[2], uPts[3]),
	PtPair(uPts[3], uPts[4]) });
// letter v
const Letter V(std::array<PtPair, 4>{ PtPair(vPts[0], vPts[1]),
	PtPair(vPts[1], vPts[2]) });
// letter w
const Letter W(std::array<PtPair, 4>{ PtPair(wPts[0], wPts[1]),
	PtPair(wPts[1], wPts[2]), PtPair(wPts[2], wPts[3]),
	PtPair(wPts[3], wPts[4]) });
// letter x
const Letter X(std::array<PtPair, 4>{PtPair(xPts[0], xPts[1]),
	PtPair(xPts[2], xPts[3]) });
// letter y
const Letter Y(std::array<PtPair, 4>{ PtPair(yPts[0], yPts[1]),
	PtPair(yPts[2], yPts[3]) });
// letter z
const Letter Z(std::array<PtPair, 4>{ PtPair(zPts[0], zPts[1]),
	PtPair(zPts[1], zPts[2]), PtPair(zPts[2], zPts[3]) });
// exclamation mark
const Letter EXCL(std::array<PtPair, 4>{ PtPair(exclPts[0], exclPts[1]),
	PtPair(exclPts[2], exclPts[3]) });
// not valid character
const Letter INVAL(std::array<PtPair, 4>{ PtPair(invalPts[0], invalPts[1]),
	PtPair(invalPts[1], invalPts[2]), PtPair(invalPts[2], invalPts[3]),
	PtPair(invalPts[3], invalPts[0]) });
// space
const Letter SPACE(std::array<PtPair, 4>{});
}; // namespace letters
// anything beyond here exists SOLELY for testing purposes
#endif // not this thing though you should probably keep this (letter.hpp btw)
