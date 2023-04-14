
public class Star extends TreeDecoration{
	public int starCost = 4;
	public String starDesc = "star, ";
	public Star(Tree tree)
	{
		this.tree = tree;
		if(getTreeStar() == false)
		{
			tree.setTreeStar(true);
		}
		else
		{
			System.out.println("Tree already has a star!");
			starDesc = "";
			starCost = 0;
		}
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
		return starCost + tree.cost();
	}
	
	public String treeDesc()
	{
		return tree.treeDesc() + starDesc;
	}
}
