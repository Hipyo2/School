
public class Ribbons extends TreeDecoration {
	public Ribbons(Tree tree)
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
		
		return tree.treeDesc() + "ribbons, ";
	}
}
