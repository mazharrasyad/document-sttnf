public class ComboLock
{
    private int secret1, secret2, secret3;
    private int pin = 0;
    // private int jawaban1, jawaban2, jawaban3;
    private int putaran_ke = 0;
    private Integer[] jawabans = new Integer[3];
    
    public ComboLock(int secret1, int secret2, int secret3)
    {
        this.secret1 = secret1;
        this.secret2 = secret2;
        this.secret3 = secret3;
    }

    public void reset()
    {
        this.pin = 0;
    }

    public void turnLeft(int ticks)
    {
        this.pin = this.pin + ticks % 40;
        jawabans[putaran_ke] = this.pin;
        putaran_ke++;
        // switch (putaran_ke)
        // {
        //     case 1:
        //         this.jawaban1 = this.pin;
        //         break;
        //     case 2:
        //         this.jawaban2 = this.pin;
        //         break;
        //     case 3:
        //         this.jawaban3 = this.pin;
        //         break;                
        // }
    }

    public void turnRight(int ticks)
    {
        this.pin = this.pin - ticks % 40;
        jawabans[putaran_ke] = this.pin;
        putaran_ke++;
        // switch (putaran_ke)
        // {
        //     case 1:
        //         this.jawaban1 = this.pin;
        //         break;
        //     case 2:
        //         this.jawaban2 = this.pin;
        //         break;
        //     case 3:
        //         this.jawaban3 = this.pin;
        //         break;                
        // }
    }

    public boolean open()
    {
        return (secret1 == jawabans[0] && secret2 == jawabans[1] && secret3 == jawabans[2]);
    }
}