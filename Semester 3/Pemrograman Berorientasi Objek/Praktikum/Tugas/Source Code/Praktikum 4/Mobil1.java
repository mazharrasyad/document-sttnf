public class Mobil1
{
  private String jenis;
  private String merek;
  private int cc;

  public Mobil1(String jenis, String merek, int cc)
  {
    this.jenis = jenis;
    this.merek = merek;
    this.cc = cc;
  }

  public String perolehjenis()
  {
    return jenis;
  }

  public String perolehmerek()
  {
    return merek;
  }

  public int perolehcc()
  {
    return cc;
  }
}
