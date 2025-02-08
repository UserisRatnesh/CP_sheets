import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class MissingNumber {
    public static void main(String[] args) throws Exception {
        solveThird();
    }

    // Time complexity = O(n)
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

    // Time complexity = O(n)
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

    // Time complexity = O(n*log(n))
    // Therefore giving TLE

    public static void solveThird() throws Exception {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());

        int[] arr = Arrays.stream(reader.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
        Arrays.sort(arr);

        for (int i = 0; i < n - 1; ++i) {
            int val = arr[i];
            if (val != i + 1) {
                System.out.println(i + 1);
                return;
            }
        }
        System.out.println(n);

    }

}
