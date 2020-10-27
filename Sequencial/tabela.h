#ifndef TABELA
#define TABELA

#include "../tipoitem.h"

#define MAX 1000
class Tabela {        
    protected:
        int n;
        TipoItem Item[MAX + 1];
    public:
        Tabela();
        int Pesquisa(TipoItem x);
        void AddItem(TipoItem x);
        void Imprime();
};

#endif