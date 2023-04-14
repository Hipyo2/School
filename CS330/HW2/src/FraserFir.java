
public class FraserFir extends Tree{
	public double cost()
	{
		return 12;
		
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
		
		return "Fraser fir tree with ";
	}
}
