public class Keturunan
{
    protected String nim;
    protected String nama;
    protected int uang;

    public Keturunan()
    {
        nim = "01102121121";
        nama = "Epsonudin";
        uang = 10000;
    }

    public void info()
    {
        System.out.println("Nim = " + nim);
        System.out.println("Nama = " + nama);
        System.out.println("Uang = " + uang);
    }
}