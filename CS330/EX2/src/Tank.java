public class Tank extends GameUnit{
    public Tank() {
        System.out.println("New Tank");

        setAttackBehavior(new CanonAttackBehavior());
        setMovementBehavior(new DriveMovementBehavior());
    }
}
