import java.util.*;

class Ascendingorder {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a[] = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);

        System.out.print("Sorted array: ");

        for (int i = 0; i < 5; i++) {
            System.out.print(a[i] + " ");
        }
    }
}