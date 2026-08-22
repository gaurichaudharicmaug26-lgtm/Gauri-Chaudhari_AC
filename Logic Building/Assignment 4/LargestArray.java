import java.util.*;

class LargestArray{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a[] = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);

        System.out.println("The largest element is: " + a[4]);
    }
}