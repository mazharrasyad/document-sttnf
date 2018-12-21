import javax.swing.JOptionPane;

public class konverter_ti1{
    public static void main (String [] args){
        rupiahtodollar c1 = new rupiahtodollar();
        dollartorupiah c2 = new dollartorupiah();
        celciustofahrenheit c3 = new celciustofahrenheit();
        fahrenheittocelcius c4 = new fahrenheittocelcius();

        iconverter[] pilihankonverter = {c1,c2,c3,c4};

        String str_pilihan = JOptionPane.showInputDialog(
            "Pilih konverter:\n"
            + "1. Rupiah ke Dollar\n" // [0]
            + "2. Dollar ke Rupiah\n" // [1] 
            + "3. Celcius ke Fahrenheit\n" // [2]
            + "4. Fahrenheit ke Celcius\n"); // [3]

        int pilihan =  Integer.parseInt(str_pilihan); // 1 - 4
        iconverter converterdipilih = pilihankonverter[pilihan - 1];

        String str_input = JOptionPane.showInputDialog(
            "Masukkan nilai input");

        double input = Double.parseDouble(str_input);
        double hasil = converterdipilih.convert(input);        
        // lanjutkan...
        JOptionPane.showMessageDialog(null, "INI lho hasilnya = " + hasil);
    }
}