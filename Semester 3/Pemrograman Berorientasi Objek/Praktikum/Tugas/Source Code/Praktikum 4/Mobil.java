public class Mobil
{
  private String jenis;
  private String merek;
  private int cc;

  public void isikanjenis(String jenis)
  {
    this.jenis = jenis;
  }

  public void isikanmerek(String merek)
  {
    this.merek = merek;
  }

  public void isikancc(int cc)
  {
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
