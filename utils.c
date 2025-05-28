#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

Processo* criar_fila() {
    return NULL; // Cria uma lista vazia com um ponteiro NULL 
}

void enfileirar(Processo **fila, Processo *novo_processo) {
   
    if (*fila == NULL) { // Caso a fila esteja vazia
        *fila = novo_processo;  //o novo processo vai ser o primeiro elemento da fila
        novo_processo->prox = NULL; // novo_processo receeb o endereço de memória de prox, no caso o prox, que tem é o último elemento da lista. Assim, termina com NULL
    } 
    else {
        Processo *temp = *fila;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo_processo;
        novo_processo->prox = NULL;
    }
}

Processo* desenfileirar(Processo **fila) {
    if (*fila == NULL) return NULL;
    Processo *removido = *fila;
    *fila = removido->prox;
    removido->prox = NULL;
    return removido;
}

int fila_vazia(Processo *fila) {
    return (fila == NULL);
}

Processo* criar_processo(int pid, int prioridade, int tempo_execucao) {
    Processo *p = (Processo*) malloc(sizeof(Processo));
    if (!p) return NULL;
    p->pid = pid;
    p->prioridade = prioridade;
    p->tempo_execucao = tempo_execucao;
    p->tempo_restante = tempo_execucao;
    p->prox = NULL;
    return p;
}

void liberar_fila(Processo *fila) {
    Processo *atual = fila;
    while (atual != NULL) {
        Processo *prox = atual->prox;
        free(atual);
        atual = prox;
    }
}