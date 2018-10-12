import java.util.*;

public class PapanCatur
{
  public static void main(String [] args)
  {
    int baris, kolom;
    String posisi;
    int i, j, n;

    Scanner in = new Scanner(System.in);

    System.out.println("===== Papan Catur =====");
    System.out.print("\nMasukkan jumlah baris dan kolom : ");
    n = in.nextInt();
    System.out.println();

    System.out.print("    ");
    for(i = 0; i < n; i++)
    {
      System.out.print(" " + (i + 1));
    }
    System.out.print(" --> Kolom\n");

    System.out.print("    ");
    for(i = 0; i < n; i++)
    {
      System.out.print(" _");
    }
    System.out.println();

    for(i = 0; i < n; i++)
    {
      System.out.print(" " + (i + 1) + " | ");
      for(j = 0; j < n; j++)
      {
        if((i + j) % 2 == 0)
        {
            System.out.print("1 ");
        }
        else
        {
            System.out.print("0 ");
        }
      }
      System.out.println();
    }
    System.out.print(" |\n V\nBaris\n\n");

    System.out.print("Masukkan posisi baris (B) : ");
    baris = in.nextInt();
    System.out.print("Masukkan posisi kolom (K) : ");
    kolom = in.nextInt();

    if((baris + kolom) % 2 == 0)
    {
      posisi = "1 (Hitam)";
    }
    else
    {
      posisi = "0 (Putih)";
    }
    System.out.println("\nBaris ke " + baris + " kolom ke " +
     kolom + " : " + posisi);
  }
}
