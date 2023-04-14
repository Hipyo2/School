
public class Shake implements Command{
	ShortOrderCook cook;
	public Shake(ShortOrderCook cook)
	{
		this.cook = cook;
	}
	
	public void execute()
	{
		cook.makeShake("shake");
	}
}
