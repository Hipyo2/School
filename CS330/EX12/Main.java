class Main {
  public static void main(String[] args) {
    Class model = new Class();
    ClassView view = new ClassView();
		ClassController controller = new ClassController(model, view);
    model.setName("CS330");
    model.setNumber(10);
    model.setDesc("Class about learning design patterns");





		controller.updateView();

    controller.setName("CS477");
    controller.setDescription("Class about algorithms or something");
    controller.setNumber(3);
    controller.updateView();
  }
}