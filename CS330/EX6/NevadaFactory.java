public class NevadaFactory implements SlotMachineFactory{
  
  public SlotMachine makeSlotMachine(String type){
    SlotMachine aSlotMachine = new SlotMachine();
    aSlotMachine.cabinet = createCabinet(type);
    aSlotMachine.display = createDisplay(type);
    aSlotMachine.payment = createPayment(type);
    aSlotMachine.gpu = createGPU(type);
    aSlotMachine.os = createOS(type);

    return aSlotMachine;
  }
  public Cabinet createCabinet(String type){
    if(type == "Straight"){
      return new largeCabinet();
    }
    else if(type == "Bonus"){
      return new smallCabinet();
    }
    else if(type == "Progressive"){
      return new mediumCabinet();
    }
    return null;
  }
  public Display createDisplay(String type){
    if(type == "Straight"){
      return new reelsDisplay();
    }
    else if(type == "Bonus"){
      return new crtDisplay();
    }
    else if(type == "Progressive"){
      return new lcdDisplay();
    }
    return null;
  }
  public Payment createPayment(String type){
    if(type == "Straight"){
      return new ticketPayment();
    }
    else if(type == "Bonus"){
      return new ticketPayment();
    }
    else if(type == "Progressive"){
      return new ticketPayment();
    }
    return null;
  }
  public GPU createGPU(String type){
    if(type == "Straight"){
      return new Arm();
    }
    else if(type == "Bonus"){
      return new X86();
    }
    else if(type == "Progressive"){
     return new X77();
    }
    return null;
  }
  public OS createOS(String type){
    if(type == "Straight"){
      return new Linux();
    }
    else if(type == "Bonus"){
      return new Linux();
    }
    else if(type == "Progressive"){
      return new Android();
    }
    return null;
  }
  
}