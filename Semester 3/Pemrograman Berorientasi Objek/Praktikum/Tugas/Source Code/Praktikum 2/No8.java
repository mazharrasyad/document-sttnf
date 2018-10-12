import java.util.Scanner;

public class No8
{
  public static void main(String [] args)
  {
    int angka, jumlah = 0, angka_temp = 0;

    Scanner in = new Scanner(System.in);

    do
    {
      System.out.print("Masukkan angka : ");
      angka = in.nextInt();
      jumlah = jumlah + angka;
      if(angka == angka_temp)
      {
        break;
      }
      angka_temp = angka;
    }
    while(angka != 0);
    if(angka == 0)
    {
      System.out.println("\nAnda telah memasukkan angka 0");
    }
    else if(angka == angka_temp)
    {
      System.out.println("\nAnda telah memasukkan angka yang sama berurutan yaitu : " + angka_temp);
    }
    System.out.println("Jumlah angka sebelumnya adalah " + jumlah);
  }
}
