public class ContohMain
{
  public static void main(String [] args)
  {
    Contohnya contoh = new Contohnya();

    contoh.contoh(1, 2); // Method pertama contoh(int, int)
    contoh.contoh(1, 2, 3); // Method kedua contoh(int, int, int)
    contoh.contoh(1.5, 2); // Method pertama contoh(double, int)
    contoh.contoh("A", 1); // Method keempat contoh(String, int)
    contoh.contoh(1, "A"); // Method kelima contoh(int, String)
  }
}
