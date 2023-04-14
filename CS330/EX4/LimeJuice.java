public class LimeJuice extends DrinkDecorator{
  public LimeJuice(Drink drink)
  {
    this.drink = drink;
  }
  public int calories()
  {
    return 8 + drink.calories();
  }
	public String getDesc()
  {
    return drink.getDesc() + " 1 oz Lime Juice";
  }
}