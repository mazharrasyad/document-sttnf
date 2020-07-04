public class FloorDecorator extends AbstractDecorator
{
	public void makeHouse()
	{
		super.makeHouse();
		//Decorating now.
		System.out.println("***Floor decorator is in action***");
		addFloor();
		/*You can put additional stuffs as per your need*/

	}
	
	private void addFloor()
	{
		System.out.println("I am making an additional floor on top of it.");
	}
}