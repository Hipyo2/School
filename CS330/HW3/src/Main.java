//Nicholas Ang
//CS330
//HW3 - Command

public class Main {
	public static void main(String[] args)
	{
		System.out.println("Cool Burger/Shake Restaurant!!\n");
		
		//Customer 1
		Command noCommand = new noCommand();
		ShortOrderCook cook = new ShortOrderCook();
		Customer customer1 = new Customer();
		System.out.println("Customer 1 wants a burger and a shake");
		Waitress waitress = new Waitress();
		Command order = customer1.createOrder(cook, "burger");
		waitress.setCommand(order,0);
		order = customer1.createOrder(cook, "shake");
		waitress.setCommand(order,1);
		waitress.giveCook();
		waitress.setCommand(noCommand, 0);
		waitress.setCommand(noCommand, 1);
		System.out.print("\n");
		
		//Customer 2
		Customer customer2 = new Customer();
		System.out.println("Customer 2 wants just a burger");
		Command order2 = customer2.createOrder(cook, "burger");
		waitress.setCommand(order2,0);
		waitress.giveCook();
		waitress.setCommand(noCommand, 0);
		System.out.print("\n");
		
		//Customer 3
		Customer customer3 = new Customer();
		System.out.println("Customer 3 wants just a shake");
		Command order3 = customer3.createOrder(cook, "shake");
		waitress.setCommand(order3,0);
		waitress.giveCook();
		waitress.setCommand(noCommand, 0);
		System.out.print("\n");
	}
}
