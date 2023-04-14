class Main {
  public static void main(String[] args) {
    Prim object1 = new Object("Box");
    Prim sphere = new Sphere(3);
    Prim cylinder = new Cylinder(1,1);
    Prim box = new Box(1,1,2);
    System.out.println("Object composed of sphere, cylinder, and box");
    object1.add(sphere);
    object1.add(cylinder);
    object1.add(box);
    object1.print();

    System.out.println("Box");
    box.print();
  }
}