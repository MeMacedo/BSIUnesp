/* https://codeforces.com/problemset/problem/1092/B */

import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class Ex3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Vector<Integer> studentList = new Vector<Integer>();
        int problems = 0;

        int N = scan.nextInt();
        scan.nextLine();

        for (int i = 0; i < N; i++) {
            int student = scan.nextInt();
            studentList.add(student);
        }

        scan.close();

        Collections.sort(studentList);

        for (int i = 0; i < N; i += 2) {
            problems += studentList.get(i + 1) - studentList.get(i);
        }

        System.out.println(problems);

    }
}
