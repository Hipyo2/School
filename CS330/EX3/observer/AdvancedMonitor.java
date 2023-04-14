package observer;

public class AdvancedMonitor implements Observer {
	private int soundLevel;
	private Subject Baby;
	
	public AdvancedMonitor(Subject s)
	{
		Baby = s;
	}
	
	public void update(int inSoundLevel) 
	{
		soundLevel = inSoundLevel;
		if(soundLevel == 0)
		{
			System.out.println("The baby is sobbing");
		}
		else if (soundLevel == 1)
		{
			System.out.println("The baby is crying");
		}
		else if (soundLevel == 2)
		{
			System.out.println("The baby is screaming");
		}
	}
}
