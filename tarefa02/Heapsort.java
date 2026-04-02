package tarefa02;

public class Heapsort {

    public void ordenar(int[] array) {
        int n = array.length;

        // Constrói a Max-Heap a partir do array original
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(array, n, i);
        }

        // Extrai os elementos da heap um por um
        for (int i = n - 1; i > 0; i--) {
            // Move a raiz atual (maior elemento) para o final
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;

            // Chama o heapify na heap reduzida para restaurar a propriedade da Max-Heap
            heapify(array, i, 0);
        }
    }

    // Método para reestruturar a sub-árvore e manter a propriedade de Max-Heap
    private void heapify(int[] array, int n, int i) {
        int maior = i;              // Inicializa o maior como a raiz
        int esquerda = 2 * i + 1;   // Filho da esquerda
        int direita = 2 * i + 2;    // Filho da direita

        // Se o filho da esquerda é maior que a raiz
        if (esquerda < n && array[esquerda] > array[maior]) {
            maior = esquerda;
        }

        // Se o filho da direita é maior que o maior até agora
        if (direita < n && array[direita] > array[maior]) {
            maior = direita;
        }

        // Se o maior não for a raiz, troca e aplica recursão
        if (maior != i) {
            int swap = array[i];
            array[i] = array[maior];
            array[maior] = swap;

            heapify(array, n, maior);
        }
    }
}
