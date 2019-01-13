import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ChiperTI1 {
    public static void main(String[] args) {        
        InputStream inStream = null;

        try {
            Scanner in = new Scanner(System.in);
            System.out.print("File input: ");            
            String fileInput = in.next();

            System.out.print("File output: ");
            String fileOutput = in.next();

            System.out.print("Key (int): ");
            int key = in.nextInt();

            inStream = new FileInputStream(fileInput);
            OutputStream outStream = new FileOutputStream(fileOutput);
            CaesarChiper chiper = new CaesarChiper(key);

            System.out.println();
            System.out.println("================");
            System.out.println("||1. Encrypt  ||");
            System.out.println("||2. Decrypt  ||");
            System.out.println("================");
            System.out.print("Masukkan Pilihan (int) : ");
            int pilihan = in.nextInt();

            if(pilihan == 1)
                chiper.encryptStream(inStream, outStream);
            else if(pilihan == 2)
                chiper.decryptStream(inStream, outStream);
            else
                System.out.println("Pilihan Tidak Ada");

            inStream.close();
            outStream.close();
        } catch (Exception ex) {
            System.out.println("Gagal melakukan enkripsi");
        } 
    }
}
