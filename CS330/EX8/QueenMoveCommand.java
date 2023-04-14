public class QueenMoveCommand implements Command
{
  Queen queen;
  int distance;
  
  QueenMoveCommand(Queen queen)
  {
    this.queen = queen;
    
  }
  public void move(int distance)
  {
    this.distance = distance;
    queen.move(distance);
  }
  public void undo()
  {
    queen.undo(this.distance);
  }
}