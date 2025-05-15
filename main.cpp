#include <iostream>
#include <ctime>

#include "FilaPrioridadesLE.h"

using namespace std;

// função para preencher as filas de solicitação de pouso;
void PreencheSolicitacoes(no **SPeD) {
    srand(time(0));
    
    for (int i = 0; i < 27; i++) {
        int aleatPrior = 1 + (rand() % 2);
        *SPeD = insereFilaChegada(*SPeD , i+10 , aleatPrior);
    }
}

int main() {
    bool continua = true;
    no *FP1, *FP2;
    no *SolicitacoesPeD;
    int num, prioridade;

    FP1 = inicializaFP(FP1);
    FP2 = inicializaFP(FP2);
    SolicitacoesPeD = inicializaFP(SolicitacoesPeD);

    PreencheSolicitacoes(&SolicitacoesPeD);

    cout << "Solicitacoes: ";
    exibe(SolicitacoesPeD);
    cout <<endl;

    for (int ut = 1; continua; ut++) {
        srand(time(0));
        // Quantidade de solicitações de pouso por ut;
        for (int solicitacoes = 0; solicitacoes < 5; solicitacoes++) {
            // uso do rand() para decidir se é uma solicitação de pouso ou decolagem;
            int aleat = 1 + (rand() % 2);
            if (aleat == 1) {
                if (!verificaSeVazia(SolicitacoesPeD)) {
                    SolicitacoesPeD = removeFP(SolicitacoesPeD, &num, &prioridade);
                    FP1 = insereFP(FP1, num, prioridade);
                }  
            }
            else {
                if (!verificaSeVazia(SolicitacoesPeD)) {
                    SolicitacoesPeD = removeFP(SolicitacoesPeD, &num, &prioridade);
                    FP2 = insereFP(FP2, num, prioridade);
                }
            }
        }
    }
    cout <<endl << "Fila de solicitacoes de POUSO:";
    exibe(FP1);
    cout <<endl;
    cout << "Fila de solicitacoes de Decolagem:";
    exibe(FP2);
}