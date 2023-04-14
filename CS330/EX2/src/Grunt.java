public class Grunt extends GameUnit {
    public Grunt() {
        System.out.println("New Grunt");

        setAttackBehavior(new AxeAttackBehavior());
        setMovementBehavior(new WalkingMovementBehavior());
    }
}
