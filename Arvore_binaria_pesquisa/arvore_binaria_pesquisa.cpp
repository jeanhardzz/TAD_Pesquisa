#include "arvore_binaria_pesquisa.h"

ArvoreBinaria::ArvoreBinaria(){
    raiz = 0;
}

ArvoreBinaria::~ArvoreBinaria(){
    Limpa();
}

void ArvoreBinaria::Limpa(){
    ApagaRecursivo(raiz);
    raiz = 0;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
    if(p!=0){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

TipoItem ArvoreBinaria::Pesquisa(TipoChave chave) {
    return PesquisaRecursivo(raiz, chave);
}


TipoItem ArvoreBinaria::PesquisaRecursivo(TipoNo *no, TipoChave chave) {
    TipoItem aux;
    if (no == 0) {
        aux.SetChave(-1); // Flag para item não presente
        return aux;
    }
    if (chave < no->item.GetChave())
        return PesquisaRecursivo(no->esq, chave);
    else if (chave>no->item.GetChave())
        return PesquisaRecursivo(no->dir, chave);
    else
        return no->item;
}

void ArvoreBinaria::Insere(TipoItem item){
    InsereRecursivo(raiz,item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoItem item){
    if(p==0){
        p = new TipoNo();
        p->item = item;
    }
    else{
        if(item.GetChave() < p->item.GetChave())
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void ArvoreBinaria::Remove(TipoChave chave) {
    return RemoveRecursivo(raiz, chave);
}

void ArvoreBinaria::RemoveRecursivo(TipoNo* &no, TipoChave chave){
    TipoNo *aux;
    if (no == 0) {
        throw("Item nao está presente");
    }
    if (chave < no->item.GetChave())
        return RemoveRecursivo(no->esq, chave);
    else if (chave>no->item.GetChave())
        return RemoveRecursivo(no->dir, chave);
    else {
        if (no->dir == 0) {
            aux = no;
            no = no->esq;
            delete(aux);
        }
        else if(no->esq == 0) {
            aux = no;
            no = no->dir;
            delete(aux);
        }
        else
            Antecessor(no, no->esq);
    }
}

void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo* &r){
    if(r->dir != 0) {
        Antecessor(q, r->dir);
        return;
    }
    q->item = r->item;
    q = r;
    r = r->esq;
    delete(q);
}

void ArvoreBinaria::PreOrdem(TipoNo *p){
    //visita o no, depois os filhos da esquerda e depois os da direita
    if(p!=0){
        p->item.Imprime();
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void ArvoreBinaria::InOrdem(TipoNo *p){
    //Visita o filho da esquerda, o nó, e depois o filho da direita
    if(p!=0){
        InOrdem(p->esq);
        p->item.Imprime();
        InOrdem(p->dir);
    }
}

void ArvoreBinaria::PosOrdem(TipoNo *p){
    //Visita os filhos da esquerda e da direita e depois o nó
    if(p!=0){
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        p->item.Imprime();
    }
}

void ArvoreBinaria::PorNivel(){
    //Visita os nodos de cada nível em sequência
    FilaArranjo F; // fila de apontadores para nos
    TipoNo *p;
    F.Enfileira(raiz);
    while(!F.Vazia()) {
        p = F.Desenfileira();
        if(p!=0) {
            p->item.Imprime();
            F.Enfileira(p->esq);
            F.Enfileira(p->dir);
        }
    }
}