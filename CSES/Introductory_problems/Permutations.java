import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Scanner;

/**
 * Permutations
 */
public class Permutations {

    public static void main(String[] args) throws Exception {
        solveBuffrederWriter();

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

    // Now we will use buffered writer to make output faster then simple
    // System.out.println()
    public static void solveBuffrederWriter() throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.close();

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        if (n == 1) {
            writer.write(1 + ""); // We need to convert 1 to string to print using writer because writer tries to
                                  // print the unicode character represented by the interger value i.e. 1 here. so
                                  // we need to convert ot string before printing using buffered writer
        } else if (n == 2 || n == 3) {
            writer.write("NO SOLUTION");
        } else {
            for (int i = 2; i <= n; i += 2) {
                writer.write(i + " ");
            }
            for (int i = 1; i <= n; i += 2) {
                writer.write(i + " ");
            }
        }
        writer.flush();
        writer.close();
    }
}
