
public class Student {
	
	String name;
	int roll_no;
	String phone_no;
	String address;
	

	public static void main(String[] args) {
		
		//a
		Student s1 = new Student();
		s1.roll_no = 2;
		s1.name = "John";
		
		System.out.println("Roll_No:" + s1.roll_no);
		System.out.println("Name:" + s1.name);
		
		//b
		Student s2 = new Student();
		s2.name = "Sam";
		s2.roll_no = 10;
		s2.phone_no = "9921308487";
		s2.address = "Siddivinayak colone,Pune";
		
		Student s3 = new Student();
		s3.name = "John";
		s3.roll_no = 17;
		s3.phone_no = "7385742801";
		s3.address = "Desipura colone,Mumbai";
		
		System.out.println("\nStudent 1:" );
		System.out.println("Name:" +s2.name );
		System.out.println("Roll_No:" +s2.roll_no );
		System.out.println("Phone_No:" +s2.phone_no);
		System.out.println("Address:" +s2.address );
		
		System.out.println("\nStudent 2:" );
		System.out.println("Name:" +s3.name );
		System.out.println("Roll_No:" +s3.roll_no );
		System.out.println("Phone_No:" +s3.phone_no);
		System.out.println("Address:" +s3.address );
		
	}

}
