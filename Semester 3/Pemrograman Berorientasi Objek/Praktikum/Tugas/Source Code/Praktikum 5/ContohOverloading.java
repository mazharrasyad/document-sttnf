public class ContohOverloading
{
  public void jumlah(int a, int b)
  {
    System.out.println("Jumlah 2 angka = " + (a + b));
  }

  public void jumlah(int a, int b, int c)
  {
    System.out.println("Jumlah 3 angka = " + (a + b + c));
  }

  public void jumlah(double a, int b)
  {
    System.out.println("Jumlah 2 angka (double + int) = " + (a + b));
  }

  public void jumlah(int a, double b)
  {
    System.out.println("Jumlah 2 angka (int + double) = " + (a + b));
  }
}
