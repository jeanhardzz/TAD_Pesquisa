#ifndef TABELA_BINARIA
#define TABELA_BINARIA

#include "../tipoitem.h"

#define MAX 1000
class TabelaBinaria {        
    protected:
        int n;
        TipoItem Item[MAX + 1];
    public:
        TabelaBinaria();
        int Pesquisa(TipoItem x);
        void AddItem(TipoItem x);
        void Imprime();
        void Ordena();
};

#endif