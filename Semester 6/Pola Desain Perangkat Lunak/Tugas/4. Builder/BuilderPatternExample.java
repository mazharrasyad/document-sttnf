public class BuilderPatternExample {
	public static void main(String[] args) 
	{
		System.out.println("NIM : 0110217029");
		System.out.println("***Builder Pattern Demo***");
		Director director = new Director();
		Builder fordCar = new Car("Ford");
		Builder hondaMotorycle = new Motorcycle("Honda");
		
		// Making Car
		director.construct(fordCar);
		Product p1 = fordCar.getVehicle();
		p1.showProduct();
		
		//Making MotorCycle
		director.construct(hondaMotorycle);
		Product p2 = hondaMotorycle.getVehicle();
		p2.showProduct();
	}
}