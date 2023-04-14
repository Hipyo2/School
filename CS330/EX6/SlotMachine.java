public class SlotMachine
{
  Display display;
  GPU gpu;
  Payment payment;
  OS os;
  Cabinet cabinet;

  public void print()
  {
    System.out.println("Cabinet:" + cabinet + "\n"+ "Display:" + display + "\n" + "Payment:" + payment + "\n" + "GPU:" + gpu + "\n" + "OS:" + os + "\n");
  }
}