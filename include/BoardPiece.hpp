#pragma once

/** Determines who the owner of the chess piece is */
enum class Owner { Player, Computer };

/** Determines the rank of the chess piece */
enum class Rank { Pawn, Knight, Bishop, Rook, Queen, King };

/**
 * Class that represents the chess piece in a chess board
 */
class BoardPiece {
public:
  /**
   * Creates the board piece object
   * @param owner of the board piece
   * @param rank of the board piece
   */
  BoardPiece(Owner owner, Rank rank);

  /**
   * Returns the owner of the board piece
   * @return owner of the board piece
   */
  Owner getOwner();

  /**
   * Returns the rank of the board piece
   * @return rank of the board piece
   */
  Rank getRank();

private:
  /** The owner of the board piece */
  Owner m_Owner;

  /** The rank of the board piece */
  Rank m_Rank;
};
