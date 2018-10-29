import java.io.*;

public class Eksepsi
{
    public static void main (String [] args)
    {
        int[] A = new int[5];
        // Error
        // int i = 10;
        // Tidak Error
        int i = 1;

        try
        {
            A[i] = 100;
            System.out.println("Hasil : " + A[i]);
        }
        catch (Exception e)
        {
            System.out.println("Kesalahan = Array yang dipilih tidak terdaftar");
        }
    }
}