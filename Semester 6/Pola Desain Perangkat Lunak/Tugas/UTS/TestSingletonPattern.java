public class TestSingletonPattern {
    public static void main(String[] args){
        MySingleton s1 = MySingleton.getInstance();
        MySingleton s2 = MySingleton.getInstance();
        MySingleton s3 = MySingleton.getInstance();
    }
}
