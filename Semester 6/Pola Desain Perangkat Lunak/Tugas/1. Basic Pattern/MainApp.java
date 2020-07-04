public class MainApp {
    public static void main(String [] args) {
        SalaryCalculator c = new CategoryA(10000, 200);
        Employee e = new Employee ("Azhar",c);
        e.display();

        c = new CategoryB(1000000,300);
        e = new Employee("Eve", c);
        e.display();
    }
}
