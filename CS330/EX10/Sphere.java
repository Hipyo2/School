public class Sphere extends Prim{
  float radius;
  public Sphere(float n)
  {
    this.radius = n;
  }
  public void setradius(float n)
  {
    radius = n;
  }
  public float getVolume()
  {
    return 4/3 * 3.14159f * radius * radius;
  }

  public void print()
  {
    System.out.println("Volume: " +getVolume());
  }
}