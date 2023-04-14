public class WashingtonFactory implements SlotMachineFactory{
  
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
      return new mediumCabinet();
    }
    else if(type == "Progressive"){
      return new largeCabinet();
    }
    return null;
  }
  public Display createDisplay(String type){
    if(type == "Straight"){
      return new reelsDisplay();
    }
    else if(type == "Bonus"){
      return new vgaDisplay();
    }
    else if(type == "Progressive"){
      return new reelsDisplay();
    }
    return null;
  }
  public Payment createPayment(String type){
    if(type == "Straight"){
      return new billPayment();
    }
    else if(type == "Bonus"){
      return new ticketPayment();
    }
    else if(type == "Progressive"){
      return new coinPayment();
    }
    return null;
  }
  public GPU createGPU(String type){
    if(type == "Straight"){
      return new Arm();
    }
    else if(type == "Bonus"){
      return new Arm();
    }
    else if(type == "Progressive"){
      return new Arm();
    }
    return null;
  }
  public OS createOS(String type){
    if(type == "Straight"){
      return new Linux();
    }
    else if(type == "Bonus"){
      return new Symbian();
    }
    else if(type == "Progressive"){
      return new Android();
    }
    return null;
  }
}