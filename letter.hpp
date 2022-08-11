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
	~Letter();
};
void drawLetter(sf::VertexArray&, std::size_t start, const Letter& letter, const Pt& offset);

std::ostream& operator<<(std::ostream&, const Pt&);
std::ostream& operator<<(std::ostream&, const PtPair&);
std::ostream& operator<<(std::ostream&, const Letter&);

namespace letters {
	const Letter& byChar(char c);
	const Letter& byIndex(std::size_t i);
	// letter a
	const std::array<Pt, 5> aPts = { Pt(100.0f, 100.0f), Pt(75.0f, 0.0f),
		Pt(0.0f, 50.0f), Pt(75.0f, 100.0f), Pt(100.0f, 0.0f)
	};
	const Letter A(std::array<PtPair, 4>{ PtPair(aPts[0], aPts[1]), 
		PtPair(aPts[1], aPts[2]), PtPair(aPts[2], aPts[3]), 
		PtPair(aPts[3], aPts[4]) });
	// letter b
	const Pt bPt0(0.0f, 0.0f);
	const Pt bPt1(33.3f, 100.0f);
	const Pt bPt2(100.0f, 75.0f);
	const Pt bPt3(33.3f, 50.0f);
	const Pt bPt4(0.0f, 100.0f);
	const Letter B(std::array<PtPair, 4>{PtPair(bPt0, bPt1), PtPair(bPt1, bPt2), PtPair(bPt2, bPt3), PtPair(bPt3, bPt4)});
	// letter c
	const Pt cPt0(100.0f, 25.0f);
	const Pt cPt1(50.0f, 0.0f);
	const Pt cPt2(0.0f, 50.0f);
	const Pt cPt3(50.0f, 100.0f);
	const Pt cPt4(100.0f, 75.0f);
	const Letter C(std::array<PtPair, 4>{PtPair(cPt0, cPt1), PtPair(cPt1, cPt2), PtPair(cPt2, cPt3), PtPair(cPt3, cPt4)});
	// letter d
	const Pt dPt0(100.0f, 0.0f);
	const Pt dPt1(66.6f, 100.0f);
	const Pt dPt2(0.0f, 75.0f);
	const Pt dPt3(66.6f, 50.0f);
	const Pt dPt4(100.0f, 100.0f);
	const Letter D(std::array<PtPair, 4>{PtPair(dPt0, dPt1), PtPair(dPt1, dPt2), PtPair(dPt2, dPt3), PtPair(dPt3, dPt4)});
	// letter e 
	const Pt ePt0(50.0f, 100.0f);
	const Pt ePt1(0.0f, 50.0f);
	const Pt ePt2(50.0f, 0.0f);
	const Pt ePt3(100.0f, 50.0f);
	const Pt ePt4(0.0f, 50.0f);
	const Letter E(std::array<PtPair, 4>{PtPair(ePt0, ePt1), PtPair(ePt1, ePt2), PtPair(ePt2, ePt3), PtPair(ePt3, ePt4)});
	// letter f
	const Pt fPt0(0.0f, 50.0f);
	const Pt fPt1(100.0f, 50.0f);
	const Pt fPt2(33.3f, 100.0f);
	const Pt fPt3(33.3f, 25.0f);
	const Pt fPt4(55.5f, 10.0f);
	const Pt fPt5(77.7f, 25.5f);
	const Letter F(std::array<PtPair, 4>{PtPair(fPt0, fPt1), PtPair(fPt2, fPt3), PtPair(fPt3, fPt4), PtPair(fPt4, fPt5)});
	// letter g
	const Pt gPt0(50.0f, 0.0f);
	const Pt gPt1(0.0f, 50.0f);
	const Pt gPt2(50.0f, 100.0f);
	const Pt gPt3(100.0f, 50.0f);
	const Pt gPt4(50.0f, 50.0f);
	const Letter G(std::array<PtPair, 4>{PtPair(gPt0, gPt1), PtPair(gPt1, gPt2), PtPair(gPt2, gPt3), PtPair(gPt3, gPt4)});
	// letter h
	const Pt hPt0(0.0f, 0.0f);
	const Pt hPt1(0.0f, 100.0f);
	const Pt hPt2(25.0f, 50.0f);
	const Pt hPt3(75.0f, 50.0f);
	const Pt hPt4(100.0f, 100.0f);
	const Letter H(std::array<PtPair, 4>{PtPair(hPt0, hPt1), PtPair(hPt1, hPt2), PtPair(hPt2, hPt3), PtPair(hPt3, hPt4)});
	// letter i
	const Pt iPt0(50.0f, 0.0f);
	const Pt iPt1(50.0f, 25.0f);
	const Pt iPt2(50.0f, 50.0f);
	const Pt iPt3(50.0f, 100.0f);
	const Letter I(std::array<PtPair, 4>{PtPair(iPt0, iPt1), PtPair(iPt2, iPt3)});
	// letter j
	const Pt jPt0(50.0f, 0.0f);
	const Pt jPt1(50.0f, 25.0f);
	const Pt jPt2(50.0f, 50.0f);
	const Pt jPt3(50.0f, 75.0f);
	const Pt jPt4(33.3f, 100.0f);
	const Letter J(std::array<PtPair, 4>{PtPair(jPt0, jPt1), PtPair(jPt2, jPt3), PtPair(jPt3, jPt4)});
	// letter k
	const Pt kPt0(0.0f, 0.0f);
	const Pt kPt1(0.0f, 100.0f);
	const Pt kPt2(0.0f, 62.5f);
	const Pt kPt3(100.0f, 25.0f);
	const Pt kPt4(100.0f, 100.f);
	const Letter K(std::array<PtPair, 4>{PtPair(kPt0, kPt1), PtPair(kPt2, kPt3), PtPair(kPt2, kPt4)});
	// letter l
	const Pt lPt0(50.0f, 0.0f);
	const Pt lPt1(50.0f, 100.0f);
	const Letter L(std::array<PtPair, 4>{PtPair(lPt0, lPt1)});
	// letter m
	const Pt mPt0(0.0f, 100.0f);
	const Pt mPt1(25.0f, 0.0f);
	const Pt mPt2(50.0f, 100.0f);
	const Pt mPt3(75.0f, 0.0f);
	const Pt mPt4(100.0f, 100.0f);
	const Letter M(std::array<PtPair, 4>{PtPair(mPt0, mPt1), PtPair(mPt1, mPt2), PtPair(mPt2, mPt3), PtPair(mPt3, mPt4)});
	// letter n
	const Pt nPt0(0.0f, 38.5f);
	const Pt nPt1(0.0f, 100.0f);
	const Pt nPt2(25.0f, 50.0f);
	const Pt nPt3(75.0f, 50.0f);
	const Pt nPt4(100.0f, 100.0f);
	const Letter N(std::array<PtPair, 4>{PtPair(nPt0, nPt1), PtPair(nPt1, nPt2), PtPair(nPt2, nPt3), PtPair(nPt3, nPt4)});
	// letter o
	const Pt oPt0(0.0f, 50.0f);
	const Pt oPt1(50.0f, 0.0f);
	const Pt oPt2(100.0f, 50.0f);
	const Pt oPt3(50.0f, 100.0f);
	const Letter O(std::array<PtPair, 4>{PtPair(oPt0, oPt1), PtPair(oPt1, oPt2), PtPair(oPt2, oPt3), PtPair(oPt3, oPt0)});
	// letter p
	const Pt pPt0(0.0f, 0.0f);
	const Pt pPt1(33.3f, 50.0f);
	const Pt pPt2(100.0f, 25.0f);
	const Pt pPt3(33.3f, 0.0f);
	const Pt pPt4(0.0f, 100.0f);
	const Letter P(std::array<PtPair, 4>{PtPair(pPt0, pPt1), PtPair(pPt1, pPt2), PtPair(pPt2, pPt3), PtPair(pPt3, pPt4)});
	// letter q
	const Pt qPt0(50.0f, 50.0f);
	const Pt qPt1(100.0f, 100.0f);
	const Pt qPt2(0.0f, 100.0f);
	const Pt qPt3(100.0f, 50.0f);
	const Pt qPt4(33.0f, 0.0f);
	const Letter Q(std::array<PtPair, 4>{PtPair(qPt0, qPt1), PtPair(qPt2, qPt3), PtPair(qPt3, qPt4), PtPair(qPt2, qPt4)});
	// letter r
	const Pt rPt0(0.0f, 38.5f);
	const Pt rPt1(0.0f, 100.0f);
	const Pt rPt2(12.5f, 50.0f);
	const Pt rPt3(50.0f, 38.5f);
	const Pt rPt4(87.5f, 50.0f);
	const Letter R(std::array<PtPair, 4>{PtPair(rPt0, rPt1), PtPair(rPt1, rPt2), PtPair(rPt2, rPt3), PtPair(rPt3, rPt4)});
	// letter s
	const Pt sPt0(50.0f, 0.0f);
	const Pt sPt1(0.0f, 50.0f);
	const Pt sPt2(100.0f, 50.0f);
	const Pt sPt3(50.0f, 100.0f);
	const Letter S(std::array<PtPair, 4>{PtPair(sPt0, sPt1), PtPair(sPt1, sPt2), PtPair(sPt2, sPt3)});
	// letter t
	const Pt tPt0(12.5f, 50.0f);
	const Pt tPt1(87.5f, 50.0f);
	const Pt tPt2(50.0f, 0.0f);
	const Pt tPt3(50.0f, 100.0f);
	const Letter T(std::array<PtPair, 4>{PtPair(tPt0, tPt1), PtPair(tPt2, tPt3)});
	// letter u
	const std::array<Pt, 5> uPts = { Pt(0.0f, 0.0f), Pt(0.0f, 62.5f), Pt(50.0f, 100.0f),
		Pt(100.0f, 62.5f), Pt(100.0f, 0.0f) };
	const Letter U(std::array<PtPair, 4>{ PtPair(uPts[0], uPts[1]), PtPair(uPts[1], uPts[2]), PtPair(uPts[2], uPts[3]), PtPair(uPts[3], uPts[4]) });
	// letter v
	const std::array<Pt, 3> vPts = { Pt(0.0f, 0.0f), Pt(50.0f, 100.0f), Pt(100.0f, 0.0f) };
	const Letter V(std::array<PtPair, 4>{PtPair(vPts[0], vPts[1]), PtPair(vPts[1], vPts[2])});
	// letter w
	const std::array<Pt, 5> wPts = { Pt(0.0f, 0.0f), Pt(25.0f, 100.0f), Pt(50.0f, 0.0f), Pt(75.0f, 100.0f), Pt(100.0f, 0.0f) };
	const Letter W(std::array<PtPair, 4>{PtPair(wPts[0], wPts[1]), PtPair(wPts[1], wPts[2]), PtPair(wPts[2], wPts[3]), PtPair(wPts[3], wPts[4])});
	// letter x
	const std::array<Pt, 4> xPts = { Pt(0.0f, 0.0f), Pt(100.0f, 100.0f), Pt(100.0f, 0.0f), Pt(0.0f, 100.0f) };
	const Letter X(std::array<PtPair, 4>{PtPair(xPts[0], xPts[1]), PtPair(xPts[2], xPts[3])});
	// letter y
	const std::array<Pt, 4> yPts = { Pt(0.0f, 0.0f), Pt(50.0f, 50.0f), Pt(0.0f, 100.0f), Pt(100.0f, 0) };
	const Letter Y(std::array<PtPair, 4>{PtPair(yPts[0], yPts[1]), PtPair(yPts[2], yPts[3])});
	// letter z
	const std::array<Pt, 4> zPts = { Pt(0.0f, 0.0f), Pt(100.f, 0.0f), Pt(0.0f, 100.0f), Pt(100.0f, 100.0f) };
	const Letter Z(std::array<PtPair, 4>{PtPair(zPts[0], zPts[1]), PtPair(zPts[1], zPts[2]), PtPair(zPts[2], zPts[3])});
}

// anything beyond here exists SOLELY for testing purposes
#endif // not this thing though you should probably keep this (letter.hpp btw)
