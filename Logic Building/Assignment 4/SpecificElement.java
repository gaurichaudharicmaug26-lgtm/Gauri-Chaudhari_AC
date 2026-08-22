import java.util.*;

class SpecificElement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Integer a[] = new Integer[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }

        System.out.print("Enter the number to search: ");
        int n = sc.nextInt();

        if (Arrays.asList(a).contains(n)) {
            System.out.println("Found");
        } else {
            System.out.println("Not Found");
        }
    }
}