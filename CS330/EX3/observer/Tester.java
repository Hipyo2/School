package observer;

public class Tester {

	public static void main(String[] args) {
		Subject baby1 = new Baby();
		Observer simpleMonitor1 = new SimpleMonitor(baby1);
		Observer advancedMonitor1 = new AdvancedMonitor(baby1);	
		
		baby1.add(simpleMonitor1);
		baby1.add(advancedMonitor1);
		
		System.out.print("We make the baby cry loudly\n");
		((Baby) baby1).setSoundLevel(2);

		
		System.out.println("\n\nThe baby sobs");
		((Baby) baby1).setSoundLevel(0);
		
		Subject baby2 = new Baby();
		
		baby2.add(advancedMonitor1);
		
		System.out.println("\n\nBaby 2 is crying");
		((Baby) baby2).setSoundLevel(1);
		((Baby) baby1).setSoundLevel(2);//the output has the simple monitor because we change the baby1 values. Note that the baby 1 and 2 values are correct otherwise
		
		
		
	}

}
