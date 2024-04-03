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

public class Ex7 {

}
