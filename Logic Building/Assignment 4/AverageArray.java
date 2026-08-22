import java.util.*;

class AverageArray{
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

        double average = sum / 5.0;

        System.out.println("The average of the numbers is: " + average);
    }
}