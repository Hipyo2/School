
public class Ruffles extends TreeDecoration {
	public Ruffles(Tree tree)
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
		return 1 + tree.cost();
		
	}

	public String treeDesc()
	{
		
		return tree.treeDesc() + "ruffles, " ;
	}
}
