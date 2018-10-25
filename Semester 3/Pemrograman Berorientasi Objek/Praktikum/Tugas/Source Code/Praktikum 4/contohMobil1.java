public class contohMobil1
{
  public static void main(String [] args)
  {
    Mobil1 minibus = new Mobil1("Avanza", "Toyota", 1300);
    Mobil1 sedan = new Mobil1("City", "Honda", 1600);

    System.out.println("Minibus ");
    System.out.print("Jenis\t: " + minibus.perolehjenis() + 
    "\nMerek\t: " + minibus.perolehmerek() + 
    "\nCC\t: " + minibus.perolehcc());
    System.out.println();
    System.out.println();
    System.out.println("Sedan ");
    System.out.print("Jenis\t: " + sedan.perolehjenis() + 
    "\nMerek\t: " + sedan.perolehmerek() +
    "\n CC\t: " + sedan.perolehcc());
    System.out.println();
  }
}
