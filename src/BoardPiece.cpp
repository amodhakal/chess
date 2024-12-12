#include "../include/BoardPiece.hpp"

BoardPiece::BoardPiece(Owner owner, Rank rank) : m_Owner(owner), m_Rank(rank) {}

Rank BoardPiece::getRank() { return BoardPiece::m_Rank; }

Owner BoardPiece::getOwner() { return BoardPiece::m_Owner; }
