
public class Lights extends TreeDecoration {
	public Lights(Tree tree)
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
		return 5 + tree.cost();
		
	}

	public String treeDesc()
	{
		
		return tree.treeDesc() + "lights, ";
	}
}
