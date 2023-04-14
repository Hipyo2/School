
public class DouglasFir  extends Tree{
	public double cost()
	{
		return 15;
		
	}

	public boolean getTreeStar()
	{
		return treeStar;
	}
	public void setTreeStar(boolean hasTreeStar)
	{
		treeStar = hasTreeStar;
	}
	
	public String treeDesc()
	{
		
		return "Douglas Fir tree with ";
	}
}
