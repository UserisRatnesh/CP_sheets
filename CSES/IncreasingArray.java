import java.util.Scanner;

class IncreasingArray {
    public static void main(String[] args) {

        solveBetter();

    }

    public static void solveBetter() {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();
        long maxTillNow = 0;
        long ans = 0;
        for (long i = 0; i < n; i++) {
            long input = sc.nextLong();
            maxTillNow = Math.max(maxTillNow, input);
            ans += (maxTillNow - input);
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
