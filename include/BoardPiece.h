//
// Created by Amodh on 12/13/24.
//

#ifndef CHESS_BOARDPIECE_H
#define CHESS_BOARDPIECE_H

#include "User.h"

class BoardPiece
{
public:
  explicit BoardPiece( User user );

  User getUser();

  virtual char getPieceAsCharacter() = 0;

private:
  User m_User;
};

class PawnPiece : public BoardPiece
{
public:
  explicit PawnPiece( User user ) : BoardPiece( std::move( user ))
  {};

  char getPieceAsCharacter() override;
};

class KnightPiece : public BoardPiece
{
public:
  explicit KnightPiece( User user ) : BoardPiece( std::move( user ))
  {};

  char getPieceAsCharacter() override;
};

class BishopPiece : public BoardPiece
{
public:
  explicit BishopPiece( [[maybe_unused]] User user ) : BoardPiece( std::move( user ))
  {};

  char getPieceAsCharacter() override;
};

class RookPiece : public BoardPiece
{
public:
  explicit RookPiece( User user ) : BoardPiece( std::move( user ))
  {};

  char getPieceAsCharacter() override;
};

class QueenPiece : public BoardPiece
{
public:
  explicit QueenPiece( User user ) : BoardPiece( std::move( user ))
  {};

  char getPieceAsCharacter() override;
};

class KingPiece : public BoardPiece
{
public:
  explicit KingPiece( User user ) : BoardPiece( std::move( user ))
  {};

  char getPieceAsCharacter() override;
};

#endif //CHESS_BOARDPIECE_H
