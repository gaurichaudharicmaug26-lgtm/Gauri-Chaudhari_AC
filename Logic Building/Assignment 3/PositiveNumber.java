import java.util.*;

class PositiveNumber1{
    static void positive() {
        Scanner sc = new Scanner(System.in);
        int n;

        do {
            System.out.print("Enter positive number: ");
            n = sc.nextInt();
        } while (n <= 0);

        System.out.println(" I Entered: " + n);
    }

    public static void main(String[] args) {
        positive();
    }
}