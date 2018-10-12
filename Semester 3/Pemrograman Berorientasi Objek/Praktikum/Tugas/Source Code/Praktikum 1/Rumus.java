import java.util.*;

public class Rumus
{
  public static void main(String [] args)
  {
    int pilihan;
    Scanner in = new Scanner(System.in);

    System.out.println("   Menu Rumus   ");
    System.out.println("----------------");
    System.out.println("| 1. Rumus s   |");
    System.out.println("| 2. Rumus G   |");
    System.out.println("| 3. Rumus FV  |");
    System.out.println("| 4. Rumus c   |");
    System.out.print("\nMasukkan pilihan no : ");
    pilihan = in.nextInt();

    switch(pilihan)
    {
      case 1 :
        // 1. s = (s0 + v0) * (t + (1/2 * g * (t * t)))
        double s, s0, v0, t, g;
        System.out.print("\nMasukkan nilai s0 : ");
        s0 = in.nextDouble();
        System.out.print("Masukkan nilai v0 : ");
        v0 = in.nextDouble();
        System.out.print("Masukkan nilai t : ");
        t = in.nextDouble();
        System.out.print("Masukkan nilai g : ");
        g = in.nextDouble();
        s = s0 + (v0 * t) + (0.5 * g * (t * t));
        System.out.println("\nRumus s : " + s);
        break;

      case 2 :
        // 2. G = ((4 * (phi * phi)) * (a * a * a)) / ((p * p) * (m1 + m2))
        double G, phi = 3.14, a3, p, m1, m2;
        System.out.print("\nMasukkan nilai a3 : ");
        a3 = in.nextDouble();
        System.out.print("Masukkan nilai p : ");
        p = in.nextDouble();
        System.out.print("Masukkan nilai m1 : ");
        m1 = in.nextDouble();
        System.out.print("Masukkan nilai m2 : ");
        m2 = in.nextDouble();
        G = ((4 * (phi * phi)) * (a3 * a3 * a3)) / ((p * p) * (m1 + m2));
        System.out.println("\nRumus G : " + G);
        break;

      case 3 :
        // 3. FV = PV * ((1 + INT / 100) ^ YRS)
        double FV, PV, INT, YRS;
        System.out.print("\nMasukkan nilai PV : ");
        PV = in.nextDouble();
        System.out.print("Masukkan nilai INT : ");
        INT = in.nextDouble();
        System.out.print("Masukkan nilai YRS : ");
        YRS = in.nextDouble();
        FV = PV * Math.pow((1 + (INT / 100)), YRS);
        System.out.println("\nRumus FV : " + FV);
        break;

      case 4 :
        // 4. c = Akar((a * a) + (b * b) - (2 * a * b * cos y))
        double c, a, b, y;
        System.out.print("\nMasukkan nilai a : ");
        a = in.nextDouble();
        System.out.print("Masukkan nilai b : ");
        b = in.nextDouble();
        System.out.print("Masukkan nilai y : ");
        y = in.nextDouble();
        c = Math.sqrt((a * a) + (b * b) - (2 * a * b * Math.cos(y)));
        System.out.println("\nRumus c : " + c);
        break;

      default :
        System.out.println("\nPilihan Tidak Ada");
        break;
    }
    /*
    double s, s0, v0, t, g;
    s = s0 + (v0 * t) + (0.5 * g * (t * t));

    double G, phi = 3.14, a3, p, m1, m2;
    G = ((4 * (phi * phi)) * (a * a * a)) / ((p * p) * (m1 + m2));

    double FV, PV, INT, YRS;
    FV = PV * Math.pow((1 + (INT / 100)), YRS);

    double c, a, b, y;
    c = Math.sqrt((a * a) + (b * b) - (2 * a * b * Math.cos(y)));
    */
  }
}
