#include "tabela.h"
#include <iostream>

Tabela::Tabela(){
    this->n = 0;

}

int Tabela::Pesquisa(TipoItem x) {
    Item[0].SetChave(x.GetChave());  /* sentinela */
    int i = n + 1;

    do {
        i--;
    } while (Item[i].GetChave() != x.GetChave());

    return i;
}

void Tabela::AddItem(TipoItem x){
    Item[n] = x;
    n++;
}

void Tabela::Imprime(){
    for(int i=0;i<MAX;i++){
        std::cout<< Item[i].GetChave() << ", ";
    }
    
}