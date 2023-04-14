package observer;

public class SimpleMonitor implements Observer{
	private boolean isCrying;
	private Subject Baby;
	
	public SimpleMonitor(Subject s)
	{
		Baby = s;
	}
	public void update(int inSoundLevel) 
	{
		if(inSoundLevel > 1)
		{
			isCrying = true;
		}
		else
			isCrying = false;
		display();
	}
	public void display() {
		System.out.println("Baby is crying: " + isCrying);
	}
}
