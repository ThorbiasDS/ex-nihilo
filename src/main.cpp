#include "Musica.h"
#include "Playlist.h"
#include <iostream>
#include <string>

using namespace std;

Lista<Musica *> louvores;
Lista<Playlist *> library;

// Funções pertencentes à opção Gerenciar Músicas

void adicionar_musicas(string title, string author)
{
    Musica *louvor = new Musica(title, author);
    louvores.inserir(louvor);
}

void remover_musicas(string title)
{
    for (int i = 0; i < library.tamanho; i++)
    {
        for (int j = 0; j < library.busca(i)->dado->getMusicas().tamanho; j++)
        {
            if (library.busca(i)->dado->getMusicas().busca(j)->dado->getTitulo().compare(title) == 0)
            {
                library.busca(i)->dado->getMusicas().remover(j);
                delete library.busca(i)->dado->getMusicas().busca(j);
            }
        }
    }

    for (int i = 0; i < louvores.tamanho; i++)
    {
        if (louvores.busca(i)->dado->getTitulo().compare(title) == 0)
        {
            louvores.remover(i);
            delete louvores.busca(i);
        }
    }
}

void listar_musicas()
{
    for (int i = 0; i < louvores.tamanho; i++)
    {
        cout << louvores.busca(i)->dado->getTitulo() << " - " << louvores.busca(i)->dado->getArtista() << endl;
    }
}

// Funções referentes à opção Gerenciar Playlists

Node<Playlist *> *tocar_playlist(string name)
{
    for (int i = 0; i < library.tamanho; i++)
    {
        if (library.busca(i)->dado->getNome().compare(name) == 0)
        {
            return library.busca(i);
        }
    }
    return nullptr;
}

void adicionar_playlists(string name)
{
    Playlist *play = new Playlist(name);
    library.inserir(play);
}

void listar_playlists()
{
    for (int i = 0; i < library.tamanho; i++)
    {
        cout << library.busca(i)->dado->getNome() << endl;
    }
}

void remover_playlists(string name)
{
    for (int i = 0; i < library.tamanho; i++)
    {
        if (library.busca(i)->dado->getNome().compare(name) == 0)
        {
            for (int j = 0; j < library.busca(i)->dado->getMusicas().tamanho; j++)
            {
                library.busca(i)->dado->getMusicas().remover(j);
                delete library.busca(i)->dado->getMusicas().busca(j);
            }
            library.remover(i);
            delete library.busca(i);
        }
    }
}

// Submenu de editar playlist

int inserir_musica_playlist(string name, string title, string author)
{
    bool existe = false;
    int op = 0;
    
    for (int i = 0; i < library.tamanho; i++)
    {
        if (library.busca(i)->dado->getNome().compare(name) != 0)
        {
            //Playlist não encontrada no sistema
            op = 1;
        }
    }

    //Encontrou a música correspondente
    for (int i = 0; i < louvores.tamanho && existe == false; i++)
    {
        if (louvores.busca(i)->dado->getTitulo().compare(title) == 0)
        {
            existe = true;
            break;
        }
    }

    if (existe == true)
    {
        for (int i = 0; i < library.tamanho; i++)
        {
            if (library.busca(i)->dado->getNome().compare(name) == 0)
            {
                //Música cadastrada com sucesso
                library.busca(i)->dado->adicionarMusica(title, author);
                op = 2;
            }
        }
    }
    else
    {
        //Música não cadastrada no sistema
        op = 3;
    }
    return op;
}

int remover_musica_playlist(string name, string title)
{
    bool existe = false;
    int op = 0;

    for (int i = 0; i < library.tamanho; i++)
    {
        if (library.busca(i)->dado->getNome().compare(name) != 0)
        {
            //Playlist não cadastrada no sistema
            op = 1;
        }
    }

    for (int i = 0; i < louvores.tamanho && existe == false; i++)
    {
        if (louvores.busca(i)->dado->getTitulo().compare(title) == 0)
        {
            //Encontrou a música correspondente
            existe = true;
            break;
        }
    }

    if (existe == true)
    {
        for (int i = 0; i < library.tamanho; i++)
        {
            if (library.busca(i)->dado->getNome().compare(name) == 0)
            {
                //Música removida com sucesso
                library.busca(i)->dado->removerMusica(title);
                op = 2;
            }
        }
    }
    else
    {
        //Música não cadastrada no sistema
        op = 3;
    }
    return op;
}

