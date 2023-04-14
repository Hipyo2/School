//Nicholas Ang
//CS330
//HW2 - Decorator


public class Main {
	public static void main(String[] args)
	{
		//Colorado blue spruce
		Tree mytree = new ColoradoBlueSpruce();
		mytree = new Star(mytree);
		mytree = new Ruffles(mytree);
		mytree = new Star(mytree);
		mytree = new Ruffles(mytree);
		mytree.printtree(mytree);
		System.out.print("\n");
		
		//FraserFir
		Tree mytree2 = new FraserFir();
		mytree2 = new Star(mytree2);
		mytree2 = new Star(mytree2);
		mytree2 = new Star(mytree2);
		mytree2 = new Ruffles(mytree2);
		mytree2 = new LEDS(mytree2);
		mytree2 = new Lights(mytree2);
		mytree2 = new BallsBlue(mytree2);
		mytree2.printtree(mytree2);
		System.out.print("\n");
		
		//Douglas Fir
		Tree mytree3 = new DouglasFir();
		mytree3 = new Star(mytree3);
		mytree3 = new BallsRed(mytree3);
		mytree3 = new BallsSilver(mytree3);
		mytree3 = new BallsBlue(mytree3);
		mytree3 = new Ribbons(mytree3);
		mytree3 = new Ribbons(mytree3);
		mytree3 = new Lights(mytree3);
		mytree3.printtree(mytree3);
		System.out.print("\n");
		
		//Balsam Fir
		Tree mytree4 = new BalsamFir();
		mytree4 = new Star(mytree4);
		mytree4 = new BallsRed(mytree4);
		mytree4 = new BallsSilver(mytree4);
		mytree4 = new BallsBlue(mytree4);
		mytree4 = new Ribbons(mytree4);
		mytree4 = new Ruffles(mytree4);
		mytree4 = new LEDS(mytree4);
		mytree4 = new Lights(mytree4);
		mytree4 = new Star(mytree4);
		mytree4.printtree(mytree4);
		System.out.print("\n");
	}
}
