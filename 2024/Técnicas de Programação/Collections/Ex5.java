/* https://judge.beecrowd.com/en/problems/view/1244 */
import java.util.*;

class Comp implements Comparator<String> {
    public int compare(String a, String b) {
        if (a.length() == b.length()) {
            return 0;
        }
        if (a.length() > b.length()) {
            return -1;
        }
        return 1;
    }
}

public class Ex5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();

        for (int i = 0; i < n; i++) {
            String line = in.nextLine();
            String[] splitLine = line.split(" ");
            List<String> list = Arrays.asList(splitLine);

            list.sort(new Comp());

            Iterator<String> it = list.iterator();

            while (it.hasNext()) {
                System.out.print(it.next());

                if (it.hasNext()) {
                    System.out.print(" ");
                } else {
                    System.out.print("");
                }

            }
            System.out.print("\n");
        }

        in.close();
    }
}
