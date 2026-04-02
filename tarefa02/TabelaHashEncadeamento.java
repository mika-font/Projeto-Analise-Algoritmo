package tarefa02;

import java.util.LinkedList;

public class TabelaHashEncadeamento<K, V> {
    
    private class Entrada {
        K chave;
        V valor;
        Entrada(K chave, V valor) { 
            this.chave = chave; 
            this.valor = valor; 
        }
    }
    
    private LinkedList<Entrada>[] tabela;
    private int capacidade;

    @SuppressWarnings("unchecked") // Parar os avisos de tipo genérico
    public TabelaHashEncadeamento(int capacidade) {
        this.capacidade = capacidade;
        tabela = new LinkedList[capacidade];
        for (int i = 0; i < capacidade; i++) {
            tabela[i] = new LinkedList<>();
        }
    }

    private int calcularHash(K chave) {
        return Math.abs(chave.hashCode() % capacidade);
    }

    public void inserir(K chave, V valor) {
        int indice = calcularHash(chave);
        
        // Verifica se a chave já existe para atualizar o valor
        for (Entrada entrada : tabela[indice]) {
            if (entrada.chave.equals(chave)) {
                entrada.valor = valor; 
                return;
            }
        }
        // Se não existir, adiciona no final da lista
        tabela[indice].add(new Entrada(chave, valor));
    }
    
    public V buscar(K chave) {
        int indice = calcularHash(chave);
        for (Entrada entrada : tabela[indice]) {
            if (entrada.chave.equals(chave)) {
                return entrada.valor;
            }
        }
        return null; // Se não encontrar
    }
}