void listar_musicas_playlist(string name)
{
    for (int i = 0; i < library.tamanho; i++)
    {
        if (library.busca(i)->dado->getNome().compare(name) == 0)
        {
            for (int j = 0; j < library.busca(i)->dado->getMusicas().tamanho; j++)
            {
                cout << library.busca(i)->dado->getMusicas().busca(j)->dado->getTitulo() << endl;
            }
        }
    }
}

// Funções de impressões de menu

void menu()
{
    cout << "========================================" << endl;
    cout << "||     Bem-vindo ao Ex Nihilo!        ||" << endl;
    cout << "========================================" << endl;
    cout << "1 - Gerenciar Músicas" << endl;
    cout << "2 - Gerenciar Playlists" << endl;
    cout << "3 - Sair" << endl;
    cout << "========================================" << endl;
    cout << "Escolha uma opção: ";
}

void submenu1()
{
    cout << "========================================" << endl;
    cout << "1 - Inserir música" << endl;
    cout << "2 - Remover música" << endl;
    cout << "3 - Listar músicas" << endl;
    cout << "4 - Voltar ao menu principal" << endl;
    cout << "========================================" << endl;
    cout << "Escolha uma opção: ";
}

void submenu2()
{
    cout << "========================================" << endl;
    cout << "1 - Tocar playlist" << endl;
    cout << "2 - Criar playlist" << endl;
    cout << "3 - Listar playlists" << endl;
    cout << "4 - Remover playlist" << endl;
    cout << "5 - Tocar próxima música" << endl;
    cout << "6 - Editar playlist" << endl;
    cout << "7 - Voltar ao menu principal" << endl;
    cout << "========================================" << endl;
    cout << "Escolha uma opção: ";
}

void editar_playlist()
{
    cout << "========================================" << endl;
    cout << "1 - Inserir música" << endl;
    cout << "2 - Mover música" << endl;
    cout << "3 - Remover música" << endl;
    cout << "4 - Listar músicas da playlist" << endl;
    cout << "5 - Voltar ao menu principal" << endl;
    cout << "========================================" << endl;
    cout << "Escolha uma opção: ";
}

