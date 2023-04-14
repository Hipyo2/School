class Main {
	public static void main(String[] args) {
    //Old Fashioned
    Drink drink = new Bourbon();
		drink = new Bitters(drink);
		drink = new Bitters(drink);
		drink = new Cherry(drink);
		drink = new Lime(drink);

    System.out.println("Old Fashioned:");
		System.out.println(drink.getDesc() + ": " + drink.calories());

    //Vodka Gimlet
    Drink drink2 = new Vodka();
		drink2 = new LimeJuice(drink2);
		drink2 = new Lime(drink2);

    System.out.println("\nVodka Gimlet:");
		System.out.println(drink2.getDesc() + ": " + drink2.calories());

    //Manhatten
    Drink drink3 = new Bourbon();
		drink3 = new Vermouth(drink3);
    drink3 = new Vermouth(drink3);
    drink3 = new Cherry(drink3);
		drink3 = new Bitters(drink3);

    System.out.println("\nManhatten: ");
		System.out.println(drink3.getDesc() + ": " + drink3.calories());

    //Tom Collins
    Drink drink4 = new Gin();
		drink4 = new LimeJuice(drink4);
    drink4 = new LimeJuice(drink4);
    drink4 = new Sugar(drink4);
		drink4 = new Sugar(drink4);
    drink4 = new Lime(drink4);

    System.out.println("\nTom Collins:");
		System.out.println(drink4.getDesc() + ": " + drink4.calories());
	}
}
