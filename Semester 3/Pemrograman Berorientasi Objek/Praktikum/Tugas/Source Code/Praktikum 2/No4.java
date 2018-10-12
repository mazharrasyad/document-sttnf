import java.util.Scanner;

public class No4
{
  public static void main(String [] args)
  {
    int value;

    Scanner in = new Scanner(System.in);

    do
    {
      System.out.print("Enter an integer < 100 : ");
      value = in.nextInt();

      if(0 < value && value < 100)
      {
        System.out.println("Angka termasuk diantara 0 dan 100 yaitu : " + value);
      }
      else
      {
        System.out.println("Angka bukan termasuk diantara 0 dan 100 yaitu : " + value);
      }
    }
    while(value >= 100);
  }
}
