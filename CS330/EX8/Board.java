import java.util.ArrayList;

public class Board
{
  Command[] moveCommands;
  Pawn pawn;
  Knight knight;
  King king;
  Queen queen;
  Bishop bishop;
  Rook rook;
  

  Board()
  {
    pawn = new Pawn();
    knight = new Knight();
    king = new King();
    rook = new Rook();
    queen = new Queen();
    bishop = new Bishop();
    
    moveCommands = new Command[6];
    moveCommands[0] = new PawnMoveCommand(pawn);
    moveCommands[1] = new BishopMoveCommand(bishop);
    moveCommands[2] = new KnightMoveCommand(knight);
    moveCommands[3] = new KingMoveCommand(king);
    moveCommands[4] = new RookMoveCommand(rook);
    moveCommands[5] = new QueenMoveCommand(queen);
  }
  public void move(int slot, int distance) 
  {
    moveCommands[slot].move(distance);
  }
  public void undo(int slot)
  {
    moveCommands[slot].undo();
  }
  
}