import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class Lagu 
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
            int count = 0;
            
            while(in.hasNextLine())
            {            
                count++;
                // Baca
                String input = in.nextLine();
                // Tulis       
                writer.printf("/* " + count + " */ " + input + "\n");            
            }

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