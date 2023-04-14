public class Knight
{
  char firstCoord;
  char secondCoord;

  Knight()
  {
    firstCoord = 'C';
    secondCoord = '1';
  }

  void move(int distance)
  {
    firstCoord += 1;
    secondCoord += 2;
    System.out.println("Knight moves to " + firstCoord + " " + secondCoord);
  }

  void undo()
  {
    firstCoord -= 1;
    secondCoord -= 2;
    System.out.println("Knight undoes move, returns to " + firstCoord + " " + secondCoord);
  }
}