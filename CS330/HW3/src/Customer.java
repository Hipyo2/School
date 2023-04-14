
public class Customer {
	public Command createOrder(ShortOrderCook cook, String food)
	{
		Command order = new noCommand();
		if (food == "burger")
		{
			order = new Burger(cook);
			return order;
		}
		else if (food == "shake")
		{
			order = new Shake(cook);
			return order;
		}
		return order;
	}
}
