public class GenericTI1
{
    public static void main(String [] args)
    {
        // Pasangan p1 = new Pasangan("SATU","DUA");
        // Pasangan p2 = new Pasangan(1,2);

        // Generic
        Pasangan<String,String> p1 = new Pasangan("SATU","DUA");
        Pasangan<Integer,Integer> p2 = new Pasangan(1,2);
        Pasangan<String,Integer> p3 = new Pasangan("SATU",2);
    }
}

// T = type data terserah, S = type data suka-suka
// class Pasangan
// extends List = Terserah tapi dibatasi
// class Pasangan<T extends List & Cloneable, S>
class Pasangan<T, S>
{
    // private String nilai1;
    // private String nilai2;

    // public Pasangan(String nilai1, String nilai2){
    //     this.nilai1 = nilai1;
    //     this.nilai2 = nilai2;
    // }

    // public String getNilai1(){
    //     return nilai1;
    // }

    // public void setNilai1(String nilai1){
    //     this.nilai1 = nilai1;
    // }

    // public String getNilai2(){
    //     return nilai2;
    // }

    // public void setNilai2(String nilai2){
    //     this.nilai2 = nilai2;
    // }

    // Generic Class
    private T nilai1;
    private S nilai2;

    public Pasangan(T nilai1, S nilai2){
        this.nilai1 = nilai1;
        this.nilai2 = nilai2;
    }

    public T getNilai1(){
        return nilai1;
    }

    public void setNilai1(T nilai1){
        this.nilai1 = nilai1;
    }

    public S getNilai2(){
        return nilai2;
    }

    public void setNilai2(S nilai2){
        this.nilai2 = nilai2;
    }
}

// 1. Buatlah sebuah kelas yang menerapkan konsep generic
// - 3 properti yang tipernya generic
// - Buat obj yang menggunakan kelas tersebut (3 objek)

// 2. Buatlah method generic untuk mencetak arraylist yang tipe datanya generic

class Keluarga<F, M, C>
{
    private F Ayah;
    private M Mother;
    private C Child;

    // public static <E> String toString(ArrayList<E> a)
    // {
    //     String result = "";
    //     for (E e : a)
    //     {
    //         result = result + e + " ";
    //     }
    //     return result;
    // }
}