public class Person
{
  protected String nama;
  protected String alamat;
  protected int umur;

  public Person(String nama, String alamat, int umur)
  {
    this.nama = nama;
    this.alamat = alamat;
    this.umur = umur;
  }

  public void info()
  {
    System.out.println("Nama : " + nama);
    System.out.println("Alamat : " + alamat);
    System.out.println("Umur : " + umur);
  }
}
