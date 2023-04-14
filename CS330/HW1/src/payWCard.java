public class payWCard implements paymentInterface{
	public void pay(int costSI, int numSI)
	{
		int cardNumber =(int) (Math.random() * (1000000000) + 1000000000);
		int totalCost = costSI * numSI;
		System.out.println("Paying with a credit card...");
		System.out.println("Card Number: " + cardNumber);
		System.out.println("Sale Amount: " + totalCost + "\n");
	}
}
