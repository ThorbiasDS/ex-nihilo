// Playlist.cpp

#include "Playlist.h"
#include "Musica.h"
#include <string>
#include <iostream>

using namespace std;

Playlist::Playlist()
{
}

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
            delete this->musicas.busca(i);
        }
    }
}

Node<Musica *> Playlist::next_music()
{
    Node<Musica *> *proxima = musicas.busca(contador);
    if ((contador + 1) == musicas.tamanho)
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
        if ((this->musicas.busca(i)->dado->getTitulo()).compare(play->getMusicas().busca(i)->dado->getTitulo()) == 0)
        {
            quant++;
            this->getMusicas().remover(i);
            delete this->getMusicas().busca(i);
        }
    }
    // musicas.remove_elements(play->musicas);
    // delete play;
    return quant;
}

Playlist::Playlist(Playlist &play)
{
    this->nome = play.nome;
    this->contador = play.contador;
    this->musicas = play.musicas;
}

Playlist Playlist::operator+(Playlist *play)
{

    Playlist result;
    result = result + play;

    for (int i = 0; i < play->getMusicas().tamanho; i++)
    {
        for (int j = 0; j < this->getMusicas().tamanho; j++)
        {
            if (play->getMusicas().busca(i)->dado->getTitulo().compare(this->getMusicas().busca(j)->dado->getTitulo()) == 0)
            {
                continue;
            }
            else
            {
                result << (this->getMusicas().busca(j)->dado);
            }
        }
    }

    return result;
}

Playlist Playlist::operator+(Musica *music)
{
    Playlist result;
    result << (music);
    return result;
}

Playlist Playlist::operator-(Playlist *play)
{
    Playlist result;
    for (int i = 0; i < play->getMusicas().tamanho; i++)
    {
        for (int j = 0; j < this->getMusicas().tamanho; j++)
        {
            if (play->getMusicas().busca(i)->dado->getTitulo().compare(this->getMusicas().busca(j)->dado->getTitulo()) == 0)
            {
                continue;
            }
            else
            {
                result << (this->getMusicas().busca(j)->dado);
            }
        }
    }

    return result;
}

Playlist Playlist::operator-(Musica *music)
{
    Playlist result;

    for (int i = 0; i < this->getMusicas().tamanho; i++)
    {
        if (music->getTitulo().compare(this->getMusicas().busca(i)->dado->getTitulo()) == 0)
        {
            continue;
        }
        else
        {
            result.getMusicas().inserir(this->getMusicas().busca(i)->dado);
        }
    }
    return result;
}

void Playlist::operator>>(Musica *music)
{
    Node<Musica *> *aux = this->getMusicas().busca(this->getMusicas().tamanho - 1);
    if (aux->proximo == nullptr)
    {
        music = nullptr;
    }
    else
    {
        music = this->getMusicas().busca(this->getMusicas().tamanho - 1)->dado;
        this->getMusicas().remover(getMusicas().tamanho - 1);
        delete this->getMusicas().busca(this->getMusicas().tamanho-1);
    }    
}

void Playlist::operator<<(Musica *music){

    if( music != nullptr){
        this->getMusicas().cauda->proximo->dado=music;
        this->getMusicas().cauda->dado=music;
        this->musicas.tamanho++;
    }
}

