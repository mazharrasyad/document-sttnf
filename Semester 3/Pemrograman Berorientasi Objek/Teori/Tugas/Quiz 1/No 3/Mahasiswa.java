public class Mahasiswa extends Person
{
  private int nim;
  private String jurusan;
  private float ipk;

  public Mahasiswa(String nama, String alamat, int umur, int nim, String jurusan, float ipk)
  {
    super(nama,alamat,umur);
    this.nim = nim;
    this.jurusan = jurusan;
    this.ipk = ipk;
  }

  public void info()
  {
    super.info();
    System.out.println("NIM : " + nim);
    System.out.println("Jurusan : " + jurusan);
    System.out.println("IPK : " + ipk);
  }
}
