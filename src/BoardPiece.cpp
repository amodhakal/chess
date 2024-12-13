//
// Created by Amodh on 12/13/24.
//

#include "../include/BoardPiece.h"

using namespace std;


BoardPiece::BoardPiece( User user ) : m_User( std::move( user ))
{}

User BoardPiece::getUser()
{
  return BoardPiece::m_User;
}

char PawnPiece::getPieceAsCharacter()
{
  return 'P';
}

char KnightPiece::getPieceAsCharacter()
{
  return 'N';
}

char BishopPiece::getPieceAsCharacter()
{
  return 'B';
}

char RookPiece::getPieceAsCharacter()
{
  return 'R';
}

char QueenPiece::getPieceAsCharacter()
{
  return 'Q';
}

char KingPiece::getPieceAsCharacter()
{
  return 'K';
}
