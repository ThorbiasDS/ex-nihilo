#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Lista.h"
#include "Musica.h"
#include <iostream>

using namespace std;

class Playlist
{

private:
    string nome;
    Lista<Musica *> musicas;
    int contador;

public:

    Playlist(string nome);
    ~Playlist();

    string getNome();
    void setNome(string nome);

    Lista<Musica *> getMusicas();
    void setMusicas(Lista<Musica *> musicas);

    void adicionarMusica(string titulo, string artista);
    void removerMusica(string nome_musica);
    Node <Musica*> next_music();
    void print_music();

    void adicionarMusica(Playlist &play);
    void removerMusica(Playlist &play);
    Playlist(Playlist &play);

    Playlist operator+(Playlist &play);
    Playlist operator+(Musica *music);
    Playlist operator-(Playlist &play);
    Playlist operator-(Musica *music);
    Playlist operator>>(Musica *music);
    Playlist operator>>(Musica *music);
};

#endif