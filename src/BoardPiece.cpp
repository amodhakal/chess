#include "../include/BoardPiece.hpp"

BoardPiece::BoardPiece(Owner owner) : m_Owner(owner) {}

Owner BoardPiece::getOwner() { return BoardPiece::m_Owner; }

char PawnPiece::getChar() { return 'P'; }

char KnightPiece::getChar() { return 'N'; }

char BishopPiece::getChar() { return 'B'; }

char RookPiece::getChar() { return 'R'; }

char QueenPiece::getChar() { return 'Q'; }

char KingPiece::getChar() { return 'K'; }
