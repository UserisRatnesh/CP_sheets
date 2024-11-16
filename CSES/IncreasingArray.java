import java.util.Scanner;

class IncreasingArray {
    public static void main(String[] args) {

        solveBetter();

    }

    public static void solveBetter() {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();
        long maxTillNow = Integer.MIN_VALUE;
        long ans = 0;
        for (long i = 0; i < n; i++) {
            long input = sc.nextLong();
            if (input < maxTillNow) {
                ans += Math.abs(input - maxTillNow);
            } else {
                maxTillNow = input;
            }
        }
        System.out.println(ans);
        sc.close();
    }

    public static void solve() {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();
        long prev = sc.nextLong();
        long ans = 0;
        for (long i = 1; i < n; i++) {
            long input = sc.nextLong();
            if (input < prev) {
                ans += Math.abs(input - prev);
            } else {
                prev = input;
            }
        }
        System.out.println(ans);
        sc.close();
    }
}
