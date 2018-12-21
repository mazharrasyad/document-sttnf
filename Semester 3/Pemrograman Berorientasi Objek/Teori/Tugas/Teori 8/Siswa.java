public class Siswa
{
    String nama;
    public int bermain()
    {
        return 1;
    }
}

// --------------------------

abstract class binatang
{
    String jenis;
    // void bersuara()
    // {
        
    // }
    abstract void bersuara();
}

// --------------------------

class anjing extends binatang
{
    @Override
    void bersuara(){
        System.out.println("Wof....wof..");
    }
}

// --------------------------

class kucing extends binatang
{
    @Override
    void bersuara(){
        System.out.println("Miau....");
    }
}

// class ayam extends binatang
// {
    
// }
// Harus ada void bersuara

class ayam extends binatang implements resizeAble, makanAble
{
    @Override
    void bersuara(){
        System.out.println("Kok...kok....");
    }

    public void resize(){
        //
    }

    public void makan(){
        //
    }
}

// Class abstract adalah class yang memiliki 1 atau lebih method abstract
// Method abstract adalah method yang tida ada isinya
// Interface adalah isinya abstract
// Implement bisa lebih dari 1

interface resizeAble
{
    void resize();
}

interface makanAble
{
    void dimakan();
}