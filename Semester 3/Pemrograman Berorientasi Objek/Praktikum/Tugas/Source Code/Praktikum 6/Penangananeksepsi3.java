public class Penangananeksepsi3
{
    public static void main(String [] args)
    {
        int pembilang = 12;
        int penyebut = 0;

        try
        {
            int hasil = pembilang / penyebut;
            System.out.println("Hasil : " + hasil);            
        }
        catch(ArithmeticException ae)
        {
            System.out.println("Terdapat pembagian dengan nol");            
        }
        catch(Exception e)
        {
            System.out.println("Eksepsi generik...");
        }        
    }
}