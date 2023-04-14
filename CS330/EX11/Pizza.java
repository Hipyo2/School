public class Pizza {
    PizzaState cooked;
    PizzaState baked;
    PizzaState delivered;
    PizzaState undeliverable;
    PizzaState pizzaState;

    public Pizza(){
        cooked = new Cooked(this);
        baked = new Baked(this);
        delivered = new Delivered(this);
        undeliverable = new Undeliverable(this);

        pizzaState = undeliverable;
    }

    public void setPizzaState(PizzaState newState){
        pizzaState = newState;
    }

    public void bake(){
        pizzaState.bake();
    }

    public void deliver(){
        pizzaState.deliver();
    }

    public void eat(){
      System.out.println("Pizza has been eaten by the staff!");
      pizzaState = undeliverable;
    }
  
    public PizzaState getCookedState(){
        return cooked;
    }

    public PizzaState getBakedState(){
        return baked;
    }

    public PizzaState getDeliveredState(){
        return delivered;
    }

    public PizzaState getUndeliverableState(){
        return undeliverable;
    }
}
