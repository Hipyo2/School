public class NewJerseyFactory extends SlotMachineFactory{
    public SlotMachine createSlotMachine(String type)
    {
        if(type.equals("Straight"))
        {
            return new NJStyleStraight();
        }
        if(type.equals("Bonus"))
        {
            return new NJStyleBonus();
        }
        if(type.equals("Progressive"))
        {
            return new NJStyleProgressive();
        }
        return null;
    }
}
