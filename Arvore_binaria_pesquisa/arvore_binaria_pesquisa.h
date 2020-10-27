#ifndef ARVORE_BINARIA_PESQUISA
#define ARVORE_BINARIA_PESQUISA

#include "../tipoitem.h"
#include "tipono.h"
#include "fila_arranjo.h"

class ArvoreBinaria{
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        void Insere(TipoItem item);//
        void Caminha(int tipo);
        TipoItem Pesquisa(TipoChave chave);//
        void Remove(TipoChave chave);//
        void Limpa();
    private:
        void InsereRecursivo(TipoNo* &p, TipoItem item);//
        void ApagaRecursivo(TipoNo* p);
        TipoItem PesquisaRecursivo(TipoNo* p, TipoChave chave);//
        void RemoveRecursivo(TipoNo* &p, TipoChave chave);//
        void Antecessor(TipoNo* q, TipoNo* &r);//
        void PorNivel();
        void PreOrdem(TipoNo* p);
        void InOrdem(TipoNo* p);
        void PosOrdem(TipoNo* p);
        TipoNo *raiz;
};

#endif