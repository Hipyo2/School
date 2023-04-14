public class payWCash implements paymentInterface{
	public void pay(int costSI, int numSI)
	{
		int cashGiven = (int) (Math.random() * (100) + 1);
		int totalCost = costSI * numSI;
		System.out.println("Paying with cash...");
		System.out.println("Sale Amount: " + totalCost);
		System.out.println("Cash Given: " + cashGiven);
		if(cashGiven >= totalCost)
		{
			int change = cashGiven - totalCost;
			System.out.println("Change Returned: " + change + "\n");
		}
		else
		{
			System.out.println("Not enough cash to buy shaved ice ...");
			System.out.println("Change Returned: " + cashGiven + "\n");
		}
	}
}
