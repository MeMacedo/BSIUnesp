/* Resolva o problema beecrowd 2174. É obrigatório o uso de TreeSet<String>
para definir o conjunto de pomekons.

Dica: Como o conjunto criado com TreeSet não aceita repetições, basta inserir 
os pokemons na lista, mesmo se repetidos, pois eles serão inseridos apenas
uma vez. */

import java.util.*;

class Ex6 {

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int n = 0;
        int pomekonQuant = 151;
        Set<String> team = new TreeSet<String>();

        n = in.nextInt();
        in.nextLine();
        for (int i = 0; i < n; i++) {
            String pomekon = in.nextLine();
            team.add(pomekon);
        }

        System.out.println(String.format("Falta(m) %d pomekon(s).", pomekonQuant - team.size()));
        in.close();

    }

}
