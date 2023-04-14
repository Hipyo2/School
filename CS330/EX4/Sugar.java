public class Sugar extends DrinkDecorator{
  public Sugar(Drink drink)
  {
    this.drink = drink;
  }  
  
  public int calories()
  {
    return 300 + drink.calories();
  }
	public String getDesc()
  {
    return drink.getDesc() + " 1 tsp Sugar";
  }
}