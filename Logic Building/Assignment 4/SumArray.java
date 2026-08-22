import java.util.*;

class SumArray{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a[] = new int[5];
        int sum = 0;

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }

        for (int n : a) {
            sum = sum + n;
        }

        System.out.println("The sum of all numbers is: " + sum);
    }
}