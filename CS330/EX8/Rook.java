public class Rook
{
  char firstCoord;
  char secondCoord;

  Rook()
  {
    firstCoord = 'E';
    secondCoord = '1';
  }

  void move(int distance)
  {
    secondCoord += distance;
    System.out.println("Rook moves to " + firstCoord + " " + secondCoord);
  }

  void undo(int distance)
  {
    secondCoord -= distance;
    System.out.println("Rook undoes move, returns to " + firstCoord + " " + secondCoord);
  }
}