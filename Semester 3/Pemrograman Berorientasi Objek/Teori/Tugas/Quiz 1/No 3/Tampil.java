public class Tampil
{
  public static void main(String [] args)
  {
    Dosen dosen = new Dosen("Pak Hilmy", "Jakarta", 30, 210217029);
    Mahasiswa mahasiswa = new Mahasiswa("Azhar", "Cibinong", 19, 110217029, "Teknik Informatika", 3.0f);

    System.out.println("===== Dosen =====");
    dosen.info();

    System.out.println("\n===== Mahasiswa =====");
    mahasiswa.info();
  }
}
