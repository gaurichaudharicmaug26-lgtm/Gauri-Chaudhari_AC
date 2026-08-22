import java.util.*;

class FindIndex {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a[] = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);

        System.out.print("Enter the number to search: ");
        int n = sc.nextInt();

        int index = Arrays.binarySearch(a, n);

        if (index >= 0) {
            System.out.println("The number " + n +
                    " is found at index " + index);
        } else {
            System.out.println("Not Found");
        }
    }
}