import java.util.Scanner;

public class No6
{
  public static void main(String [] args)
  {
    int angka;

    Scanner in = new Scanner(System.in);

    do
    {
      System.out.print("Masukkan angka : ");
      angka = in.nextInt();
    }
    while(angka != 0);
    System.out.println("\nAnda telah memasukkan angka 0");
  }
}
