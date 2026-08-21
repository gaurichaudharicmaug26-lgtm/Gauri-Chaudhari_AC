import java.util.*;

class CheckAge {
    static void checkAge(int age) {
        if (age < 18)
            System.out.println("Minor");
        else if (age < 60)
            System.out.println("Adult");
        else
            System.out.println("Senior Citizen");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter age: ");
        int age = sc.nextInt();

        checkAge(age);
    }
}