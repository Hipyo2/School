//Written by Nicholas Ang
//CS330 HW1 - Strategy

public class TestDriver {
	public static void main(String[] args) {
		shaveIceShop kiosk = new kiosk();
		shaveIceShop store = new store();
		kiosk.describeShop();
		System.out.println("Current price of shaved ice at Kiosk: " + kiosk.costSI);
		store.describeShop();
		System.out.println("Current price of shaved ice at Store: " + store.costSI);
		
		//Customer 1 - Cash, Kiosk
		System.out.println("\nCustomer 1 has arrived at a kiosk");
		System.out.println("Customer 1 has cash");
		kiosk.order();
		kiosk.pay();
		
		//Customer 2 - Credit Card Attempt, Cash, Kiosk
		System.out.println("\nCustomer 2 has arrived at a kiosk");
		System.out.println("Customer 2 has credit card");
		if(kiosk.getCardAccepted() == 1)
		{
			kiosk.setPayment(new payWCard());
		}
		else
		{
			System.out.println("This establishment does not accept credit card... Please pay with cash");
		}
		System.out.println("Customer 2 takes out cash");
		kiosk.order();
		kiosk.pay();
		
		//Customer 3 - Cash, Store
		System.out.println("\nCustomer 3 has arrived at a store");
		System.out.println("Customer 3 has cash");
		store.order();
		store.pay();
		
		//Customer 4 - Credit Card, Store
		System.out.println("\nCustomer 4 has arrived at a store");
		System.out.println("Customer 4 has credit card");
		if(store.getCardAccepted() == 1)
		{
			store.setPayment(new payWCard());
		}
		else
		{
			System.out.println("This establishment does not accept credit card... Please pay with cash");
		}
		store.order();
		store.pay();
	}
}
