#include "Musica.h"
#include <iostream>

using namespace std;

Musica::Musica(string titulo, string artista)
{
    this->titulo = titulo;
    this->artista = artista;
}

Musica::~Musica()
{
}

string Musica::getTitulo()
{
    return this->titulo;
}

void Musica::setTitulo(string titulo)
{
    this->titulo = titulo;
}

void Musica::setArtista(string artista)
{
    this->artista = artista;
}

string Musica::getArtista()
{
    return this->artista;
}