public class Kedua
{
  public static void main(String [] args)
  {
    // No 1 Beginners sometimes write statements such as the following
    if (price > 100)
    {
      discountedPrice = price - 20;
    }
    else if (price <= 100)
    {
      discountedPrice = price - 10;
    }

    // improve 1
    if (price > 100)
    {
      discountedPrice = price - 20;
    }
    else
    {
      discountedPrice = price - 10;
    }

    // improve 2
    if (price > 100)
      discountedPrice = price - 20;
    else
      discountedPrice = price - 10;

    // improve 3
    discountedPrice = price > 100 ? price - 20 : price - 10;

    // Explain how this code can be improve
    // Jika price lebih besar dari 100 maka discountedPrice = price kurang 20, jika tidak lanjut ke statement selanjutnya
    // price kurang dari atau sama dengan 100 maka discountedPrice = price kurang 10

    // No 2 what does the following loop print ?
    int n = 1;
    while (n < 100)
    {
      n = 2 * n;
      System.out.print(n + " ");
    }
    // Print Kelipatan 2
    // 2 4 6 8 16 32 64 128

    // No 3 Hand trace the following code, showing the value of n and the output
    int n2 = 5;
    while (n2 >= 0)
    {
      n2--;
      System.out.print(n2);
    }
    // 4 3 2 1 0 -1 */
  }
}
