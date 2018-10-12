public class Biodata
{
  private String nama;
  private String nim;
  private String alamat;
  private String prodi;
  private float nilai;
  private char grade;

  public Biodata(String nama, String nim, String alamat, String prodi, float nilai)
  {
    System.out.println("Nama : " + nama);
    System.out.println("NIM : " + nim);
    System.out.println("Alamat : " + alamat);

    if(prodi == "SI" || prodi == "si")
    {
      prodi = "Sistem Informasi";
    }
    else if(prodi == "TI" || prodi == "ti")
    {
      prodi = "Teknik Informatika";
    }
    else
    {
      prodi = "Tidak Diketahui";
    }

    System.out.println("Prodi : " + prodi);
    System.out.println("Nilai : " + nilai);

    if(80 <= nilai && nilai <= 100)
    {
      grade = 'A';
    }
    else if(65 <= nilai && nilai <= 79)
    {
      grade = 'B';
    }
    else if(50 <= nilai && nilai <= 64)
    {
      grade = 'C';
    }
    else if(40 <= nilai && nilai <= 49)
    {
      grade = 'D';
    }
    else if(0 <= nilai && nilai <= 39)
    {
      grade = 'E';
    }
    else
    {
      grade = '?';
    }

    System.out.println("Grade : " + grade);
  }
}
