import java.util.Scanner;

public class MissingNumber {
    public static void main(String[] args) {
        solve();
    }

    public static void solveImproved() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int xor = 0;
        for (int i = 0; i < n - 1; i++) {
            xor ^= sc.nextInt();
            xor ^= (i + 1);
        }
        xor ^= n;
        System.out.println(xor);
        sc.close();

    }

    // Why this one is givign TLE
    public static void solve() {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long sum = n * (n + 1) / 2;

        long currSum = 0;
        for (int i = 0; i < n - 1; i++) {
            currSum += sc.nextInt();
        }

        System.out.println(sum - currSum);
        sc.close();
    }

}
