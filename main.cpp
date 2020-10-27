#include <iostream>

#include "tipoitem.h"
#include "Sequencial/tabela.h"
#include "Binaria/tabela_binaria.h"
#include "Arvore_binaria_pesquisa/arvore_binaria_pesquisa.h"

int main(){
    int i;
    TipoItem x, aux;
    x.SetChave(0);
    TipoChave x2=9;

    //Teste Sequencial
    Tabela Sequencial;

    for(i=0;i<1000;i++){
        aux.SetChave(rand()%100);
        Sequencial.AddItem(aux);
    }

    //Sequencial.Imprime();
    std::cout<<"\n\n"<<Sequencial.Pesquisa(x)<<std::endl;

    //Teste Binario
    TabelaBinaria Binaria;    

    for(i=0;i<1000;i++){
        aux.SetChave(rand()%100);
        Binaria.AddItem(aux);
    }

    Binaria.Ordena();
    //Binaria.Imprime();
    std::cout<<"\n\n"<<Binaria.Pesquisa(x)<<std::endl;

    //Teste Arvore Binaria de Pesquisa
    ArvoreBinaria arvore;

    for(i=0;i<1000;i++){
        aux.SetChave(rand()%100);
        arvore.Insere(aux);
    }
    aux=arvore.Pesquisa(x2);
    std::cout<<"\n\n"<<aux.GetChave()<<std::endl;
    

    return 0;
}