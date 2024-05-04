/* https://judge.beecrowd.com/pt/problems/view/1069 */

import java.util.Stack;
import java.util.Scanner;

public class Ex4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();

        for (int i = 0; i < n; i++) {
            int diamonds = 0;
            Stack<Character> stack = new Stack<Character>();
            String mine = in.nextLine();
            for (char c : mine.toCharArray()) {
                if (c == '<') {
                    stack.push(c);
                } else if (c == '>') {
                    try {
                        stack.pop();
                        diamonds = diamonds + 1;
                    } catch (Exception e) {
                    }
                }
            }
            System.out.println(diamonds);
            diamonds = 0;

        }
        in.close();
    }
}
