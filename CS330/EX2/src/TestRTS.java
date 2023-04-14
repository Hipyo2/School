public class TestRTS {
    public static void main(String[] args) {
        GameUnit grunt = new Grunt();
        GameUnit tank = new Tank();
        grunt.move();
        tank.move();
        grunt.attack();
        tank.attack();

        System.out.println("\nGiving Grunt a Pistol");
        grunt.setAttackBehavior(new PistolAttackBehavior());
        grunt.attack();

        System.out.println("\nGiving Tank a Rocket");
        tank.setAttackBehavior(new RocketAttackBehavior());
        tank.attack();

        System.out.println("\nThey fly now!");
        tank.setMovementBehavior(new FlyingMovementBehavior());
        tank.move();
    }
}