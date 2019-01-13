public class ThreadDemo{
    public static void main(String [] args){
        RunnableDemo r1 = new RunnableDemo("THREAD SATU",3000);
        r1.start();
        RunnableDemo r2 = new RunnableDemo("THREAD Dua",1000);
        r2.start();
    }
}

class RunnableDemo implements Runnable{
    private String namaThread;
    private Thread t;
    private long delay;

    public RunnableDemo(String namaThread, long delay){
        this.namaThread = namaThread;
        this.delay = delay;
    }

    @Override
    public void run(){
        System.out.println("Thread " + namaThread + " sedang berjalan");        

        for(int i = 5; i >= 0; i--){
            try{
                System.out.println(namaThread + " countdown ke-" + i);
                Thread.sleep(delay);
            } catch(InterruptedException ex){
                System.out.println(namaThread + " diinterupsi");
            }            
        }
    }

    public void start(){
        System.out.println("Starting " + namaThread);
        if(t == null){
            t = new Thread(this, namaThread);
            t.start();
        }
    }
}