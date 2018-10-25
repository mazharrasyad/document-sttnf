public class Contohnya
{
  // Kasus Overloading

  void contoh(int a, int b)
  {
    System.out.println("ini kasus pertama dengan nilai : " +a+ " dan " +b);
    // Kasus pertama sudah benar
    // Cara memanggil methodnya dengan kedua argumen diharuskan type data int
  }

  void contoh(int a, int b, int c)
  {
    // System.out .println(ini kasus kedua dengan nilai : " +a+ " dan " +b+ " dan " +c);
    //                     ^ Kasus kedua tidak ada tanda petik dua sebelum kata ini, seharusnya :
    System.out .println("ini kasus kedua dengan nilai : " +a+ " dan " +b+ " dan " +c);
    // Cara memanggil methodnya dengan ketiga argumen diharuskan type data int
  }

  void contoh(double x,int y)
  {
    System.out.println("ini kasus ketiga dengan nilai : "+x+ " dan " +y);
    // Kasus ketiga terjadi error karena pada method pertama sudah terdapat argumen kedunya int
    // Maka harus ada perubahan di method ketiga, salah satu contohnya mengganti int pertama dengan double
    // Cara memanggil methodnya dengan argumen pertama type data double dan argumen kedua type data int
  }

  void contoh(String a, int b)
  {
    System.out.println("ini kasus keempat dengan nilai : "+a+ " dan " +b);
    // Kasus keempat sudah benar
    // Cara memanggil methodnya dengan argumen pertama type data String dan argumen kedua type data int
  }

  void contoh(int b, String a)
  {
    // System.out.println("ini kasus kelima dengan nilai : +a+ " dan "+b);
    //                                                         ^ Tidak ada tanda plus untuk menambah variabel
    //                                                    ^ Atau tidak ada tanda petik dua sebelum kata +am seharusnya :
    System.out.println("ini kasus kelima dengan nilai : " +a+ " dan "+b);
    // Cara memanggil methodnya dengan argumen pertama type data int dan argumen kedua type data String
  }
}
