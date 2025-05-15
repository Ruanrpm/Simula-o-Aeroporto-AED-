#include <iostream>
#include <ctime>

#include "FilaPrioridadesLE.h"

using namespace std;

void PreencheSolicitacoes(no **SP, no **SD) {
    srand(time(0));

    
    for (int i = 0; i < 27; i++) {
        int aleat = 1 + (rand() % 2);
        int aleatPrior = 1 + (rand() % 2);
        if (aleat == 1) {
            *SP = insereFilaChegada(*SP , i+10 , aleatPrior);
        }
        else {
            *SD = insereFilaChegada(*SD , i+10 , aleatPrior);
        }
    }
}

int main() {
    no *SolicitacoesPouso;
    no *SolicitacoesDecolagem;

    SolicitacoesPouso = inicializaFP(SolicitacoesPouso);
    SolicitacoesDecolagem = inicializaFP(SolicitacoesDecolagem);

    PreencheSolicitacoes(&SolicitacoesPouso , &SolicitacoesDecolagem);

    cout << "solicitcoes de POUSO:" <<endl;
    exibe(SolicitacoesPouso);
    cout <<endl;
    cout << "--------------------------------" <<endl;
    cout << "solicitcoes de DECOLAGEM:" <<endl;
    exibe(SolicitacoesDecolagem);
}