public class King
{
  char firstCoord;
  char secondCoord;

  King()
  {
    firstCoord = 'D';
    secondCoord = '1';
  }

  void move()
  {
    secondCoord += 1;
    System.out.println("King moves to " + firstCoord + " " + secondCoord);
  }

  void undo()
  {
    secondCoord -= 1;
    System.out.println("King undoes move, returns to " + firstCoord + " " + secondCoord);
  }
}