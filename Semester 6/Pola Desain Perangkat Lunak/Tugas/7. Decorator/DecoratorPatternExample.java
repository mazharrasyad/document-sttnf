public class DecoratorPatternExample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("NIM : 0110217029");
		System.out.println("***Decorator pattern Demo***\n");
		ConcreteComponent withoutDecorator = new ConcreteComponent();
		withoutDecorator.makeHouse();
		
		System.out.println("_________________");
		
		//Using a decorator to add floor
		System.out.println("Using a Floor decorator now.");
		FloorDecorator floorDecorator = new FloorDecorator();
		floorDecorator.setTheComponent(withoutDecorator);
		floorDecorator.makeHouse();
		
		System.out.println("_________________");
		
		//Using a decorator to add floor to original house and then
		//paint it.
		System.out.println("Using a Paint decorator now.");
		PaintDecorator paintDecorator = new PaintDecorator();
		//Adding results from floor decorator
		paintDecorator.setTheComponent(withoutDecorator);
		paintDecorator.makeHouse();
		System.out.println("_________________");

	}

}