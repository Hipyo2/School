public abstract class SlotMachineFactory { //abstract factory class

    public SlotMachine order(String type)
    {
        SlotMachine SlotMachine;
        SlotMachine = createSlotMachine(type);
        return SlotMachine;
    }
    protected abstract SlotMachine createSlotMachine(String type);

}
