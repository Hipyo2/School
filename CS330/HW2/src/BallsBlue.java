
public class BallsBlue extends TreeDecoration{
	public BallsBlue(Tree tree)
	{
		this.tree = tree;
	}
	
	public boolean getTreeStar()
	{
		return tree.getTreeStar();
	}
	public void setTreeStar(boolean hasTreeStar)
	{
		tree.setTreeStar(hasTreeStar);
	}
	
	public double cost()
	{
		return 2 + tree.cost();
	}

	public String treeDesc()
	{
		
		return tree.treeDesc() + "blue balls, ";
	}
}
