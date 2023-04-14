public class NewJerseyFactory implements SlotMachineFactory{
  
  public SlotMachine makeSlotMachine(String type)
  {
    SlotMachine aSlotMachine = new SlotMachine();
    aSlotMachine.cabinet = createCabinet(type);
    aSlotMachine.display = createDisplay(type);
    aSlotMachine.payment = createPayment(type);
    aSlotMachine.gpu = createGPU(type);
    aSlotMachine.os = createOS(type);
    
    return aSlotMachine;
  }
  public GPU createGPU(String type)
  {
    if(type == "Straight")
    {
      return new Arm();
    }
    else if(type == "Bonus")
    {
      return new Arm();
    }
    else if(type == "Progressive")
    {
      return new X86();
    }
    else
    {
      return new Arm();
    }
  }
  public OS createOS(String type)
  {
    if(type == "Straight")
    {
      return new WindowsME();
    }
    else if(type == "Bonus")
    {
      return new WindowsME();
    }
    else if(type == "Progressive")
    {
      return new WindowsXP();
    }
    else
    {
      return new WindowsME();
    }
  }
  public Payment createPayment(String type)
  {
    if(type == "Straight")
    {
      return new coinPayment();
    }
    else if(type == "Bonus")
    {
      return new coinPayment();
    }
    else if(type == "Progressive")
    {
      return new billPayment();
    } 
    else
    {
      return new coinPayment();
    }
  }
  public Cabinet createCabinet(String type)
  {
    if(type == "Straight")
    {
      return new smallCabinet();
    }
    else if(type == "Bonus")
    {
      return new largeCabinet();
    }
    else if(type == "Progressive")
    {
      return new smallCabinet();
    }
    else
    {
      return new smallCabinet();
    }
  }
  public Display createDisplay(String type)
  {
    if(type == "Straight")
    {
      return new lcdDisplay();
    }
    else if(type == "Bonus")
    {
      return new reelsDisplay();
    }
    else if(type == "Progressive")
    {
      return new crtDisplay();
    }
    else
    {
      return new lcdDisplay();
    }
  }
}