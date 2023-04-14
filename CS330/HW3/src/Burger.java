
public class Burger implements Command{
	ShortOrderCook cook;
	public Burger(ShortOrderCook cook)
	{
		this.cook = cook;
	}
	
	public void execute()
	{
		cook.makeBurger("burger");
	}
}
