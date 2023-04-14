public class Pawn
{
  char firstCoord;
  char secondCoord;

  Pawn()
  {
    firstCoord = 'A';
    secondCoord = '1';
  }

  void move(int distance)
  {
    firstCoord += 0;
    secondCoord += 1;
    System.out.println("Pawn moves " + firstCoord + " " + secondCoord);
  }

  void undo()
  {
    firstCoord += 0;
    secondCoord += -1;
    System.out.println("Pawn undoes move, returns to " + firstCoord + " " + secondCoord);
  }
}