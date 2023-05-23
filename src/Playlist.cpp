#include "Playlist.h"
#include "Musica.h"
#include <string>
#include <iostream>

using namespace std;

Playlist::Playlist(string nome)
{
    this->nome = nome;
    this->contador = 0;
}

Playlist::~Playlist()
{
}

string Playlist::getNome()
{
    return this->nome;
}

void Playlist::setNome(string nome)
{
    this->nome = nome;
}

Lista<Musica *> Playlist::getMusicas()
{
    return this->musicas;
}

void Playlist::setMusicas(Lista<Musica *> musicas)
{
    this->musicas = musicas;
}

void Playlist::adicionarMusica(string titulo, string artista)
{
    Musica *song = new Musica(titulo, artista);
    musicas.inserir(song);
}

void Playlist::removerMusica(string titulo)
{
    for (int i = 0; i < musicas.tamanho; i++)
    {
        if (musicas.busca(i)->dado->getTitulo().compare(titulo) == 0)
        {
            musicas.remover(i);
        }
    }
}

Node<Musica *> Playlist::next_music()
{
    Node<Musica *> *proxima = musicas.busca(contador);
    if((contador+1) == musicas.tamanho)
    {
        return nullptr;
    }
    else
    {
        proxima = musicas.busca(++contador);
        return *proxima;
    }
}

void print_music(Lista<Musica *> songs, int tamanho)
{
    if (tamanho < 0)
    {
        return;
    }
    else
    {
        cout << songs.busca(tamanho)->dado->getTitulo() << endl;
        print_music(songs, tamanho - 1);
    }
}

void Playlist::adicionarMusica(Playlist *play)
{
    musicas.add_elements(play->musicas);
}

int Playlist::removerMusica(Playlist *play)
{
    int quant = 0;
    for (int i = 0; i < play->getMusicas().tamanho; i++)
    {
        if(this->musicas.busca(i)->dado->getTitulo() == play->getMusicas().busca(i)->dado->getTitulo())
        {
            quant++;
        }
    }
    musicas.remove_elements(play->musicas);
}

Playlist::Playlist(Playlist &play)
{
    Playlist nova(play.getNome());
    nova.musicas = play.getMusicas();
    nova.contador = play.contador;
}