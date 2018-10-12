import java.util.Scanner;

public class No7
{
  public static void main(String [] args)
  {
    int angka, jumlah = 0;

    Scanner in = new Scanner(System.in);

    do
    {
      System.out.print("Masukkan angka : ");
      angka = in.nextInt();
      jumlah = jumlah + angka;
    }
    while(angka != 0);
    System.out.println("\nAnda telah memasukkan angka 0");
    System.out.println("Jumlah angka sebelumnya adalah " + jumlah);
  }
}
