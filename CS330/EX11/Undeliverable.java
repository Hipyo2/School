public class Undeliverable implements PizzaState{
    Pizza pizza;

    public Undeliverable(Pizza newPizza){
        pizza = newPizza;
    }

    public void bake(){
        System.out.println("Pizza is now cooked.");
        pizza.setPizzaState(pizza.getCookedState());
    }
    public void deliver(){
        System.out.println("Cannot deliver an undeliverable pizza.");
    }
}
