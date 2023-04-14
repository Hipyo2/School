
public class LEDS extends TreeDecoration {
	public LEDS(Tree tree)
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
		return 10 + tree.cost();
		
	}

	public String treeDesc()
	{
		
		return tree.treeDesc() + "LEDS, ";
	}
}
