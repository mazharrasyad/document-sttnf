// final class Captain {
// 	private static Captain captain;
// 	//We make the constructor private to prevent the use of "new"
// 	private Captain() { }
// 	public static synchronized Captain getCaptain()
// 	{
// 	// Lazy initialization
// 	if (captain == null)
// 	{
// 	captain = new Captain();
// 	System.out.println("New captain is elected for your team.");
// 	}
// 	else
// 	{
//     System.out.print("You already have a captain for your team.");
//     System.out.println("Send him for the toss.");
// 	}
// 	return captain;
// 	}
// }

// ----- Eager
public class Captain {
	//Early initialization
	private static final Captain captain = new Captain();
	//We make the constructor private to prevent the use of "new"
	private Captain()
	{
	System.out.println("A captain is elected for your team.");
	}
	/* Global point of access.The method getCaptain() is a public static
	method*/
	public static Captain getCaptain()
	{
	System.out.println("You have a captain for your team.");
	return captain;
	}
	public static void dummyMethod()
	{
		System.out.println("It is a dummy method");
	}
}