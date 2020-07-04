public class MySingleton{
    private static MySingleton singleton = new MySingleton();

    private MySingleton(){
        System.out.println("object created...");        
    }

    public static MySingleton getInstance(){
        return singleton;
    }
}