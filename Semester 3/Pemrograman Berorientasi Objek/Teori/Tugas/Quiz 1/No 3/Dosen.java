public class Dosen extends Person
{
  private int nip;

  public Dosen(String nama, String alamat, int umur, int nip)
  {
    super(nama,alamat,umur);
    this.nip = nip;
  }

  public void info()
  {
    super.info();
    System.out.println("NIP : " + nip);
  }
}
