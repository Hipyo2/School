public class KingMoveCommand implements Command
{
  King king;

  
  KingMoveCommand(King king)
  {
    this.king = king;
  }
  public void move(int distance)
  {
    king.move();
  }
  public void undo()
  {
    king.undo();
  }
}