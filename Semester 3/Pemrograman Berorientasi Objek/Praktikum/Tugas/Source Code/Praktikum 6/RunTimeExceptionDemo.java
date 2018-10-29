import java.util.Scanner;

public class RunTimeExceptionDemo 
{
	public static void main(String[] args) 
	{
		//Reading user input
		Scanner inputDevice = new Scanner(System.in);
		System.out.print("Please enter your age- Numeric value: ");
		int age = inputDevice.nextInt();
		if (age>18)
		{
			System.out.println("You are authorized to view the page");
			//Other business logic
		}
		else 
		{
			System.out.println("You are not authorized to view page");
			//Other code related to logout
		}
	}

}