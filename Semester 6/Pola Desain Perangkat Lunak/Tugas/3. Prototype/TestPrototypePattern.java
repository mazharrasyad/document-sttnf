public class TestPrototypePattern {
	public static void main(String[] args){
        Box box1 = new Box("GREEN");
        Box box2 = new Box("RED");
                 
        System.out.println("NIM : 0110217029");
        System.out.println("Box 1 dan Box 2 yang telah di isi");
        System.out.println("Box 1 : " + box1.getColor());
        System.out.println("Box 2 : " + box2.getColor());
        System.out.println();
         
         
        System.out.println("Box 3 di clone dengan Box 1");
        Box box3 = box1.clone();
        System.out.println("Box 3 : " + box3.getColor());
         
        System.out.println("Box 4 di clone dengan Box 2");
        Box box4 = box2.clone();
        System.out.println("Box 4 : " + box4.getColor());
    }
}