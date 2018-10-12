import java.util.Scanner;

public class No5
{
  public static void main(String [] args)
  {
    int value = 101;

    Scanner in = new Scanner(System.in);

    while(100 < value)
    {
      System.out.print("Enter an integer < 100 : ");
      value = in.nextInt();
    }
  }
}
