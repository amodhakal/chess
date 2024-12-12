#pragma once

/** Determines who the owner of the chess piece is */
enum class Owner { Player, Computer };

/** Determines the rank of the chess piece */
enum class Rank { Pawn, Knight, Bishop, Rook, Queen, King };

/**
 * Abstract class that represents the chess piece in a chess board
 */
class BoardPiece {
public:
  /**
   * Creates the board piece object
   * @param owner of the board piece
   */
  explicit BoardPiece(Owner owner);

  /**
   * Returns the owner of the board piece
   * @return owner of the board piece
   */
  Owner getOwner();

  /**
   * Virtual function in children that returns the board piece as a characet
   * @return character representing board piece
   */
  virtual char getChar() = 0;

  /**
   * Virtual function to destroy the board piece
   */
  virtual ~BoardPiece() = default;

private:
  /** The owner of the board piece */
  Owner m_Owner;
};

/**
 * Class to represent the pawn piece in the chess board
 */
class PawnPiece : public BoardPiece {
  using BoardPiece::BoardPiece;
  char getChar() override;
};

/**
 * Class to represent the knight piece in the chess board
 */
class KnightPiece : public BoardPiece {
  using BoardPiece::BoardPiece;
  char getChar() override;
};

/**
 * Class to represent the bishop piece in the chess board
 */
class BishopPiece : public BoardPiece {
  using BoardPiece::BoardPiece;
  char getChar() override;
};

/**
 * Class to represent the rook piece in the chess board
 */
class RookPiece : public BoardPiece {
  using BoardPiece::BoardPiece;
  char getChar() override;
};

/**
 * Class to represent the queen piece in the chess board
 */
class QueenPiece : public BoardPiece {
  using BoardPiece::BoardPiece;
  char getChar() override;
};

/**
 * Class to represent the king piece in the chess board
 */
class KingPiece : public BoardPiece {
  using BoardPiece::BoardPiece;
  char getChar() override;
};
