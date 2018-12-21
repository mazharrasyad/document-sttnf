public class DemoInterface{
    public static void main(String[] args) {            
        Mahasiswa m1 = new Mahasiswa("Adi",3.75);
        Mahasiswa m2 = new Mahasiswa("Ade",3.87);
        Mahasiswa m3 = new Mahasiswa("Adu",3.46);

        // Tanpa Interface
        // Mahasiswa mahasiswas[] = {m1,m2,m3};
        // double total = 0;   
        // for(Mahasiswa m: mahasiswas){
        //     total += m.getIPK();
        // }
        // double avg = total / mahasiswas.length;

        Measureble m4 = m1;
        Measureble m5 = new Mahasiswa("Ado",3.2);        
        Measureble k5 = new Kota("Bandung",2232323);
        // Mahasiswa m6 = m5; Salah Karena m5 belum tentu Mahasiswa
        // Jika dilanjutkan akan terjadi runtime error
        Mahasiswa m6 = (Mahasiswa)m5;
        // Mahasiswa m8 = (Mahasiswa)k5; // Runtime Error
        Kota k6 = (Kota)k5;
        Measureble m8 = (Mahasiswa)m5;

        // Dengan Interface        
        Measureble mahasiswas[] = {m1,m2,m3};
        double avg = hitungRataRata(mahasiswas);

        Kota k1 = new Kota("Depok",112000);
        Kota k2 = new Kota("Tangerang",412000);
        Kota k3 = new Kota("Bekasi",312000);

        // Tanpa Interface
        // Kota kotas[] = {k1,k2,k3};
        // double total_kota = 0;   
        // for(Kota k: kotas){
        //     total_kota += m.getJmlPenduduk();
        // }
        // double avg_kota = total_kota / kotas.length;

        // Dengan Interface
        Measureble kotas[] = {m1,m2,m3};
        double avg_pend = hitungRataRata(kotas);
    }

    static double hitungRataRata(Measureble data[]){
        double total = 0;   
        for(Measureble mes: data){
            total += mes.getMeasure();
        }
        double avg = total / data.length;
        return avg;
    }
}

class Mahasiswa implements Measureble{
    String nama;
    double IPK;

    @Override
    public double getMeasure(){
        return this.IPK;
    }

    public Mahasiswa(String nama, double IPK){
        this.nama = nama;
        this.IPK = IPK;
    }

    public String getNama(){
        return nama;
    }

    public void setNama(String nama){
        this.nama = nama;
    }

    public double getIPK(){
        return IPK;
    }

    public void setIPK(double IPK){
        this.IPK = IPK;
    }
}

class Kota implements Measureble{
    String namaKota;
    double jmlPenduduk;

    @Override
    public double getMeasure(){
        return this.jmlPenduduk;
    }

    public Kota(String namaKota, double jmlPenduduk){
        this.namaKota = namaKota;
        this.jmlPenduduk = jmlPenduduk;
    }

    public String getNamaKota(){
        return namaKota;
    }

    public void setNamaKota(String namaKota){
        this.namaKota = namaKota;
    }

    public double getJmlPenduduk(){
        return jmlPenduduk;
    }

    public void setJmlPenduduk(double jmlPenduduk){
        this.jmlPenduduk = jmlPenduduk;
    }
}

interface Measureble{
    double getMeasure();
}