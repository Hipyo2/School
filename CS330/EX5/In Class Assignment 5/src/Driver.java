public class Driver {
    public static void main(String[] args) throws Exception {
        System.out.println("IN CLASS ASSIGNMENT 5");
        System.out.println("Nevada Slots");
        SlotMachineFactory  sFactory= new NevadaFactory();
        SlotMachine slot1 = sFactory.order("Straight");
        slot1.print();
        SlotMachine slot2 = sFactory.order("Bonus");
        slot2.print();
        SlotMachine slot3 = sFactory.order("Progressive");
        slot3.print();
        
        System.out.println("New Jersey Slots");
        SlotMachineFactory  nFactory= new NewJerseyFactory();
        SlotMachine slot4 = nFactory.order("Straight");
        slot4.print();
        SlotMachine slot5 = nFactory.order("Bonus");
        slot5.print();
        SlotMachine slot6 = nFactory.order("Progressive");
        slot6.print();

        System.out.println("Washington Slots");
        SlotMachineFactory  mFactory= new WashingtonFactory();
        SlotMachine slot7 = mFactory.order("Straight");
        slot7.print();
        SlotMachine slot8 = mFactory.order("Bonus");
        slot8.print();
        SlotMachine slot9 = mFactory.order("Progressive");
        slot9.print();
    }
}
