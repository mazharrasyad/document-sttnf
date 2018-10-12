import java.util.Scanner;

public class No3
{
  public static void main(String [] args)
  {
    int value;

    Scanner in = new Scanner(System.in);

    do
    {
      System.out.print("Enter an integer < 100 : ");
      value = in.nextInt();
    }
    while(value >= 100);
  }
}
