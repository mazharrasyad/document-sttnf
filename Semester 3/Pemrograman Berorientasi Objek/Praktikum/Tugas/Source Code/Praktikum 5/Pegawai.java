public class Pegawai
{
  protected String nip;
  protected String nama;

  public Pegawai(String nip, String nama)
  {
    this.nip = nip;
    this.nama = nama;
  }

  public void info()
  {
    System.out.println("Nip : " + nip);
    System.out.println("Nama : " + nama);
  }
}
