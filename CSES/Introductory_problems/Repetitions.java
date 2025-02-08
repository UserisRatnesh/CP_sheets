import java.util.Scanner;

/**
 * Repetitions
 */
public class Repetitions {

    public static void main(String[] args) {
        solveBetter();
    }

    public static void solveBetter() {
        Scanner sc = new Scanner(System.in);

        int ans = 0;
        String str = sc.next();
        int n = str.length();

        char prev = 'S';
        int count = 0;
        for (int i = 0; i < n; i++) {
            char c = str.charAt(i);
            if (c == prev) {
                count++;
            } else {
                count = 1;
                prev = c;
            }
            ans = Math.max(ans, count);
        }
        System.out.println(ans);
        sc.close();
    }
}
