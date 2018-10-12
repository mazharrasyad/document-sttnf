import java.util.Scanner;

public class No2
{
  public static void main(String [] args)
  {
    int n, i, hasil = 0;

    Scanner in = new Scanner(System.in);

    System.out.print("Masukkan nilai n : ");
    n = in.nextInt();

    for(i = 1; i <= n; i++)
    {
      hasil = hasil + i;
    }
    System.out.println("Hasil Penjumlahan dari 1 sampai " + n + " : " + hasil);
  }
}
