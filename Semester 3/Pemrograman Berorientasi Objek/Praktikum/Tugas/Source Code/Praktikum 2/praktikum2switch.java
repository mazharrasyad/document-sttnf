import java.util.Scanner;

public class praktikum2switch
{
  public static void main(String args[])
  {
    int a = 0;
    Scanner baru = new Scanner(System.in);

    System.out.print("Masukkan satu angka dari angka 1 sampai 5 : ");
    a = baru.nextInt();

    switch(a)
    {
      case 1:
        System.out.println("Ini angka satu");
        break;
      case 2:
        System.out.println("Ini angka dua");
        break;
      case 3:
        System.out.println("Ini angka tiga");
        break;
      case 4:
        System.out.println("Ini angka empat");
        break;
      case 5:
        System.out.println("Ini angka lima");
        break;
      default:
        System.out.println("Maaf angka yang dimasukkan tidak sesuai");
    }
  }
}
