/** Descrição do arquivo.
/*
* @author Hosana Iasmin & Tobias Daniel
* @since 01/05/2023
* @version 2.0
*/

#include "Musica.h"
#include "Playlist.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * \brief Listas globais de músicas e playlists
 */

Lista<Musica *> louvores;
Lista<Playlist *> library;

/**
 * \brief Funções pertencentes à opção Gerenciar Músicas
 *
 * Essas funções servem para adicionar, remover e listar as músicas do sistema.
 * */

/// \param titulo Título da música
/// \param artista Nome do autor da música
void adicionar_musicas(string title, string author)
{
    Musica *louvor = new Musica(title, author);
    louvores.inserir(louvor);
}

/// \param titulo Título da música
/// \return Retorna verdadeiro se as músicas foram removidas com sucesso da playlist e do sistema
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

/**
 * \brief Funções referentes à opção Gerenciar Playlists
 *
 * Essas funções fazem a adição, remoção e listagem das playlists do sistema.
 * Além disso, temos as funções para tocar uma playlist e tocar a próxima música.
 * Por fim, há opção de entrar em uma submenu para a edição de playlists específicas
 * */

/// \param nome Nome da playlist a ser tocada
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

/// \param nome Nome da playlist a ser adicionada
void adicionar_playlists(string name)
{
    Playlist *play = new Playlist(name);
    library.inserir(play);
}

/// \param plays Objeto playlist a ser adicionado
void adicionar_playlists(Playlist &plays)
{
    library.inserir(&plays);
}

void listar_playlists()
{
    for (int i = 0; i < library.tamanho; i++)
    {
        cout << library.busca(i)->dado->getNome() << endl;
    }
}

/// \param nome Nome da playlist a ser removida
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

/**
 * \brief Funções referentes ao submenu de edição de playlists
 *
 * Aqui temos as opções de inserir música em uma determinada playlist, remover e listar
 */

/// @param name Nome da playlist
/// @param title Título da música
/// @param author Autor da músca
/// @return O retorno 1 significa que a playlist não foi encontrada, o 2 significa que a música foi cadastrada com sucesso e o 3 que a música não está cadastrada no sistema
int inserir_musica_playlist(string name, string title, string author)
{
    bool existe = false;
    int op = 0;

    for (int i = 0; i < library.tamanho; i++)
    {
        if (library.busca(i)->dado->getNome().compare(name) != 0)
        {
            // Playlist não encontrada no sistema
            op = 1;
        }
    }

    // Encontrou a música correspondente
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
                // Música cadastrada com sucesso
                library.busca(i)->dado->adicionarMusica(title, author);
                op = 2;
            }
        }
    }
    else
    {
        // Música não cadastrada no sistema
        op = 3;
    }
    return op;
}

/// @param name Nome da playlist
/// @param title Título da música
/// @param author Autor da músca
/// @return O retorno 1 significa que a playlist não foi encontrada, o 2 significa que a música foi cadastrada com sucesso e o 3 que a música não está cadastrada no sistema
int remover_musica_playlist(string name, string title)
{
    bool existe = false;
    int op = 0;

    for (int i = 0; i < library.tamanho; i++)
    {
        if (library.busca(i)->dado->getNome().compare(name) != 0)
        {
            // Playlist não cadastrada no sistema
            op = 1;
        }
    }

    for (int i = 0; i < louvores.tamanho && existe == false; i++)
    {
        if (louvores.busca(i)->dado->getTitulo().compare(title) == 0)
        {
            // Encontrou a música correspondente
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
                // Música removida com sucesso
                library.busca(i)->dado->removerMusica(title);
                op = 2;
            }
        }
    }
    else
    {
        // Música não cadastrada no sistema
        op = 3;
    }
    return op;
}

/// @param name Nome da playlist
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

// Funções referente à manipulação de arquivos

Lista<string> split(string &texto, char separador)
{
    int inicio = 0;
    int fim = 0;

    Lista<string> palavras;
    string info;

    fim = texto.find(separador);

    while (fim != string::npos)
    {
        info = texto.substr(inicio, fim);
        palavras.inserir(info);
        texto.erase(inicio, fim - inicio);
        fim = texto.find(separador);
    }

    return palavras;
}

