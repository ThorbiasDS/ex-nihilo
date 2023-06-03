/**
 * @author Hosana Iasmin & Tobias Daniel
 * @since 01/05/2023
 * @version 2.0
 */

#ifndef NODE_H
#define NODE_H

/**
 * @brief Essa classe implementa os nós que serão utilizados na nossa lista
*/

#include <iostream>

using namespace std;

/// @brief Utilização de template para que o nó receba dados genéricos
template <typename T>

class Node
{
public:

    /// @brief A classe possui o atributo dado, que é genérico, e o atributo próximo, que guarda o endereço do próximo nó na lista
    T dado;
    Node *proximo;

    /// @brief Construtor da classe nó
    /// @param dado Dado genérico que será armazenado no nó
    Node(T dado)
    {
        this->dado = dado;
        this->proximo = nullptr;
    }

    /// @brief Destrutor da classe
    ~Node()
    {
    }
};

#endif