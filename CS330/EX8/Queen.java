public class Queen
{
  char firstCoord;
  char secondCoord;

  Queen()
  {
    firstCoord = 'E';
    secondCoord = '1';
  }

  void move(int distance)
  {
    firstCoord += distance;
    System.out.println("Queen moves to " + firstCoord + " " + secondCoord);
  }

  void undo(int distance)
  {
    firstCoord -= distance;
    System.out.println("Queen undoes move, returns to " + firstCoord + " " + secondCoord);
  }
}