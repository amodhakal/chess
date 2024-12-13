//
// Created by Amodh on 12/13/24.
//

#include "../include/BoardPiece.h"

using namespace std;


User::User( std::string name, std::string outputColor ) : m_Name( std::move( name )),
                                                          m_OutputColor( std::move( outputColor ))
{}

string User::getOutputColor()
{
  return User::m_OutputColor;
}

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
