public class Bishop
{
  char firstCoord;
  char secondCoord;

  Bishop()
  {
    firstCoord = 'C';
    secondCoord = '1';
  }

  void move(int distance)
  {
    firstCoord += distance;
    secondCoord += distance;
    System.out.println("Bishop moves to " + firstCoord + " " + secondCoord);
  }

  void undo(int distance)
  {
    firstCoord -= distance;
    secondCoord -= distance;
    System.out.println("Bishop undoes move, returns to " + firstCoord + " " + secondCoord);
  }
}