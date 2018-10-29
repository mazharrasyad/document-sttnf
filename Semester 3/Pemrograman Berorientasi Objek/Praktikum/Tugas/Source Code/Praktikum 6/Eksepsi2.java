public class Eksepsi2
{
    public static void main (String [] args)
    {
        int pembilang = 12;
        // Tidak Error
        // int penyebut = 5;
        // Error
        int penyebut = 0;

        try
        {
            int hasil = pembilang / penyebut;
            System.out.println("Hasil = " + hasil);            
        }
        catch (ArithmeticException e)
        {
            System.out.println("Kesalahan = Terdapat pembagian dengan nol");
            System.out.println("Statement setelah blok try-catch");
        }
        catch (Exception ae)
        {
            System.out.println("Eksepsi Generik...");
        }
    }
}