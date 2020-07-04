// import jdp2e.mvc.model.*;
// import jdp2e.mvc.view.*;
// import jdp2e.mvc.controller.*;

public class MVCArchitectureExample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("NIM : 0110217029\n");
		System.out.println("***MVC architecture Demo***\n");
		
		//Model
		Model model = new EmployeeModel();
		
		//View
		View view = new ConsoleView();
		
		//Controller
		Controller controller = new EmployeeController(model, view);
		controller.displayEnrolledEmployees();
		
		//Add an employee
		controller.addEmployee(new Employee("Kevin","E4"));
		controller.displayEnrolledEmployees();
		
		//Remove an existing employee using the employee id.
		controller.removeEmployee("E2");
		controller.displayEnrolledEmployees();
		
		//Cannot remove an employee who does not belong to the list.
		controller.removeEmployee("E5");
		controller.displayEnrolledEmployees();
		
		//Avoiding duplicate entry
		controller.addEmployee(new Employee("Kevin","E4"));
	}

}