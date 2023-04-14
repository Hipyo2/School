public class Baked implements PizzaState{
    Pizza pizza;

    public Baked(Pizza newPizza){
        pizza = newPizza;
    }

    public void bake(){
        System.out.println("Cannot bake a pizza that has already been baked.");
    }
    public void deliver(){
        System.out.println("Pizza has now been delivered.");
        pizza.setPizzaState(pizza.getDeliveredState());
    }
}
