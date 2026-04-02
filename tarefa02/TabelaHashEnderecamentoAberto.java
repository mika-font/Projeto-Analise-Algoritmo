package tarefa02;

public class TabelaHashEnderecamentoAberto<K, V> {
    private K[] chaves;
    private V[] valores;
    private int capacidade;
    private int tamanhoAtual;

    @SuppressWarnings("unchecked") // Parar os avisos de tipo genérico
    public TabelaHashEnderecamentoAberto(int capacidade) {
        this.capacidade = capacidade;
        chaves = (K[]) new Object[capacidade];
        valores = (V[]) new Object[capacidade];
        this.tamanhoAtual = 0;
    }

    private int calcularHash(K chave) {
        return Math.abs(chave.hashCode() % capacidade);
    }

    public void inserir(K chave, V valor) {
        if (tamanhoAtual >= capacidade) {
            throw new RuntimeException("A Tabela Hash está cheia!");
        }

        int indice = calcularHash(chave);

        // Sondagem Linear: procura o próximo espaço vazio
        while (chaves[indice] != null) {
            // Se a chave já existe, apenas atualiza o valor
            if (chaves[indice].equals(chave)) {
                valores[indice] = valor;
                return;
            }
            indice = (indice + 1) % capacidade; 
        }

        chaves[indice] = chave;
        valores[indice] = valor;
        tamanhoAtual++;
    }

    public V buscar(K chave) {
        int indice = calcularHash(chave);
        int indiceInicial = indice;

        while (chaves[indice] != null) {
            if (chaves[indice].equals(chave)) {
                return valores[indice];
            }
            indice = (indice + 1) % capacidade;
            // Se voltou ao início, a chave não está na tabela
            if (indice == indiceInicial) break;
        }
        return null;
    }
}