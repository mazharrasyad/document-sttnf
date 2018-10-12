import java.util.Scanner;

public class praktikum2if
{
  public static void main(String args[])
  {
    int a = 0;
    int b = 0;

    Scanner masuk = new Scanner(System.in);

    System.out.print("Masukkan Angka Pertama : ");
    a = masuk.nextInt();
    System.out.print("Masukkan Angka Kedua : ");
    b = masuk.nextInt();

    if(a > b)
    {
      System.out.println("Angka pertama lebih besar dari angka kedua");
    }
    else if(a == b)
    {
      System.out.println("Angka pertama sama dengan angka kedua");
    }
    else
    {
      System.out.println("Angka kedua lebih besar dari angka pertama");
    }
  }
}
