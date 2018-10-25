public class InputKaryawan
{
  public static void main(String [] args)
  {
    Karyawan karyawan1 = new Karyawan("Muklis", "Margonda", 25, "muklis@123.com", "05060708");
    Karyawan karyawan2 = new Karyawan("Mahmud", "Lenteng", 23, "mahmud@123.com", "05060709");
    Karyawan karyawan3 = new Karyawan("Udin Katagawa", "Jepang", 21, "udinK@123.com", "05060710");

    System.out.println("Nama Karyawan : " + karyawan1.tampilNama());
    System.out.println("Alamat : " + karyawan1.tampilAlamat());
    System.out.println("Usia : " + karyawan1.tampilUsia());
    System.out.println("Email : " + karyawan1.tampilEmail());
    System.out.println("Id : " + karyawan1.tampilId());

    System.out.println("\nNama Karyawan : " + karyawan2.tampilNama());
    System.out.println("Alamat : " + karyawan2.tampilAlamat());
    System.out.println("Usia : " + karyawan2.tampilUsia());
    System.out.println("Email : " + karyawan2.tampilEmail());
    System.out.println("Id : " + karyawan2.tampilId());

    System.out.println("\nNama Karyawan : " + karyawan3.tampilNama());
    System.out.println("Alamat : " + karyawan3.tampilAlamat());
    System.out.println("Usia : " + karyawan3.tampilUsia());
    System.out.println("Email : " + karyawan3.tampilEmail());
    System.out.println("Id : " + karyawan3.tampilId());
  }
}
