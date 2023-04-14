public class Delivered implements PizzaState{
    Pizza pizza;

    public Delivered(Pizza newPizza){
        pizza = newPizza;
    }

    public void bake(){
        System.out.println("Cannot bake a delivered pizza.");
    }
    public void deliver(){
        System.out.println("Cannot deliver a pizza that has already been delivered.");
    }
}
