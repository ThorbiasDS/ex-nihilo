#ifndef LISTA_H
#define LISTA_H

#include "Node.h"
#include <iostream>

using namespace std;

//Criação do template
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
        // for (int i = 0; i < tamanho; i++)
        // {
        //     remover(0);
        // }
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

    Node<T> *busca(int n)
    {
        if (n < tamanho && n >= 0)
        {
            Node<T> *p;
            p = cabeca;

            for (int i = 0; i < n; i++)
            {
                p = p->proximo;
            }
            return p;
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
};

#endif