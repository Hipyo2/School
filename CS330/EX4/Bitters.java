public class Bitters extends DrinkDecorator {

	public Bitters(Drink drink) {
		this.drink = drink;
	}

	public int calories() {
		return 20 + drink.calories();
	}

	public String getDesc() {
		return drink.getDesc() + " 1 dash Bitters";
	}
}