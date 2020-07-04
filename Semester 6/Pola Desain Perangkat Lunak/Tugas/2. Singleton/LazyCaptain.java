public class LazyCaptain {
	private static LazyCaptain lazyCaptain;
    // We make the constructor private to prevent the use of "new"
    
	private LazyCaptain() {
	}

	public static LazyCaptain getCaptain() {
		// Lazy initialization
		if (lazyCaptain == null) {
			lazyCaptain = new LazyCaptain();
			System.out.println("New captain is elected for your team.");
		} else {
			System.out.print("You already have a captain for your team.");
			System.out.println("Send him for the toss.");
		}
		return lazyCaptain;
	}

	public static void main(String[] args) {
		System.out.println("NIM : 0110217029\n");
		System.out.println("***Singleton Pattern Demo***\n");
		System.out.println("Trying to make a captain for your team with lazy style:");
		
		LazyCaptain captain1 = LazyCaptain.getCaptain();
		System.out.println("Captain1:" + captain1);
		
		LazyCaptain captain2 = LazyCaptain.getCaptain();
		System.out.println("Captain2:" + captain2);
	}
}