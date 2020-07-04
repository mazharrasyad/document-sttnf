public class Car implements Builder{
	private String brandName;
    private Product product;
    
	public Car(String brand)
	{
		product = new Product();
		this.brandName = brand;
    }
    
	public void startUpOperations()
	{
		//Starting with brand name
		product.add(String.format("Car model is :%s",this.brandName));
    }
    
	public void buildBody()
	{
		product.add("This is a body of a Car");
    }
    
	public void insertWheels()
	{
		product.add("4 wheels are added");
    }
    
	public void addHeadlights()
	{
		product.add("2 Headlights are added");
    }
    
	public void endOperations()
    { //Nothing in this case
    }
    
	public Product getVehicle()
	{
		return product;
	}
}