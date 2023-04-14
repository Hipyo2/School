public class NevadaFactory extends SlotMachineFactory {
    public SlotMachine createSlotMachine(String type)
    {
        if(type.equals("Straight"))
        {
            return new NVStyleStraight();
        }
        if(type.equals("Bonus"))
        {
            return new NVStyleBonus();
        }
        if(type.equals("Progressive"))
        {
            return new NVStyleProgressive();
        }
        return new SlotMachine();
    }
    
}
