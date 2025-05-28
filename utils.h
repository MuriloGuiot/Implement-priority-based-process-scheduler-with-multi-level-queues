#ifndef UTILS_H
#define UTILS_H

typedef struct Processo {
    int pid;
    int tempo_execucao;
    int tempo_restante;
    int prioridade;
    struct Processo *prox;  // Para implementar fila encadeada
} Processo;

// Protótipos das funções de fila
Processo* criar_fila();
void enfileirar(Processo **fila, Processo *novo_processo);
Processo* desenfileirar(Processo **fila);
int fila_vazia(Processo *fila);
Processo* criar_processo(int pid, int prioridade, int tempo_execucao);
void liberar_fila(Processo *fila);

#endif
