public class BelajarInterface{

}

abstract class bentuk2d{
    double luas;
    double keliling;
    abstract void hitungLuas();
    abstract void hitungKeliling();
    double getLuas(){return this.luas;}
    double getKeliling(){return this.keliling;}
}

class segitiga extends bentuk2d{
    double alas, tinggi;

    @Override
    void hitungLuas(){
        this.luas = this.alas * this.tinggi / 2;
    }

    @Override
    void hitungKeliling(){
        
    }
}

class lingkaran extends bentuk2d{
    double r;

    void hitungLuas(){
        this.luas = Math.PI * r * r;
    }

    void hitungKeliling(){
        this.keliling = Math.PI * 2 * r;
    }
}