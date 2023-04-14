public class WashingtonFactory extends SlotMachineFactory{
    public SlotMachine createSlotMachine(String type)
    {
        if(type.equals("Straight"))
        {
            return new WAStyleStraight();
        }
        if(type.equals("Bonus"))
        {
            return new WAStyleBonus();
        }
        if (type.equals("Progressive"))
        {
            return new WAStyleProgressive();
        }
        return null;
    }
}
