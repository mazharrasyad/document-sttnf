public class Combo
{
    public static void main(String [] args)
    {
        // ComboLock kunci = new ComboLock(3, 7, 9);
        ComboLock kunci = new ComboLock(3, 0, 9);

        // kunci.turnLeft(3);
        // kunci.turnLeft(4);
        // kunci.turnLeft(2);
        // System.out.println("Apakah kunci terbuka ? " + kunci.open());

        // kunci.turnLeft(3);
        // kunci.turnLeft(44);
        // kunci.turnLeft(2);
        // System.out.println("Apakah kunci terbuka ? " + kunci.open());

        kunci.turnLeft(3);
        kunci.turnRight(3);
        kunci.turnLeft(9);
        System.out.println("Apakah kunci terbuka ? " + kunci.open());
    }
}