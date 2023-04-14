public interface Command
{
  public void move(int distance);
  public void undo();
}