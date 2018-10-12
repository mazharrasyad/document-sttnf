public class DemoVariable
{
  public static void main(String ar[])
  {
    // Deklarasi variabel
    int a = 5;
    int b = 3;
    int c = a / b;
    // float d = a / b;
    boolean d = true;
    String e = "hello";
    char f = '1';

    System.out.println("Nilai a : " + a);
    System.out.println("Nilai b : " + b);
    System.out.println("Nilai c : " + c);
    System.out.println("Nilai d : " + d);
    System.out.println("Nilai e : " + e);
    System.out.println("Nilai f : " + f);
    System.out.println("Nilai abe : " + a + b + e);
    System.out.println("Nilai eab : " + e + a + b);
    System.out.println("Nilai abf : " + a + b + f);
    System.out.println("Nilai fab : " + f + a + b);
  }
}
