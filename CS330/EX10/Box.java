public class Box extends Prim{
  float base;
  float width;
  float height;

  public Box(float n , float m, float o)
  {
    this.base = n;
    this.width = m;
    this.height = o;
  }
  
  public void setBase(float n)
  {
    base = n;
  }
  public void setWidth(float n)
  {
    width = n;
  }
  public void setHeight(float n)
  {
    height=  n;
  }
  public float getVolume()
  {
    return base * width * height;
  }
    public void print()
  {
    System.out.println("Volume: " +getVolume());
  }
}