int main()
{
    int opcao = 0;
    int subopcao = 0;
    int subopcao2 = 0;
    Node<Playlist *> *atual;
    Node<Musica *> *proxima;

    while (opcao != 3)
    {
        menu();
        cin >> opcao;

        switch (opcao)
        {
        //Gerenciar Músicas
        case 1:
            submenu1();
            cin >> subopcao;

            //Adicionar música
            if (subopcao == 1)
            {
                string title, author;

                while ((getchar()) != '\n');
                cout << "Digite o nome da música: ";
                getline(cin, title);
                cout << "Agora digite o nome do artista: ";
                getline(cin, author);

                adicionar_musicas(title, author);
                cout << endl;
                cout << "Música adicionada!" << endl;
                cout << endl;
            }

            //Remover música
            else if (subopcao == 2)
            {
                string title;

                while ((getchar()) != '\n');
                cout << "Digite o nome da música: ";
                getline(cin, title);

                remover_musicas(title);
                cout << endl;
                cout << "Música removida!" << endl;
                cout << endl;
            }

            //Listar músicas
            else if (subopcao == 3)
            {
                cout << "========================================" << endl;
                cout << "Músicas cadastradas no sistema:" << endl;
                cout << endl;
                listar_musicas();
                cout << endl;
                cout << "========================================" << endl;
            }

            //Voltar ao menu principal
            else if (subopcao == 4)
            {
                continue;
            }

            break;

        //Gerenciar Playlists
        case 2:
            submenu2();
            cin >> subopcao;

            //Tocar playlist
            if (subopcao == 1)
            {
                string name;

                while ((getchar()) != '\n');
                cout << "Escutar qual playlist? ";
                getline(cin, name);

                atual = tocar_playlist(name);

                if (atual != nullptr)
                {
                    cout << endl;
                    cout << "Tocando " << atual->dado->getMusicas().busca(0)->dado->getTitulo() << "..." << endl;
                    cout << endl;
                }
                else
                {
                    cout << "Playlist não encontrada!" << endl;
                }
                continue;
            }

            //Criar playlist
            else if (subopcao == 2)
            {
                string name;

                while ((getchar()) != '\n');
                cout << "Digite o nome da playlist: ";
                getline(cin, name);

                adicionar_playlists(name);
                cout << endl;
                cout << "Playlist adicionada!" << endl;
                cout << endl;
            }

            //Listar playlists
            else if (subopcao == 3)
            {
                while ((getchar()) != '\n');
                cout << "========================================" << endl;
                cout << "Playlists cadastradas no sistema:" << endl;
                cout << endl;
                listar_playlists();
                cout << endl;
                cout << "========================================" << endl;
            }

            //Remover playlist
            else if (subopcao == 4)
            {
                string name;

                while ((getchar()) != '\n');
                cout << "Remover qual playlist? ";
                getline(cin, name);

                remover_playlists(name);
                cout << endl;
                cout << "Playlist removida!" << endl;
                cout << endl;
            }

            //Tocar próxima música
            else if (subopcao == 5)
            {
                *proxima = atual->dado->next_music();
                if (proxima == nullptr)
                {
                    cout << "Não há músicas a serem tocadas!" << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Tocando " << proxima->dado->getTitulo() << "..." << endl;
                    cout << endl;
                }
            }

            //Editar playlist
            else if (subopcao == 6)
            {
                editar_playlist();
                cin >> subopcao2;

                //Adicionar música na playlist
                if (subopcao2 == 1)
                {
                    string name, title, author;
                    int op = 0;

                    while ((getchar()) != '\n');
                    cout << "Adicionar música em qual playlist? ";
                    getline(cin, name);
                    cout << "Digite o título da música: ";
                    getline(cin, title);
                    cout << "Agora digite o nome do artista: ";
                    getline(cin, author);
                    
                    op = inserir_musica_playlist(name, title, author);

                    if (op == 1)
                    {
                        cout << endl;
                        cout << "Playlist não cadastrada no sistema!" << endl;
                        cout << endl;
                    }
                    else if(op == 2)
                    {
                        cout << endl;
                        cout << "Música adicionada com sucesso!" << endl;
                        cout << endl;
                    }
                    else if(op == 3)
                    {
                        cout << endl;
                        cout << "Música não cadastrada no sistema!" << endl;
                        cout << endl;
                    }
                }

                //Mover música
                else if (subopcao2 == 2)
                {

                    string title, author, origem, destino;
                    int op = 0;
                    int op2 = 0;

                    while ((getchar()) != '\n');
                    cout << "Nome da playlist origem: ";
                    getline(cin, origem);
                    cout << "Nome da playlist destino: ";
                    getline(cin, destino);
                    cout << "Digite o título da música: ";
                    getline(cin, title);
                    cout << "Digite o artista da música: ";
                    getline(cin, author);

                    op = remover_musica_playlist(origem, title);
                    op2 = inserir_musica_playlist(destino, title, author);

                    if (op == 1 && op2 == 1)
                    {
                        cout << endl;
                        cout << "Playlist não cadastrada no sistema!" << endl;
                        cout << endl;
                    }
                    else if(op == 2 && op2 == 2)
                    {
                        cout << endl;
                        cout << "Música movida com sucesso!" << endl;
                        cout << endl;
                    }
                    else if(op == 3 && op2 == 3)
                    {
                        cout << endl;
                        cout << "Música não cadastrada no sistema!" << endl;
                        cout << endl;
                    }
                }

                //Remover música da playlist
                else if (subopcao2 == 3)
                {
                    string name, title;
                    int op = 0;

                    while ((getchar()) != '\n');
                    cout << "Remover música de qual playlist? ";
                    getline(cin, name);
                    cout << "Digite o título da música: ";
                    getline(cin, title);

                    op = remover_musica_playlist(name, title);

                    if (op == 1)
                    {
                        cout << endl;
                        cout << "Playlist não cadastrada no sistema!" << endl;
                        cout << endl;
                    }
                    else if(op == 2)
                    {
                        cout << endl;
                        cout << "Música removida com sucesso!" << endl;
                        cout << endl;
                    }
                    else if(op == 3)
                    {
                        cout << endl;
                        cout << "Música não cadastrada no sistema!" << endl;
                        cout << endl;
                    }
                }

                //Listar músicas da playlist
                else if (subopcao2 == 4)
                {
                    string name;

                    while ((getchar()) != '\n');
                    cout << "Listar músicas de qual playlist? ";
                    getline(cin, name);

                    cout << "========================================" << endl;
                    cout << "Músicas desta playlist:" << endl;
                    cout << endl;
                    listar_musicas_playlist(name);
                    cout << endl;
                    cout << "========================================" << endl;
                }

                //Voltar
                else if (subopcao2 == 5){
                    continue;
                }
            }
            break;

        //Sair
        case 3:
            cout << "========================================" << endl;
            cout << "||   Obrigado por usar o Ex Nihilo!   ||" << endl;
            cout << "========================================" << endl;
            break;

        default:
            cout << "========================================" << endl;
            cout << endl;
            cout << "Opção inválida, tente novamente." << endl;
            cout << endl;
            break;
        }
    }
}