/**
 * \brief Funções para as impressões dos menus
 *
 * Essas funções são chamados no main para apresentar ao usuário as opções que ele tem disponível para usar no sistema.
 */

/// \brief Menu principal
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

/// \brief Menu de gerenciar músicas
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

/// \brief Menu de gerenciar playlists

void submenu2()
{
    cout << "========================================" << endl;
    cout << "1 - Criar playlist" << endl;
    cout << "2 - Listar playlists" << endl;
    cout << "3 - Editar playlist" << endl;
    cout << "4 - Remover playlist" << endl;
    cout << "5 - Tocar playlist" << endl;
    cout << "6 - Tocar próxima música" << endl;
    cout << "7 - Unir playlists" << endl;
    cout << "8 - Subtrair playlists" << endl;
    cout << "9 - Voltar ao menu principal" << endl;
    cout << "========================================" << endl;
    cout << "Escolha uma opção: ";
}

/// \brief Menu de editar playlists
void editar_playlist()
{
    cout << "========================================" << endl;
    cout << "1 - Inserir música" << endl;
    cout << "2 - Mover música" << endl;
    cout << "3 - Remover música" << endl;
    cout << "4 - Listar músicas da playlist" << endl;
    cout << "5 - Extair última música" << endl;
    cout << "6 - Voltar ao menu principal" << endl;
    cout << "========================================" << endl;
    cout << "Escolha uma opção: ";
}

