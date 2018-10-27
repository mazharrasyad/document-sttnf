/*
Sekolah Tinggi Teknologi Terpadu Nurul Fikri
Angkatan 2017
Teknik Informatika 1
Kelas Pagi

Kelompok 2 Sistem Operasi :
- Ahmad Fathan Syakir - 0110217055
- Raihan Sabiq Rabbani - 0110217040
- Muhammad Azhar Rasyad - 0110217029

Debug Source Code di PDF :
- Line No 125 : Solusinya Tambahkan if pada else menjadi else if (falseCount == 1)
- Line No 186 : Solusinya Tukar Code No 186 Dengan No 187
*/

// <----- Package Java ----->
// package Hompimpah;

// <----- Hompimpah ----->
public class Hompimpah 
{
    private static final int JUMLAH_PEMAIN = 6; // Menentukan Jumlah Pemain Yang Ikut Hompimpah
    
    public static void main(String args[]) 
    {
        // Menentukan Bandar dan Pemain
        Gambreng gamserver = new Gambreng(JUMLAH_PEMAIN);
        Thread[] pemain    = new Thread[JUMLAH_PEMAIN]; 
        
        // Menentukan Nomer Pemain Yang Gambreng
        for (int ii = 0; ii < JUMLAH_PEMAIN; ii++) 
        {
            pemain[ii] = new Thread(new Pemain(gamserver,ii));
            pemain[ii].start();
        }
        
        // Menentukan Bandar Gambreng 1 Orang
        gamserver.bandarGambreng();
    }
    // Kedua Thread Value = 0, Artinya Bandar dan Pemain Sedang Tidur
}

// <----- Pemain ----->
class Pemain implements Runnable 
{
    Pemain(Gambreng gserver, int nomer) 
    {
       gamserver = gserver;
       no_pemain = nomer;
    }

    // <----- Pemain Mulai ----->
    // Pemain Mengirimkan Nomernya Untuk Diakses
    public void run() 
    {
       gamserver.pemainGambreng(no_pemain);
    }
    
    private Gambreng gamserver;
    private int      no_pemain;
}

// <----- Gambreng ----->
class Gambreng 
{
    private boolean   adaPemenang;
    private int       truePemain, trueCount, iterasiGambreng;
    private int       falsePemain, falseCount;
    private int       nomorPemenang, jumlahPemain;
    private Semafor[] bandar, pemain;
    private Semafor   mutex;
    
    public Gambreng(int jumlah) 
    {
        bandar = new Semafor[jumlah];
        pemain = new Semafor[jumlah];

        for (int ii = 0; ii < jumlah; ii++) 
        {
            bandar[ii] = new Semafor();
            pemain[ii] = new Semafor();
        }

        mutex           = new Semafor(1);
        jumlahPemain    = jumlah;
        iterasiGambreng = 0;
        resetGambreng();
    }

    // <----- Bandar Gambreng ----->
    // Menentukan 
    public void bandarGambreng() 
    {
        syncBandar();
        System.out.println("Permainan Hompimpah");
        
        while(!menangGambreng()) 
        {
            resetGambreng(); 
            System.out.println("\nIterasi Ke [" + (iterasiGambreng + 1) + "] : ");
            syncPemainBandar();
            hitungGambreng();
            iterasiGambreng++;
        }

        syncPemain();
        System.out.println("\nNomor Peserta Pemain [0] - [" +
        (jumlahPemain-1) + "] Pemenang Pemain Nomor[" +
        nomorPemenang + "] Jumlah Iterasi[" + iterasiGambreng + "]");
    }

    // <----- Pemain Gambreng ----->
    public void pemainGambreng(int nomor) 
    {
        syncBandarPemain(nomor);

        while(!menangGambreng()) 
        {
            mutex.kunci();

            // True = Telapak Tangan
            // False = Punggung Tangan
            if ((int)(Math.random()*2) == 1) 
            {
               truePemain = nomor;
               trueCount++;
               System.out.println("Nomor Peserta Pemain [" + nomor + "] = Telapak Tangan");
            } 
            else 
            {
               falsePemain = nomor;
               falseCount++;
               System.out.println("Nomor Peserta Pemain [" + nomor + "] = Punggung Tangan");
            }
            mutex.buka();
            syncBandarPemain(nomor);
        }
    }

    // <----- Gambreng Ulang ----->
    private void resetGambreng() 
    {
        mutex.kunci();
        adaPemenang   = false;
        truePemain    = 0;
        trueCount     = 0;
        falsePemain   = 0;
        falseCount    = 0;
        mutex.buka();
    }
   
    // <----- Menang Gambreng ----->
    private boolean menangGambreng() 
    {
         return adaPemenang;
    }
   
    // <----- Hitung Gambreng ----->
    private void hitungGambreng() 
    {
         mutex.kunci();

         if (trueCount == 1) 
         {
            adaPemenang   = true;
            nomorPemenang = truePemain;
         } 
         else if (falseCount == 1) 
         {
            adaPemenang   = true;
            nomorPemenang = falsePemain; 
         } 

         mutex.buka();
    }
   
    // <----- Sinkronisasi Pemain Dan Bandar Ke 1 ----->
    private void syncPemainBandar() 
    {
        for (int ii = 0; ii < jumlahPemain; ii++) 
        { 
            pemain[ii].buka(); 
            bandar[ii].kunci(); 
        }
    }

    // <----- Sinkronisasi Bandar ----->
    private void syncBandar() 
    {
        for (int ii = 0; ii < jumlahPemain; ii++)
        {
            bandar[ii].kunci();
        } 
    }

    // <----- Sinkronisasi Pemain ----->
    private void syncPemain() 
    {
        for (int ii = 0; ii < jumlahPemain; ii++)
        {
            pemain[ii].buka();
        } 
    }

    // <----- Sinkronisasi Pemain Dan Bandar Ke 2 ----->
    private void syncBandarPemain(int ii) 
    {
        bandar[ii].buka(); 
        pemain[ii].kunci(); 
    }
}

// <----- Sinkronisasi ----->
class Semafor 
{
    public Semafor()        
    { 
        value = 0;   
    }
    
    public Semafor(int val) 
    { 
        value = val; 
    }
    
    public synchronized void kunci() 
    {
        while (value == 0) 
        {
            try   
            { 
                wait(); 
            }
            
         catch (InterruptedException e) { }
        }
        
        value--;
    }

    public synchronized void buka() 
    {
        value++;
        notify();
    }
    
    private int value;
}
