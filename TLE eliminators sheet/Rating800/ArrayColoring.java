import java.util.Scanner;

public class ArrayColoring {
    private static void A1857() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += sc.nextInt();
            }

            if (sum % 2 == 0)
                System.out.println("Yes");
            else
                System.out.println("No");

        }
        sc.close();
    }

    public static void main(String[] args) {
        A1857();
    }

}
