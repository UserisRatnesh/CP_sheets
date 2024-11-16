import java.util.Scanner;

/**
 * Repetitions
 */
public class Repetitions {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int ans = 1;
        String str = sc.next();
        int n = str.length();

        char prev = str.charAt(0);
        int count = 1;
        for (int i = 1; i < n; i++) {
            char c = str.charAt(i);
            if (c == prev) {
                count++;
            } else {
                prev = c;
                count = 1;
            }
            ans = Math.max(count, ans);
        }
        System.out.println(ans);
        sc.close();
    }
}
