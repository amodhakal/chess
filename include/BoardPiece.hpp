#pragma once

enum class Owner { Player, Computer };
enum class Rank { Pawn, Knight, Bishop, Rook, Queen, King };

class BoardPiece {
public:
  BoardPiece(Owner owner, Rank rank);
  Rank getRank();
  Owner getOwner();

private:
  Owner m_Owner;
  Rank m_Rank;
};
