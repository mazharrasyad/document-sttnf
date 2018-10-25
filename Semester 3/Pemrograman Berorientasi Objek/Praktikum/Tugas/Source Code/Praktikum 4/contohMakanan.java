public class contohMakanan
{
    public static void main(String [] args)
    {
        Makanbang nasgor = new Makanbang();
        Makanbang bubur = new Makanbang();

        nasgor.isiNama("Nasi Goreng");
        nasgor.isiJenis("Makan Berat");        
        nasgor.isiPorsi(1);        

        bubur.isiNama("Bubur Ayam");
        bubur.isiJenis("Makan Berat");        
        bubur.isiPorsi(1);

        System.out.println("Nasgor\n==========");
        System.out.println("Nama Lengkap\t:" + nasgor.ambilNama() +
        "\nJenis\t: " + nasgor.ambilJenis() +
        "\nJumlah Porsi \t: Untuk " + nasgor.ambilPorsi() + " Orang");
        System.out.println();
        System.out.println("Bubur\n==========");
        System.out.println("Nama Lengkap\t:" + bubur.ambilNama() +
        "\nJenis\t: " + bubur.ambilJenis() +
        "\nJumlah Porsi \t: Untuk " + bubur.ambilPorsi() + " Orang");
    }
}