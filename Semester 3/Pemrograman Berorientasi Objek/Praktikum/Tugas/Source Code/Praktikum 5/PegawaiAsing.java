public class PegawaiAsing extends Pegawai
{
  private String noPasport;

  public PegawaiAsing(String nip, String nama, String noPasport)
  {
    super(nip,nama);
    this.noPasport = noPasport;
  }

  public void info()
  {
    super.info();
    System.out.println("Pasport : " + noPasport);
  }
}
