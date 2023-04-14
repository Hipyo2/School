public class Cylinder extends Prim{
  float height;
  float radius;
  public Cylinder(float n, float m)
  {
    this.height = n;
    this.radius = m;
  }
  
  public void setheight (float n)
  {
    height = n;
  }
  public void setradius(float n)
  {
    radius = n;
  }
  public float getVolume()
  {
    return 3.14159f * radius * radius * height;
  }
  public void print()
  {
    System.out.println("Volume: " +getVolume());
  }
}