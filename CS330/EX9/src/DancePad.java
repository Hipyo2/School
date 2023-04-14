public class DancePad implements IDanceController{
	public void Step(direction dir)
	{
		if (dir == direction.FORWARD)
		{
			System.out.println("Stepping Forward");
		}
		else if (dir ==direction.LEFT)
		{
			System.out.println("Stepping Left");
		}
		else if (dir == direction.RIGHT)
		{
			System.out.println("Stepping Right");
		}
		else if (dir == direction.BACK)
		{
			System.out.println("Stepping Back");
		}
		else if (dir == direction.MIDDLE)
		{
			System.out.println("Stepping Middle");
		}
	}
}
