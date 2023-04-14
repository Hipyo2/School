
public class Waitress {
	Command[] orderSlip;
	
	public Waitress()
	{
		orderSlip = new Command[5];
		for (int i = 0; i < 5; i++)
		{
			orderSlip[i] = new noCommand();
		}
	}
	
	//Take order function
	public void setCommand(Command command, int slot)
	{
		orderSlip[slot] = command;
	}
	
	//Order up function
	public void giveCook()
	{
		System.out.println("Getting order from customer");
		System.out.println("Order Up!!");
		for (int i = 0; i < 5; i++)
		{
			orderSlip[i].execute();
		}
	}
}
