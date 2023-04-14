public class Main {
	public static void main(String[] args)
	{
		GuitarHeroController guitarController = new GuitarHeroController();
		DancePad danceController = new DancePad();
		TwoWayControllerAdapter adapter1 = new TwoWayControllerAdapter(guitarController);
		TwoWayControllerAdapter adapter2 = new TwoWayControllerAdapter(danceController);
		
		System.out.print("Guitar Controller\n");
		guitarController.PressFretButton(IGuitarController.colors.GREEN);
		guitarController.PressTremelo();
		guitarController.PressFretButton(IGuitarController.colors.BLUE);
		guitarController.PressPick();
		
		System.out.print("\nDance Pad Controller\n");
		danceController.Step(IDanceController.direction.FORWARD);
		danceController.Step(IDanceController.direction.BACK);
		danceController.Step(IDanceController.direction.MIDDLE);
		
		System.out.print("\nAdapting Guitar Hero with Dance Pad Controller\n");
		adapter1.Step(IDanceController.direction.LEFT);
		adapter1.Step(IDanceController.direction.RIGHT);
		
		System.out.print("\nAdapting Dance Dance Revolution with Guitar Controller\n");
		adapter2.PressFretButton(IGuitarController.colors.ORANGE);
		adapter2.PressFretButton(IGuitarController.colors.RED);
		adapter2.PressFretButton(IGuitarController.colors.YELLOW);
		adapter2.PressTremelo();
		adapter2.PressPick();
	}
}
