import java.io.*;
import java.util.*;

public class TugasEksepsi4
{
    public FileInputStream test()
    {
        String x;
        Scanner a = new Scanner (System.in);
        System.out.print("Masukkan direktori.txt yang anda ingin keluarkan : ");
        x = a.next();
        File isi = new File(x);
        FileInputStream fileInputStream = null;

        try
        {
            fileInputStream = new FileInputStream(isi);
            fileInputStream.read();

            FileReader fr = new FileReader(isi);
            BufferedReader br = new BufferedReader(fr);

            String text;

            while((text = br.readLine()) != null)
            {
                System.out.println(text);
            }            
        }
        catch (IOException e)
        {
            System.out.println("Filenya ga ada cu, coba benerin dah");            
        }

        return fileInputStream;
    }

    public static void main(String [] args)
    {
        TugasEksepsi4 instance1 = new TugasEksepsi4();
        instance1.test();
    }
}