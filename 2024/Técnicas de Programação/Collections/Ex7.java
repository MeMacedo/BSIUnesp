/* Resolva o problema beecrowd 2727. É obrigatório o uso de TreeMap<String,
Character> para decodificar a String lida. A iniciação do Map pode ser feito de
forma programática ou manualmente, adicionando os 26 códigos um a um para
cada caractere.
Definindo:
Map<String, Character> decodifica = new
TreeMap<String, Character>();
Manualmente, por exemplo, para a letra “i”, seria:
decodifica.put("... ... ...", 'i');
Para decodificar, basta ler o código de cada linha em uma String e usá-la
como chave na função get do decodifica.
Dica: para repetir até que os dados acabem, use:
while (tecl.hasNextLine()) {

Obs.: os tipos Generics, que são definidos entre o “<” e o “>”, não aceitam tipos
primitivos, portanto o tipo char precisa ser substituído por Character que é uma
classe. A conversão do tipo primitivo char para uma instância de Character
acontece automaticamente. */

import java.util.*;

class Ex7 {

    static Map<String, Character> code = new TreeMap<String, Character>();

    public static void main(String s[]) {
        createCode();
        Scanner in = new Scanner(System.in);
        int n = 0;
        String line;

        while ((in.hasNext())) {
            n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                line = in.nextLine();
                System.out.println(code.get(line));
            }

        }
        in.close();

    }

    static void createCode() {
        code.put(".", 'a');
        code.put("..", 'b');
        code.put("...", 'c');
        code.put(". .", 'd');
        code.put(".. ..", 'e');
        code.put("... ...", 'f');
        code.put(". . .", 'g');
        code.put(".. .. ..", 'h');
        code.put("... ... ...", 'i');
        code.put(". . . .", 'j');
        code.put(".. .. .. ..", 'k');
        code.put("... ... ... ...", 'l');
        code.put(". . . . .", 'm');
        code.put(".. .. .. .. ..", 'n');
        code.put("... ... ... ... ...", 'o');
        code.put(". . . . . .", 'p');
        code.put(".. .. .. .. .. ..", 'q');
        code.put("... ... ... ... ... ...", 'r');
        code.put(". . . . . . .", 's');
        code.put(".. .. .. .. .. .. ..", 't');
        code.put("... ... ... ... ... ... ...", 'u');
        code.put(". . . . . . . .", 'v');
        code.put(".. .. .. .. .. .. .. ..", 'w');
        code.put("... ... ... ... ... ... ... ...", 'x');
        code.put(". . . . . . . . .", 'y');
        code.put(".. .. .. .. .. .. .. .. ..", 'z');

    }
}
