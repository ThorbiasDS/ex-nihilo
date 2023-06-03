/**
 * @author Hosana Iasmin & Tobias Daniel
 * @since 01/05/2023
 * @version 2.0
 */

#ifndef MUSICA_H
#define MUSICA_H

/**
 * @brief Essa classe define as músicas do nosso sistema
*/

#include <iostream>
#include <string>

using namespace std;

class Musica
{

private:

    /// @brief Atributos que guardam a informação de título e artista da música
    string titulo;
    string artista;

public:

    /// @brief Construtor da classe Música
    /// @param titulo String que será colocada no atributo titulo na hora da construção de um objeto Musica
    /// @param artista String que será colocada no atributo artista na hora da construção de um objeto Musica
    Musica(string titulo, string artista);

    //Destutor da classe
    ~Musica();

    /// @brief Métodos get e set para o atributo título
    string getTitulo();
    void setTitulo(string titulo);

    /// @brief Métodos get e set para o atributo título
    string getArtista();
    void setArtista(string artista);
};

#endif