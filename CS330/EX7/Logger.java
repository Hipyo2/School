import java.time.LocalDateTime;  
import java.time.format.DateTimeFormatter;  


public class Logger{
  private static Logger uniqueInstance;
  
  private Logger(){};

  public static synchronized Logger getInstance()
  {
    if(uniqueInstance == null)
    {
      uniqueInstance = new Logger();
    }
    return uniqueInstance;
  }


  public void info ()
  {
    java.util.Date date = new java.util.Date();    
    System.out.println(date);    
  }
  
  public void warn()
  {
    System.out.println("WARNING: Unexpected problem occurred birthday invalid");
    System.out.print("Date and time error occured is: ");
  }

  public void debug(String debugString)
  {
    System.out.print("Log: ");
    System.out.println(debugString);
  }
}