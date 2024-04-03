/*Escreva um programa que ordene uma lista de nomes de alunos. Para isso, o usuário irá
digitar um número inteiro N, indicando o número dos alunos, seguido de N linhas com o
nome de cada aluno. Após isso imprima a lista de nomes ordenados. Utilize a Collection
Vector e o método Collections.sort().*/

import java.util.*;

class ListaAlunos {
    public static void main(String[] args) {
        System.out.println("Digite a quantidade de alunos na lista.");
        Scanner scan = new Scanner(System.in);
        Vector<String> studentList = new Vector<String>();

        int N = scan.nextInt();
        scan.nextLine();

        for (int i = 0; i < N; i++) {
            String studentName = scan.nextLine();
            studentList.add(studentName);
        }

        Collections.sort(studentList);

        Iterator<String> i = studentList.iterator();

        System.out.println("Os alunos so:");

        while (i.hasNext()) {
            System.out.println(i.next());
        }

        scan.close();
    }
}
