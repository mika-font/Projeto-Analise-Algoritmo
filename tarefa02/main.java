// Executar o arquivo fora da pasta tarefa02 para evitar problemas de importação
// javac tarefa02/*.java
// java tarefa02.Main
// Teste do Heapsort, Tabela Hash Encadeamento e Tabela Hash Endereçamento Aberto

package tarefa02;
public class Main {
    public static void main(String[] args) {
        System.out.println("--- Teste Algoritmo Heapsort ---");
        Heapsort heap = new Heapsort();
        int[] array = {12, 11, 13, 5, 6, 7};
        heap.ordenar(array);
        System.out.print("Array ordenado: ");
        for (int num : array) System.out.print(num + " ");
        System.out.println("\n");

        System.out.println("--- Teste Tabela Hash Encadeamento ---");
        TabelaHashEncadeamento<String, Integer> hashEncad = new TabelaHashEncadeamento<>(5);
        hashEncad.inserir("Schirmer", 25);
        hashEncad.inserir("Raissa", 30);
        hashEncad.inserir("Franchesco", 22);
        System.out.println("Matricula do Franchesco: " + hashEncad.buscar("Franchesco"));

        System.out.println("\n--- Teste Tabela Hash Endereçamento Aberto ---");
        TabelaHashEnderecamentoAberto<String, Integer> hashAberto = new TabelaHashEnderecamentoAberto<>(5);
        hashAberto.inserir("Mika", 100);
        hashAberto.inserir("Julia", 200);
        hashAberto.inserir("Angelo", 300);
        System.out.println("Matricula do Angelo: " + hashAberto.buscar("Angelo"));
    }
}
