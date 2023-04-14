public abstract class GameUnit {
    private IAttackBehavior attackBehavior;
    private IMovementBehavior movementBehavior;

    public void attack() {
//        attackBehavior.attack();
        System.out.println(this.getClass().getName() + ':' + attackBehavior.attack());
    }

    public void move() {
//        movementBehavior.move();
        System.out.println(this.getClass().getName() + ':' + movementBehavior.move());
    }

    public void setAttackBehavior(IAttackBehavior newAttackBehavior) {
        attackBehavior = newAttackBehavior;
    }

    public void setMovementBehavior(IMovementBehavior newMovementBehavior) {
        movementBehavior = newMovementBehavior;
    }
}
