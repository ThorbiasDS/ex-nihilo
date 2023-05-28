#ifndef MUSICA_H
#define MUSICA_H

#include <iostream>
#include <string>

using namespace std;

class Musica
{

private:
    string titulo;
    string artista;

public:

    Musica(string titulo, string artista);
    ~Musica();

    string getTitulo();
    void setTitulo(string titulo);

    string getArtista();
    void setArtista(string artista);
};

#endif