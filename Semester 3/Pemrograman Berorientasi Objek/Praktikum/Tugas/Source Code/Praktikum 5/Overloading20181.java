public class Overloading20181
{
    static void tambah(int a, int b)
    {
        System.out.println("Jumlah 2 angka = " + (a + b));
    }

    // Beda jumlah argumen / parameter
    static void tambah(int a, int b, int c)
    {
        System.out.println("Jumlah 3 angka = " + (a + b + c));
    }

    // Beda tipe data parameter
    static void tambah(int a, double b)
    {
        System.out.println("Jumlah 2 angka (int dan double) = " + (a + b));
    }

    // Beda urutan tipe data parameter
    static void tambah(double a, int b)
    {
        System.out.println("Jumlah 2 angka (double dan int) = " + (a + b));
    }
}