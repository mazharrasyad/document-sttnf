import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class Total 
{
    public static void main(String a[]) // throws FileNotFoundException
    {        
        // Tampilkan pesan ke user untuk menuliskan nama file
        Scanner sc = new Scanner(System.in);
        System.out.print("Nama file input : ");
        String inputFileName = sc.next();
        System.out.print("Nama file output : ");
        String outputFileName = sc.next();
        try
        {
            // Buat objek file, scanner & printwriter 
            File inputFile = new File(inputFileName);
            Scanner in = new Scanner(inputFile);
            PrintWriter writer = new PrintWriter(outputFileName);

            // Baca file, lalu hitung total, lalu tulis ke file
            double total = 0;
            double avg = 0;
            int count = 0;        

            while(in.hasNextDouble())
            {            
                // Baca
                double nilai = in.nextDouble();
                // Tulis   
                if(count % 2 == 0)         
                    writer.printf("%15.2f", nilai);
                else
                    writer.printf("%15.2f\n", nilai);
                // Jumlahkan
                total = total + nilai;                        
                count++;
            }
            avg = total / count;

            // Tulis Total
            writer.printf("Total : %8.2f\n", total);
            writer.printf("Average : %8.2f\n", avg);

            // Close All
            in.close();
            writer.close();
        }
        catch(Exception e)
        {
            // Jika terjadi kesalahan, apa yang kita lakukan
            System.out.println("Maaf, file tidak ditemukan");
        }
    }
}