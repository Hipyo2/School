import java.util.Scanner;

class Main {
  public static void main(String[] args) {

    Scanner inst = new Scanner(System.in);
    Scanner inst2 = new Scanner(System.in);

    System.out.println("what is your name?");
    String username = inst.nextLine();
    
    Logger logger1 = Logger.getInstance();

    logger1.debug("Logging in user " + username);

    System.out.println("what is your birthday? dd/mm/yyyy");
    String birth = inst2.nextLine();
    logger1.warn();
    logger1.info();
    
  }

}