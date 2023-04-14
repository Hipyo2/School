public class BishopMoveCommand implements Command
{
  Bishop bishop;
  int distance;
  
  BishopMoveCommand(Bishop bishop)
  {
    this.bishop = bishop;
  }
  public void move(int distance)
  {
    this.distance = distance;
    bishop.move(distance);
  }
  public void undo()
  {
    bishop.undo(this.distance);
  }
}