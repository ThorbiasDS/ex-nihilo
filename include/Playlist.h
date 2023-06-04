/**
 * @author Hosana Iasmin & Tobias Daniel
 * @since 01/05/2023
 * @version 2.0
 */

#ifndef PLAYLIST_H
#define PLAYLIST_H

/**
 * @brief Essa classe define as playlists do nosso sistema
*/

#include "Lista.h"
#include "Musica.h"
#include <iostream>

using namespace std;

class Playlist
{

private:

    /// @brief A classe possui como atributos o seu nome, a lista de música que ela irá possuir e um contador que servirá no método de avançar a música que está sendo tocada
    string nome;
    Lista<Musica *> musicas;
    int contador;

public:
    
    /// @brief Usando sobrecarga para os construtores, em que um não receberá nenhum valor na criação do objeto e o outro receberá o nome da playlist
    Playlist();
    Playlist(string nome);

    /// @brief Destrutor da classe
    ~Playlist();

    /// @brief Métodos get e set da para o atributo nome
    string getNome();
    void setNome(string nome);

    /// @brief Métodos get e set da para o atributo da lista de músicas
    Lista<Musica *> getMusicas();
    void setMusicas(Lista<Musica *> musicas);

    /// @brief Método que servirá para adicionar músicas na playlist
    /// @param titulo Título da música a ser adicionada
    /// @param artista Nome da artista da música
    void adicionarMusica(string titulo, string artista);

    /// @brief Método para remoção de músicas da playlist
    /// @param titulo Título da música a ser removida
    void removerMusica(string titulo);

    /// @brief Método para que a próxima música da playlist seja tocada
    /// @return Retorna o nó contendo a próxima música a ser tocada
    Node <Musica*> next_music();

    /// @brief Método para a impressão das músicas da playlist
    void print_music();

    /// @brief Sobrecarga do método de adição de músicas
    /// @param play Recebe uma playlist, em que suas músicas serão adicionadas à playlist que está sendo manipulada
    void adicionarMusica(Playlist *play);

    /// @brief Sobrecarga do método de remoção de músicas
    /// @param play Recebe uma playlist, em que suas músicas serão removidas à playlist que está sendo manipulada
    /// @return Remove a quantidade de músicas removidas
    int removerMusica(Playlist *play);

    /// @brief Sobrecarga do construtor da classe, este serve como um construtor cópia
    /// @param play Recebe a playlist que servirá de molde para a cópia
    Playlist(Playlist &play);

    /// @brief Sobrecarga do operador + para adição de músicas
    /// @param play Recebe uma playlist, em que terão as músicas adicionadas à playlist que está sendo manipulada (não permite a adição de músicas repetidas)
    /// @return Retorna uma nova playlist contendo todas as músicas das duas playlists que foram somadas
    Playlist operator+(Playlist *play);

    /// @brief Sobrecarga do operador + para adição de músicas 
    /// @brief Recebe uma música que será adicionada ao final da playlist
    Playlist operator+(Musica *music);

    /// @brief Sobrecarga do operador -
    /// @param play Recebe uma playlist para que seja feita a diferença entre as músicas da playlist que está sendo manipulada e ela
    /// @return Retorna uma nova playlist após ter sido feita a diferença entre as playlists
    Playlist operator-(Playlist *play);

    /// @brief Sobrecarga do operador -
    /// @param music Recebe a música que deve ser subtraída da playlist que está sendo manipulada
    /// @return Retorna uma nova playlist após ter sido feita a subtração
    Playlist operator-(Musica *music);

    /// @brief Sobrecarga do operador >> 
    /// @param music Recebe uma música em que será armazenada a última música da playlist
    void operator>>(Musica *music);


    /// @brief Sobrecarga do operador <<
    /// @param music Recebe uma música que será adicionada no final da playlist
    /// @return Retorna uma nova playlist contendo a nova música que foi adicionada
    void operator<<(Musica *music);
};

#endif
