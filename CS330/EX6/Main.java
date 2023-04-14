class Main {
  public static void main(String[] args) {
    NevadaFactory factory1 = new NevadaFactory();
    NewJerseyFactory factory2 = new NewJerseyFactory();
    WashingtonFactory factory3 = new WashingtonFactory();
    SlotMachine SlotMachine1 = factory1.makeSlotMachine("Straight");
    SlotMachine SlotMachine2 = factory2.makeSlotMachine("Straight");
    SlotMachine SlotMachine3 = factory3.makeSlotMachine("Straight");
    SlotMachine1.print();
    SlotMachine2.print();
    SlotMachine3.print();

    SlotMachine SlotMachine4 = factory1.makeSlotMachine("Bonus");
    SlotMachine SlotMachine5 = factory2.makeSlotMachine("Bonus");
    SlotMachine SlotMachine6 = factory3.makeSlotMachine("Bonus");
    SlotMachine4.print();
    SlotMachine5.print();
    SlotMachine6.print();

    SlotMachine SlotMachine7 = factory1.makeSlotMachine("Progressive");
    SlotMachine SlotMachine8 = factory2.makeSlotMachine("Progressive");
    SlotMachine SlotMachine9 = factory3.makeSlotMachine("Progressive");
    SlotMachine7.print();
    SlotMachine8.print();
    SlotMachine9.print();
    
  }
}