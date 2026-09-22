
public class Empolyee {
	
	String name;
	int yearOfJoining;
	double Salary;
	String address;
	
	Empolyee(String name, int yearOfJoining, double Salary, String address) {
		
		this.name = name;
		this.yearOfJoining = yearOfJoining;
		this.Salary = Salary;
		this.address = address;
	}
	
	void Display() {
		
		System.out.println(name + "\t" + yearOfJoining + "\t" + Salary + "\t" + address );
	}
	

	public static void main(String[] args) {
		
		Empolyee e1 = new Empolyee("Robert", 1994, 50000, "Mumbai");
		Empolyee e2 = new Empolyee("Sam", 2000, 60000, "Pune");
		Empolyee e3 = new Empolyee("John", 2005, 70000, "Nashik");
		
		System.out.println("Name\tYear\tSalary\tAddress");
		
		e1.Display();
		e2.Display();
		e3.Display();
	}

}
