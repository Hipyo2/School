import java.util.*;

public class Object extends Prim{
  List<Prim> prims = new ArrayList<Prim>();
  String name;
  float totalVolume;

  public Object(String name)
  {
    this.name = name;
  }

  public void add(Prim prim)
  {
    prims.add(prim);
  }

  public void remove(Prim prim)
  {
    prims.remove(prim);
  }

  public void getTotalVolume()
  {
    float totalVolume = 0;
    for(Prim prim: prims)
    {
      totalVolume += prim.getVolume();
    }
    this.totalVolume = totalVolume;
  }

  public void print()
  {
    getTotalVolume();
    System.out.println("Total Volume: "+ totalVolume);
  }
}