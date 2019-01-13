import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class CaesarChiper {
    private int key;

    public CaesarChiper(int key) {
        this.key = key;
    }
    
    private int encrypt(int asal){
        return (asal + this.key) % 256;
    }    

    public void encryptStream(InputStream in, OutputStream out)
            throws IOException{
        //baca input stream
        boolean selesai = false;
        while (!selesai) {
            //selama masih ada data, encrypt
            int data = in.read();
            if(data == -1){
                selesai = true;
            }else{
                out.write(encrypt(data));
            }      
        }
    }

    private int decrypt(int asal){
        return (asal - this.key) % 256;
    }    

    public void decryptStream(InputStream in, OutputStream out)
            throws IOException{
        //baca input stream
        boolean selesai = false;
        while (!selesai) {
            //selama masih ada data, encrypt
            int data = in.read();
            if(data == -1){
                selesai = true;
            }else{
                out.write(decrypt(data));
            }      
        }
    }
}
