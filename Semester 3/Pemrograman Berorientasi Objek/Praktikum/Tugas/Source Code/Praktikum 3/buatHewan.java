public class buatHewan
{
  public static void main(String args[])
  {
    hewan kucing = new hewan();
    hewan kelinci = new hewan();

    kucing.jenis = "Anggora";
    kelinci.jenis = "Australia";
    kucing.kaki = 4;
    kucing.warna = "Putih";
    kucing.habitat = "Darat";

    kucing.suara("Meooooong");

    String makanankucing = kucing.Makanan("Ikan");

    System.out.print("Jenis Kucing : " + kucing.jenis + "\nJenis Kelinci : " + kelinci.jenis +
                      "\nBanyak Kaki Kucing : " + kucing.kaki + "\nWarna Kucing : " + kucing.warna +
                      "\nHabitat Kucing : " + kucing.habitat + "\nMakanan Kucing : " + makanankucing);

    System.out.println();
  }
}
