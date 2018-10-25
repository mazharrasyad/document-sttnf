public class contohMobil
{
  public static void main(String [] args)
  {
    Mobil minibus = new Mobil();
    Mobil sedan = new Mobil();

    minibus.isikanjenis("Avanza");
    minibus.isikanmerek("Toyota");
    minibus.isikancc(1300);

    sedan.isikanjenis("City");
    sedan.isikanmerek("Honda");
    sedan.isikancc(1600);

    System.out.println("Minibus ");
    System.out.print("Jenis : " + minibus.perolehjenis() + "\n Merek : "
                    + minibus.perolehmerek() + "\n CC : " + minibus.perolehcc());
    System.out.println();

    System.out.println("Sedan ");
    System.out.print("Jenis : " + sedan.perolehjenis() + "\n Merek : "
                    + sedan.perolehmerek() + "\n CC : " + sedan.perolehcc());
    System.out.println();
  }
}
