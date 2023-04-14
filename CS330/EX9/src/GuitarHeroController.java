public class GuitarHeroController implements IGuitarController{
	public void PressFretButton(colors button)
	{
		if (button == colors.GREEN)
		{
			System.out.println("Pressing Green Button");
		}
		else if (button == colors.RED)
		{
			System.out.println("Pressing Red Button");
		}
		else if (button == colors.YELLOW)
		{
			System.out.println("Pressing Yellow Button");
		}
		else if (button == colors.BLUE)
		{
			System.out.println("Pressing Blue Button");
		}
		else if (button == colors.ORANGE)
		{
			System.out.println("Pressing Orange Button");
		}
	}
	public void PressPick()
	{
		System.out.println("Strumming Guitar with Pick");
	}
	public void PressTremelo()
	{
		System.out.println("Using Tremelo");
	}
}
