public class KnightMoveCommand implements Command
{
  Knight knight;
  KnightMoveCommand(Knight knight)
  {
    this.knight = knight;
  }
  public void move(int distance)
  {
    knight.move(distance);
  }
  public void undo()
  {
    knight.undo();
  }
}