public class CalculatorAdapter {
	public double getArea(Triangle triangle)
	{
		Calculator c = new Calculator();
		Rectangle rect = new Rectangle();
		
		//Area of Triangle=0.5*base*height
		rect.length = 0.5 * triangle.base;
		rect.width = triangle.height;
		return c.getArea(rect);
	}
}