public class Makanbang
{
    private String nama;
    private String jenis;
    private int porsi;

    public void isiNama(String nama)
    {
        this.nama = nama;
    }

    public void isiJenis(String jenis)
    {
        this.jenis = jenis;
    }

    public void isiPorsi(int porsi)
    {
        this.porsi = porsi;
    }

    public String ambilNama()
    {
        return nama;
    }

    public String ambilJenis()
    {
        return jenis;
    }

    public int ambilPorsi()
    {
        return porsi;
    }
}