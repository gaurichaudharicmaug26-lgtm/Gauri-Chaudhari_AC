class EvenNumber {
    static void printEven() {
        int i = 2;

        while (i <= 50) {
            System.out.print(i + " ");
            i += 2;
        }
    }

    public static void main(String[] args) {
        printEven();
    }
}