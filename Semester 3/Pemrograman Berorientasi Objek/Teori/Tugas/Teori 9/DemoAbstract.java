/*
    Hero MLBB :
        - Nama
        - Role()

    Akai extends Hero MLBB :
        - Role("Tanker")

    Zilong extends Hero MLBB :
        - Role("Fighter")
*/

// Class Abstract digunakan dimethod

public class DemoAbstract{
    public static void main(String [] args){
        // Manusia bayi = new Manusia();
        // Bayi.setCaraMakan("Diemut");
        // Manusia dewasa = new Manusia();
        // Bayi.setCaraMakan("Dikunyah");
        Manusia bayi = new Bayi();
        Manusia dewasa = new Dewasa();
    }
}

// class Manusia{
//     String caraMakan;
//     public void setCaraMakan(String caraMakan)
//     {
//         this.caraMakan = caraMakan;
//     }
// }

abstract class Manusia{
    abstract public void caraMakan();
}

class Dewasa extends Manusia{
    @Override
    public void caraMakan(){
        System.out.println("Dikunyah...");
    }
}

class Bayi extends Manusia{
    @Override
    public void caraMakan(){
        System.out.println("Diemut...");
    }
}