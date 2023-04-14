public class Cooked implements PizzaState{
    Pizza pizza;

    public Cooked(Pizza newPizza){
        pizza = newPizza;
    }

    public void bake(){
        System.out.println("Pizza is now baked.");
        pizza.setPizzaState(pizza.getBakedState());
    }
    public void deliver(){
        System.out.println("Cannot deliver a pizza that has not been baked.");
    }
}
