public class orderComputer implements orderInterface{
	public int order(int numSI)
	{
		numSI = (int) (Math.random() * (3) + 1);
		System.out.println("Ordering with computer, Order Number: " + (int)(Math.random() * (100) + 1));
		System.out.println("Buying " + numSI + " shaved ices");
		return numSI;
	}
}
