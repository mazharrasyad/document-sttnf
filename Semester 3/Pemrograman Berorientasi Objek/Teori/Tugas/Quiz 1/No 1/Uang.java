public class Uang
{
  public static void main(String [] args)
  {
    int tanggal = 1;
    double awal = 1680000;
    double beli = 500000;
    double total = 0;
    double tambahan = 700000;

    while(tanggal < 16)
    {
      if(tanggal == 1)
      {
        System.out.println("Zidni Mendapat Uang Setiap Awal Bulan Sebesar Rp" + awal);
        System.out.println("Kemudian Zidni Membeli Baju Seharga Rp" + beli);
        total = awal - beli;
        System.out.println("Sisa Uang Zidni Sebesar Rp" + total);
        System.out.println();
      }
      else if (tanggal == 15)
      {
        System.out.println();
        System.out.println("Zidni Mendapat Uang Tambahan Setiap Tanggal 15 Sebesar Rp" + tambahan);
        total += tambahan;
        System.out.println("Total Uang Zidni Sebesar Rp" + total);
        System.out.println();
      }

      System.out.println("Total Uang Zidni Tanggal " + tanggal + " Sebesar Rp" + total);
      tanggal++;
    }
  }
}
