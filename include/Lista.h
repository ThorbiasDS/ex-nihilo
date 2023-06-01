/**
 * @author Hosana Iasmin & Tobias Daniel
 * @since 01/05/2023
 * @version 2.0
 */

#ifndef LISTA_H
#define LISTA_H

/// @brief Essa classe implementa a nossa lista ligada, utilizando os nós criados na classe Node

#include "Node.h"
#include <iostream>

using namespace std;

/// @brief Criação do template
template <typename T>

class Lista
{
public:

    /// @brief Ponteiros para nós da cabeça e da cauda da lista e variável que armazena o tamanho da lista
    Node<T> *cabeca;
    Node<T> *cauda;
    int tamanho;

    /// @brief Construtor da classe
    Lista()
    {
        this->cabeca = nullptr;
        this->cauda = nullptr;
        this->tamanho = 0;
    }

    /// @brief Destrutor da classe para eliminar cada nó da classe
    ~Lista()
    {
        for (int i = 0; i < tamanho; i++)
        {
            remover(i);
        }
    }

    /// @brief Método para inserção de novos nós na lista. Verifica-se se ele é o primeiro elemento a ser inserido ou não
    /// @param valor Dado genérica para ser colocado no nó, pode ser playlist ou música
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


    /// @brief Esse método serve para encontrar um nó na lista
    /// @param indice O índice do elemento que se deseja encontrar
    /// @return O método retorna o nó desejado
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

    /// @brief O método remove um nó da lista verificando se ele vai ser removido no início, no meio ou no fim da lista
    /// @param indice Índice do nó a ser recebido
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

    /// @brief Método para adicionar outra playlist no fim da atual
    /// @param list Lista a ser adicionada no fim
    void add_elements(Lista<T> &list)
    {
        this->cauda->proximo = list.cabeca;
        this->cauda = list.cauda;
    }

    /// @brief Remove as músicas da playlist atual que estiverem na playlist recebida por parâmetro
    /// @param list Playlist que contêm as músicas que devem ser removidas
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

    /// @brief Construtor cópia 
    /// @param list Lista para servir como cópia
    Lista(Lista &list)
    {
        this->cabeca = list.cabeca;
        this->cauda = list.cauda;
        this->tamanho = list.tamanho;
    }

    /// @brief Método de sobrecarga do operador +, ele cria uma nova playlist contendo todas as músicas das duas playlists que estão sendo operadas
    /// @param list 
    /// @return 
    Lista<T> operator+(Lista<T> &list)
    {
        Lista result;
        result.cabeca = this->cabeca;
        result.cauda = list.cauda;
        return result;
    }

    /// @brief Método de sobrecarga do operador >>, ele extrai o último nó da lista e o atribui ao que é passado como argumento
    /// @param no Nó que receberá o último da lista
    void operator>>(Node<T> *no)
    {
        Node<T> *aux = busca((this->tamanho - 1));
        if (aux->proximo == nullptr)
        {
            no = nullptr;
        }
        else
        {
            no = aux->proximo;
            delete aux->proximo;
            this->tamanho--;
            this->cauda = aux;
        }
    }

    /// @brief Método de sobrecarga do operador <<, ele adiciona o nó que é recebido como argumento no fim da lista
    /// @param no Nó que será adicionado no fim da lista
    void operator<<(Node<T> *no)
    {
        if (no != nullptr)
        {
            cauda->proximo = no;
            cauda = no;
            tamanho++;
        }
    }
};

#endif