public class Crack
{
    public static void main(String [] args)
    {
        ComboLock crack = new ComboLock(5, 35, 2);
            
        // Kombinasi Salah
        crack.reset();                        
        crack.turnLeft(5);
        crack.turnLeft(35);
        crack.turnRight(2);
        crack.open();  

        // Kombinasi Benar
        crack.reset();                
        crack.turnRight(5);
        crack.turnLeft(35);
        crack.turnRight(2);
        crack.open();          
    } 
}