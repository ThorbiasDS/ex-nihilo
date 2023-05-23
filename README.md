# Ex Nihilo

• Autores: Hosana Iasmin Castro dos Santos e Tobias Daniel Siqueira 

• Como compilar e rodar: Para compilar o código é necessário usar o CMake, criamos um arquivo na raiz do projeto nomeado CMakeLists.txt, onde configuramos  a versão do cmake, nome do projeto, arquivos.cpp e localização dos includes. Depois execute o comando cmake para criar os arquivos auxiliares. Em seguida execute make para compilar e depois chama o executável program.

## (Roteiro) Exemplos de entrada: 
   
O programa irá apresentar um menu, composto de outros submenus que irão gerenciar as músicas e as playlists.
Por exemplo:
	
#### Inserir músicas:

 	Música: Yellow
 	Artista: Coldplay

#### Remover músicas: 
     
	Música: Yellow

#### Adicionar playlist:
    
 	Nome: Playlist1
  
#### Remover playlist:
  
	Nome: Playlist1

#### Tocar música:

	Nome da Playlist: Playlist1

#### Adicionar música em playlist:

	Nome da Playlist: Playlist1
	Nome da Musica: Yellow
	Nome do Artista: Coldplay

#### Mover música:

	Nome da Playlist de Origem: Playlist1
	Nome da Playlist de Destino: Playlist2
	Nome da música: Yellow
	Nome do Artista: Coldplay

#### Remover música:

	Nome da Playlist: Playlist1
	Nome da Musica: Yellow

Limitações: Voltar ao menu imediatamente anterior. <br>
Dificuldades: Passar para a próxima  música.
