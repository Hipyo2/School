public class RookMoveCommand implements Command
{
  Rook rook;
  int distance;
  
  RookMoveCommand(Rook rook)
  {
    this.rook = rook;
  }
  public void move(int distance)
  {
    this.distance = distance;
    rook.move(distance);
  }
  public void undo()
  {
    rook.undo(this.distance);
  }
}