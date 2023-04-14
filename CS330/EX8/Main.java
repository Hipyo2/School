class Main {
  public static void main(String[] args) {
    Board board = new Board();
    board.move(0,1);
    board.move(1, 4);
    board.undo(1);
    board.move(2, 0);
    board.move(3, 0);
    board.move(4, 2);
    board.undo(4);
    board.move(5, 3);
  }
}