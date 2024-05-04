/*Reescreva o programa anterior, mas agora utilizando uma TreeSet.*/

import java.util.*;

class ListaAlunos {
    public static void main(String[] args) {
        System.out.println("Digite a quantidade de alunos na lista.");
        Scanner scan = new Scanner(System.in);
        TreeSet<String> studentList = new TreeSet<String>();

        int N = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < N; i++) {
            String studentName = scan.nextLine();
            studentList.add(studentName);
        }

        Iterator<String> i = studentList.iterator();

        System.out.println("Os alunos sao:");

        while (i.hasNext()) {
            System.out.println(i.next());
        }

        scan.close();
    }
}
