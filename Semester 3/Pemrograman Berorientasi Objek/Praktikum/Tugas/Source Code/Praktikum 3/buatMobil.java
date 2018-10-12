public class buatMobil
{
  public static void main(String [] args)
  {
    Mobil minibus = new Mobil();
    Mobil sedan = new Mobil();

    minibus.jenis = "Avanza";
    minibus.merek = "Toyota";
    minibus.cc = 1300;

    sedan.jenis = "City";
    sedan.merek = "Honda";
    sedan.cc = 1600;

    minibus.tipe("Minibus");
    System.out.println("Jenis : " + minibus.jenis);
    System.out.println("Merek : " + minibus.merek);
    System.out.println("CC : " + minibus.cc);

    sedan.tipe("\nSedan");
    System.out.println("Jenis : " + sedan.jenis);
    System.out.println("Merek : " + sedan.merek);
    System.out.println("CC : " + sedan.cc);
  }
}
