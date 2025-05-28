#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>  
#include "utils.h"

#define PROC_ALTA 3
#define PROC_NORMAL 2
#define PROC_BAIXA 1

int main() {

    srand(time(NULL));

    Processo *fila_alta = criar_fila();
    Processo *fila_normal = criar_fila();
    Processo *fila_baixa = criar_fila();

    // Nessa parte se inicializam os 20 processos com pid único, tempos de execuçao e suas prioridades
    
    for (int i = 1; i <= 20; i++) {
        
        int prioridade = rand() % 3; // prioridade aleatória entre 0, 1 ou 2
        int tempo_exec = 10 + rand() % 11; // gera um número inteiro aleatório em um intervalo fechado de 10 a 20, dividindo o resto do número gerado com o rand() por 11
      
        Processo *p = criar_processo(i, prioridade, tempo_exec);

        if (prioridade == 0) {
            enfileirar(&fila_alta, p);
        } else if (prioridade == 1) {
            enfileirar(&fila_normal, p);
        } else {
            enfileirar(&fila_baixa, p);
        }
    }

    int tempo_total = 0;

    printf("Iniciando escalonamento com fila de prioridades: \n\n");

    while (!fila_vazia(fila_alta) || !fila_vazia(fila_normal) || !fila_vazia(fila_baixa)) {
        
        // Executar 3 processos de alta prioridade
        for (int i = 0; i < PROC_ALTA; i++) {
            if (fila_vazia(fila_alta)){
                 break;
            }

            Processo *p = desenfileirar(&fila_alta);
            int fatia = 8 + rand() % 3; // 8 a 10

            if (fatia > p->tempo_restante) fatia = p->tempo_restante;

            printf("Tempo total: %d | PID: %d | Prioridade: Alta | Fatia: %d | Tempo restante antes: %d\n",
                tempo_total, p->pid, fatia, p->tempo_restante);

            Sleep(fatia * 1000);

            p->tempo_restante -= fatia;
            tempo_total += fatia;

            printf("Tempo restante após execução: %d\n", p->tempo_restante);

            if (p->tempo_restante <= 0) {
                printf("Processo PID %d concluído!\n\n", p->pid);
                free(p);
            } else {
                enfileirar(&fila_alta, p);
                printf("\n");
            }
        }

        // Executar 2 processos com prioridade normal 
        for (int i = 0; i < PROC_NORMAL; i++) {
            if (fila_vazia(fila_normal)) break;

            Processo *p = desenfileirar(&fila_normal);
            int fatia = 5 + rand() % 4; // 5 a 8

            if (fatia > p->tempo_restante) fatia = p->tempo_restante;

            printf("Tempo total: %d | PID: %d | Prioridade: Normal | Fatia: %d | Tempo restante antes: %d\n",
                tempo_total, p->pid, fatia, p->tempo_restante);

            Sleep(fatia * 1000);

            p->tempo_restante -= fatia;
            tempo_total += fatia;

            printf("Tempo restante após execução: %d\n", p->tempo_restante);

            if (p->tempo_restante <= 0) {
                printf("Processo PID %d concluído!\n\n", p->pid);
                free(p);
            } else {
                enfileirar(&fila_normal, p);
                printf("\n");
            }
        }

        // Executar 1 processo baixa prioridade
        for (int i = 0; i < PROC_BAIXA; i++) {
            if (fila_vazia(fila_baixa)) break;

            Processo *p = desenfileirar(&fila_baixa);
            int fatia = 2 + rand() % 4; // 2 a 5

            if (fatia > p->tempo_restante) fatia = p->tempo_restante;

            printf("Tempo total: %d | PID: %d | Prioridade: Baixa | Fatia: %d | Tempo restante antes: %d\n",
                tempo_total, p->pid, fatia, p->tempo_restante);

            Sleep(fatia * 1000);

            p->tempo_restante -= fatia;
            tempo_total += fatia;

            printf("Tempo restante após execução: %d\n", p->tempo_restante);

            if (p->tempo_restante <= 0) {
                printf("Processo PID %d concluído!\n\n", p->pid);
                free(p);
            } else {
                enfileirar(&fila_baixa, p);
                printf("\n");
            }
        }
    }

    printf("Todos os processos foram concluídos.\nTempo total de execução: %d segundos\n", tempo_total);

    return 0;
}