int main(int argc, char *argv[])
{

    /// @brief Variáveis para a manipulação de arquivos
    ifstream file;
    ofstream file_exit;
    Lista<string> plays;
    Lista<string> descricao;
    Lista<string> criadores;
    string linha;

    file.open("infos.txt", ios::in);

    if (!file) {
        cout << "Impossivel abrir arquivo de entrada!" << endl;
        abort();
    }

    while(!file.eof()) {
        getline(file, linha);
        plays = split(linha, ';');
        descricao = split(linha, ':');
        criadores = split(linha, ',');
    }

    for (int i = 0; i < plays.tamanho; i++)
    {
        adicionar_playlists(plays.busca(i)->dado);
    }
    
    for (int i = 0; i < descricao.tamanho; i++)
    {
        adicionar_musicas(descricao.busca(i)->dado, criadores.busca(i)->dado);
    }

    file.close();

    /// @brief Variáveis para a escolha das opções nos menus
    int opcao = 0;
    int subopcao = 0;
    int subopcao2 = 0;

    /// @brief Variáveis usadas para armazenar a playlist que está sendo tocada e para guardar a próxima música a ser tocada
    Node<Playlist *> *atual;
    Node<Musica *> *proxima;

    /// @brief Enquanto a opção for diferente de 3 chama o menu, quando for igual encerra o programa
    while (opcao != 3)
    {
        menu();
        cin >> opcao;

        switch (opcao)
        {
        /// @brief Gerenciar músicas Músicas
        case 1:
            submenu1();
            cin >> subopcao;

            /// @brief Adicionar música
            if (subopcao == 1)
            {
                string title, author;

                while ((getchar()) != '\n')
                    ;
                cout << "Digite o nome da música: ";
                getline(cin, title);
                cout << "Agora digite o nome do artista: ";
                getline(cin, author);

                adicionar_musicas(title, author);
                cout << endl;
                cout << "Música adicionada!" << endl;
                cout << endl;
            }

            /// @brief Remover música
            else if (subopcao == 2)
            {
                string title;

                while ((getchar()) != '\n')
                    ;
                cout << "Digite o nome da música: ";
                getline(cin, title);

                remover_musicas(title);
                cout << endl;
                cout << "Música removida!" << endl;
                cout << endl;
            }

            /// @brief Listar músicas
            else if (subopcao == 3)
            {
                cout << "========================================" << endl;
                cout << "Músicas cadastradas no sistema:" << endl;
                cout << endl;
                listar_musicas();
                cout << endl;
                cout << "========================================" << endl;
            }

            /// @brief Voltar ao menu principal
            else if (subopcao == 4)
            {
                continue;
            }

            break;

        /// @brief Gerenciar Playlists
        case 2:
            submenu2();
            cin >> subopcao;

            /// @brief Criar playlist
            if (subopcao == 1)
            {
                string name;

                while ((getchar()) != '\n')
                    ;
                cout << "Digite o nome da playlist: ";
                getline(cin, name);

                adicionar_playlists(name);
                cout << endl;
                cout << "Playlist adicionada!" << endl;
                cout << endl;
            }

            /// @brief Listar playlists
            else if (subopcao == 2)
            {
                while ((getchar()) != '\n');
                cout << "========================================" << endl;
                cout << "Playlists cadastradas no sistema:" << endl;
                cout << endl;
                listar_playlists();
                cout << endl;
                cout << "========================================" << endl;
            }

            /// @brief Editar playlist
            else if (subopcao == 3)
            {
                editar_playlist();
                cin >> subopcao2;

                // Adicionar música na playlist
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
                    else if (op == 2)
                    {
                        cout << endl;
                        cout << "Música adicionada com sucesso!" << endl;
                        cout << endl;
                    }
                    else if (op == 3)
                    {
                        cout << endl;
                        cout << "Música não cadastrada no sistema!" << endl;
                        cout << endl;
                    }
                }

                // Mover música
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
                    else if (op == 2 && op2 == 2)
                    {
                        cout << endl;
                        cout << "Música movida com sucesso!" << endl;
                        cout << endl;
                    }
                    else if (op == 3 && op2 == 3)
                    {
                        cout << endl;
                        cout << "Música não cadastrada no sistema!" << endl;
                        cout << endl;
                    }
                }

                // Remover música da playlist
                else if (subopcao2 == 3)
                {
                    string name, title;
                    int op = 0;

                    while ((getchar()) != '\n')
                        ;
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
                    else if (op == 2)
                    {
                        cout << endl;
                        cout << "Música removida com sucesso!" << endl;
                        cout << endl;
                    }
                    else if (op == 3)
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

                    while ((getchar()) != '\n')
                        ;
                    cout << "Listar músicas de qual playlist? ";
                    getline(cin, name);

                    cout << "========================================" << endl;
                    cout << "Músicas desta playlist:" << endl;
                    cout << endl;
                    listar_musicas_playlist(name);
                    cout << endl;
                    cout << "========================================" << endl;
                }

                //Extrair última música
                else if (subopcao2 == 5)
                {
                    
                }

                //Voltar ao menu principal
                else if (subopcao2 == 6)
                {

                }
            }

            /// @brief Remover playlist
            else if (subopcao == 4)
            {
                string name;

                while ((getchar()) != '\n')
                    ;
                cout << "Remover qual playlist? ";
                getline(cin, name);

                remover_playlists(name);
                cout << endl;
                cout << "Playlist removida!" << endl;
                cout << endl;
            }

            /// @brief Tocar playlist
            else if (subopcao == 5)
            {
                string name;

                while ((getchar()) != '\n')
                    ;
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

            /// @brief Tocar próxima música
            else if (subopcao == 6)
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

            /// @brief Unir playlists
            else if (subopcao == 7)
            {

            }

            /// @brief Subtrair playlists
            else if (subopcao == 8)
            {

            }

            /// @brief Voltar ao menu principal
            else if (subopcao == 9)
            {
                continue;
            }
            break;

        /// @brief Encerrar o programa
        case 3:
            cout << "========================================" << endl;
            cout << "||   Obrigado por usar o Ex Nihilo!   ||" << endl;
            cout << "========================================" << endl;
            break;

        /// @brief Se o usuário digitar um valor diferente de 1, 2 ou 3, o programa mostra que essa opção é inválida
        default:
            cout << "========================================" << endl;
            cout << endl;
            cout << "Opção inválida, tente novamente." << endl;
            cout << endl;
            break;
        }
    }

    file.open("exit.txt", ios::out);

    if(!file)
    {
        cout << "Impossivel abrir arquivo de saída!" << endl;
        abort();
    }
}