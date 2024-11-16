import java.util.Scanner;

/**
 * Permutations
 */
public class Permutations {

    public static void main(String[] args) {
        solve();

    }

    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        if (n == 1) {
            System.out.println(1);
        } else if (n == 2 || n == 3) {
            System.out.println("NO SOLUTION");
        } else {
            // Print even numbers
            StringBuilder sb = new StringBuilder();
            for (int i = 2; i <= n; i += 2) {
                sb.append(i).append(" ");
            }
            // Print odd numbers
            for (int i = 1; i <= n; i += 2) {

                sb.append(i).append(" ");

            }
            System.out.println(sb.toString());
        }

        scanner.close();
    }

    // Why this is wrong
    // Because If the input size n is very large,
    // the repeated use of System.out.print could slow down the execution
    // significantly
    // because each print call flushes the output buffer.
    //
    // Therefore stringBuilder to build output as single string and
    // then print it in one go.
    public static void solveWrong() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        if (n == 1) {
            System.out.println(1);
        } else if (n == 2 || n == 3) {
            System.out.println("NO SOLUTION");
        } else {
            // Print even numbers
            for (int i = 2; i <= n; i += 2) {
                System.out.print(i + " ");
            }
            // Print odd numbers
            for (int i = 1; i <= n; i += 2) {
                System.out.print(i + " ");
            }
        }

        scanner.close();
    }
}
