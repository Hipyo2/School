package observer;

import java.util.ArrayList;

public class Baby implements Subject{
	private boolean isCrying;
	private int soundLevel;
	private ArrayList observers;
	private String name;
	
	public Baby()
	{
		observers = new ArrayList();
	}
	
	
	public void add(Observer o) 
	{
		observers.add(o);
	}
	public void remove(Observer o) 
	{
		int i = observers.indexOf(o);
		observers.remove(i);
	}
	public void inform() 
	{
		for(int i = 0; i < observers.size(); i++)
		{
			Observer observer = (Observer) observers.get(i);
			observer.update(soundLevel);
		}
	}
	public void setSoundLevel(int a)
	{
		soundLevel = a;
		inform();
	}
	public int getSoundLevel()
	{
		return soundLevel;
	}
	public void setIsCrying(boolean b)
	{
		isCrying = b;
		inform();
	}
	public boolean getIsCrying()
	{
		return isCrying;
	}

}
	