
public abstract class Tree {
	public boolean treeStar = false;
	public abstract double cost();
	public void printtree(Tree tree)
	{
		System.out.println(tree.treeDesc() + "with cost: " + tree.cost());
	}
	public abstract boolean getTreeStar();
	public abstract void setTreeStar(boolean hasTreeStar);
	public abstract String treeDesc();
}
