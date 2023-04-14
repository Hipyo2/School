public class SlotMachine { //Concrete Class

    String Cabinet;
    String Display;
    String Payment;
    String GPU;
    String OS;
    public void print()
    {
        System.out.println("fetching components: " + Cabinet + " Cabinet," + Payment + " validator,"+ Display + " display " + GPU);
        System.out.println("Assembling components");
        System.out.println("Testing Hardware");
        System.out.println("Assembling components");
        System.out.println("Uploading Software: "+ OS);
        System.out.println("Testing Software");
    }
}
