public abstract class AbstractDecorator {
	protected Component component ;
	
	public void setTheComponent(Component c)
	{
		component = c;
	}
	
	public void makeHouse()
	{
		if (component != null)
		{
			component.makeHouse();//Delegating the task
		}
	}
}