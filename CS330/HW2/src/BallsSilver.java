
public class BallsSilver extends TreeDecoration {
	public BallsSilver(Tree tree)
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
		return 3 + tree.cost();
		
	}

	public String treeDesc()
	{
		
		return tree.treeDesc() + "silver balls, ";
	}
}
