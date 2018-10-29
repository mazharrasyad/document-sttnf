public class Penangananeksepsi1
{
    public static void main(String [] args)
    {
        int pembilang = 2;
        int penyebut = 0;

        try
        {
            int hasil = pembilang / penyebut;
            System.out.println("Hasil : " + hasil);            
        }
        catch(ArithmeticException ae)
        {
            System.out.println("Kesalahan terdapat pembagian dengan nol");            
        }
        System.out.println("Statement setelah blok try-catch");
    }
}