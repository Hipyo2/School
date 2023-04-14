public class kiosk extends shaveIceShop{
	public kiosk()
	{
		System.out.println("Kiosk has spawned in");
		setPayment(new payWCash());
		setOrder(new orderTicket());
	}
	
	public void describeShop()
	{
		System.out.println("This is a kiosk");
	}
}
