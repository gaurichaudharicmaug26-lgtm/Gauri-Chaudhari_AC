import java.util.*;

class  PNNumber{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a[] = new int[6];
        int positive = 0;
        int negative = 0;

        System.out.println("Enter 6 integers:");

        for (int i = 0; i < 6; i++) {
            a[i] = sc.nextInt();
        }

        for (int n : a) {
            if (n > 0)
                positive++;

            if (n < 0)
                negative++;
        }

        System.out.println("Positive numbers: " + positive);
        System.out.println("Negative numbers: " + negative);
    }
}