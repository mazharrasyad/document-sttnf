public class Eksepsi3
{
    public static void main(String [] args)
    {
        int[] A = new int[5];

        try
        {
            for(int i = 0; i < 5; i++)
            {
                A[i] = i * 10;
            }

            System.out.println("Nilai pada indeks ke 9 : " + A[9]);
        }
        catch (ArrayIndexOutOfBoundsException e)        
        {
            System.out.println("Tidak terdapat indeks ke " + e.getMessage());
        }

        for(int i = 0; i < 5; i++)
        {
            System.out.println("Elemen ke-" + i + " : " + A[i]);
        }
    }
}