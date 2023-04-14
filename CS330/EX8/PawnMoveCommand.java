public class PawnMoveCommand implements Command
{
  Pawn pawn;
  
  PawnMoveCommand(Pawn pawn)
  {
    this.pawn = pawn;
  }
  public void move(int distance)
  {
    pawn.move(distance);
  }
  public void undo()
  {
    pawn.undo();
  }
}