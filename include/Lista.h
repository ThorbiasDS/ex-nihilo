#ifndef LISTA_H
#define LISTA_H

#include "Node.h"
#include <iostream>

using namespace std;

// Criação do template
template <typename T>

class Lista
{
public:
    Node<T> *cabeca;
    Node<T> *cauda;
    int tamanho;

    Lista()
    {
        this->cabeca = nullptr;
        this->cauda = nullptr;
        this->tamanho = 0;
    }

    ~Lista()
    {
        //Verificar com o professor se isso está correto
        for (int i = 0; i < tamanho; i++)
        {
            remover(i);
        }
    }

    void inserir(T valor)
    {
        Node<T> *no = new Node(valor);

        if (cabeca == nullptr)
        {
            cabeca = cauda = no;
            tamanho++;
        }
        else
        {
            cauda->proximo = no;
            cauda = no;
            tamanho++;
        }
    }

    Node<T> *busca(int indice)
    {
        if (indice < tamanho && indice >= 0)
        {
            Node<T> *aux;
            aux = cabeca;

            for (int i = 0; i < indice; i++)
            {
                aux = aux->proximo;
            }
            return aux;
        }
        else
        {
            return nullptr;
        }
    }

    void remover(int indice)
    {
        Node<T> *p;

        if (indice == 0 && cabeca->proximo == nullptr)
        {
            p = cabeca;
            delete p;
            cabeca = cauda = nullptr;
            tamanho--;
        }
        else
        {
            if (indice == 0)
            {
                p = cabeca;
                cabeca = cabeca->proximo;
                delete p;
                tamanho--;
            }
            else if (indice > 0 && indice < tamanho)
            {
                p = busca(indice - 1);
                Node<T> *aux = p->proximo;
                p = aux->proximo;
                delete aux;
                tamanho--;
            }
            else if (indice > 0 && indice == tamanho)
            {
                p = busca(indice - 1);
                cauda = p;
                Node<T> *aux = cauda->proximo;
                delete aux;
                p->proximo = nullptr;
                tamanho--;
            }
        }
    }

    void add_elements(Lista<T> &list)
    {
        this->cauda->proximo = list.cabeca;
        this->cauda = list.cauda;
    }

    void remove_elements(Lista<T> &list)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (this->busca(i)->dado == list.busca(i)->dado)
            {
                this->remover(i);
            }
        }
    }

    Lista(Lista &list)
    {
        this->cabeca = list.cabeca;
        this->cauda = list.cauda;
        this->tamanho = list.tamanho;
    }

    Lista<T> operator+(Lista <T> &list)
    {
    }

    Lista <T> operator<<(Node <T> *no)
    {
    }

    Lista <T> operator>>(Node <T> *no)
    {
    }
};

#endif