public class ClassController {
	private Class model;
	private ClassView view;


	public ClassController(Class newModel, ClassView newView){
		this.model = newModel;
		this.view = newView;
	}

	public String getName(){
		return model.getName();
	}

	public void setName(String newName){
		model.setName(newName);
	}

	public String getDescription(){
		return model.getDesc();
	}

	public void setDescription(String newDescription){
		model.setDesc(newDescription);
	}

	public int getNumber(){
		return model.getNumber();
	}

	public void setNumber(int newNumber){
		model.setNumber(newNumber);
	}

	public void updateView(){
		view.printClassDetails(model.getName(), model.getNumber(), model.getDesc());
	}
}