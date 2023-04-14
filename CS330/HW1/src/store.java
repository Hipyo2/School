public class store extends shaveIceShop{
	public store()
	{
		System.out.println("Store has spawned in");
		setPayment(new payWCash());
		setOrder(new orderComputer());
		setCardAccepted(1);
		setCostSI(15);
	}
	
	public void describeShop()
	{
		System.out.println("This is a store");
	}
}
