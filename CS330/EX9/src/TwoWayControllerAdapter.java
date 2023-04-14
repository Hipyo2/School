public class TwoWayControllerAdapter implements IDanceController, IGuitarController{
	private GuitarHeroController guitarC;
	private DancePad danceC;
	
	public TwoWayControllerAdapter(DancePad danceC)
	{
		//For Guitar to Dance Pad
		this.danceC = danceC;
	}
	
	public TwoWayControllerAdapter(GuitarHeroController guitarC)
	{
		//For Dance Pad to Guitar
		this.guitarC = guitarC;
	}
	
	//For Guitar to Dance Pad
	public void PressFretButton(colors button)
	{
		if (button == colors.GREEN)
		{
			System.out.println("Pressing Green Button");
			danceC.Step(direction.FORWARD);
		}
		else if (button == colors.RED)
		{
			System.out.println("Pressing Red Button");
			danceC.Step(direction.LEFT);
		}
		else if (button == colors.YELLOW)
		{
			System.out.println("Pressing Yellow Button");
			danceC.Step(direction.RIGHT);
		}
		else if (button == colors.BLUE)
		{
			System.out.println("Pressing Blue Button");
			danceC.Step(direction.BACK);
		}
		else if (button == colors.ORANGE)
		{
			System.out.println("Pressing Orange Button");
			danceC.Step(direction.MIDDLE);
		}
	}
	//For Guitar to Dance Pad
	public void PressPick()
	{
		System.out.println("Strumming Guitar with Pick");
		System.out.println("Nothing else happens...");
	}
	public void PressTremelo()
	{
		System.out.println("Using Tremelo");
		System.out.println("Nothing else happens...");
	}
	
	
	//For Dance Pad to Guitar
	public void Step(direction dir)
	{
		if (dir == direction.FORWARD)
		{
			System.out.println("Stepping Forward");
			guitarC.PressFretButton(colors.GREEN);
			guitarC.PressPick();
		}
		else if (dir == direction.LEFT)
		{
			System.out.println("Stepping Left");
			guitarC.PressFretButton(colors.RED);
			guitarC.PressPick();
		}
		else if (dir == direction.RIGHT)
		{
			System.out.println("Stepping Right");
			guitarC.PressFretButton(colors.YELLOW);
			guitarC.PressPick();
		}
		else if (dir == direction.BACK)
		{
			System.out.println("Stepping Back");
			guitarC.PressFretButton(colors.BLUE);
			guitarC.PressPick();
		}
		else if (dir == direction.MIDDLE)
		{
			System.out.println("Stepping Middle");
			guitarC.PressFretButton(colors.ORANGE);
			guitarC.PressPick();
		}
	}
}
