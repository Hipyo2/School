public interface IDanceController {
	public static enum direction {FORWARD,LEFT,RIGHT, BACK, MIDDLE}
	public void Step(direction dir);
}
