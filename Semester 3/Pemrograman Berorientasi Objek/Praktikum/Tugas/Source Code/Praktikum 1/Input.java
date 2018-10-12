import java.util.*;

public class Input
{
  public static void main(String [] args)
  {
    String nama;

    Scanner in = new Scanner(System.in);
    System.out.print("Masukkan nama anda = ");
    nama = in.nextLine();

    System.out.println("Nama anda = " + nama);
  }
}
