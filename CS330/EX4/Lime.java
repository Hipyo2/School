public class Lime extends DrinkDecorator{
  public Lime(Drink drink)
  {
    this.drink = drink;
  }  
  public int calories()
  {
    return 2 + drink.calories();
  }
	public String getDesc()
  {
    return drink.getDesc() + " 1 Lime";
  }
}