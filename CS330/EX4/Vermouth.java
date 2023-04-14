public class Vermouth extends DrinkDecorator{
  public Vermouth(Drink drink)
  {
    this.drink = drink;
  } 
  
  public int calories()
  {
    return 40 + drink.calories();
  }
	public String getDesc()
  {
    return drink.getDesc() + " 1 oz Vermouth";
  }
	
}