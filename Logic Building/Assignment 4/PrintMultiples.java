import java.util.*;

class PrintMultiples {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        for (int i = 3; i <= n; i += 3) {
            System.out.print(i + " ");
        }
    }
}