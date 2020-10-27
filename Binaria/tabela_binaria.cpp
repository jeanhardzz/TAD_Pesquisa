#include "tabela_binaria.h"
#include <iostream>

TabelaBinaria::TabelaBinaria(){
    this->n = 0;

}

int TabelaBinaria::Pesquisa(TipoItem x) {
    if (n == 0){ /* vetor vazio */
        return 0;
    }
    int i;
    int Esq = 1;
    int Dir = n;
    do {
        i = (Esq + Dir) / 2;
        if (x.GetChave() > Item[i].GetChave()){
            Esq = i + 1; /* procura na partição direita */
        }
        else{
            Dir = i - 1; /* procura na partição esquerda */
        }
    } while ((x.GetChave() != Item[i].GetChave()) && (Esq <= Dir));

    if (x.GetChave() == Item[i].GetChave()){
        return i;
    }
    return 0;
}


void TabelaBinaria::Ordena(){
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = n-1; j > i; j--) {
            if (Item[j-1].GetChave() > Item[j].GetChave()){
                /* comparações */
                TipoItem aux = Item[j-1];
                Item[j-1]=Item[j];
                Item[j]=aux;
                                
            }
        }
    }
}

void TabelaBinaria::AddItem(TipoItem x){
    Item[n] = x;
    n++;
}

void TabelaBinaria::Imprime(){
    for(int i=0;i<MAX;i++){
        std::cout<< Item[i].GetChave() << ", ";
    }
    
}