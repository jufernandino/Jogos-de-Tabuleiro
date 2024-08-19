# Jogos de Tabuleiro

## Descrição do projeto
O projeto Jogos de Tabuleiro é uma aplicação desenvolvida como trabalho final da disciplina de Programação e Desenvolvimento de Software II (PDS II) do curso de Sistemas de Informação na UFMG. Este projeto implementa um sistema para jogar diferentes jogos, proporcionando funcionalidades cadastro de jogadores, exclusão de jogadores, estatísica dos jogadores e a listagem dos jogadores. Os jogos disponibilizados para serem jogados são:
- Lig4
- Reversi
- Tic Tac Toe (jogo extra)
- Jogo da Memória (jogo extra)
- Campo Minado (jogo extra)

## Equipe
Trabalho feito colaborativamente pelos membros:
- Bárbara Diniz
- Isadora Horta
- Júlia Vasconcelos
- Marcele Louise
- Sarah Menks

## Tecnologias Utilizadas
- `Linguagem:` C++
- `Compilação:` Makefile  
- `Documentação:` Doxygen e README  
- `Testes:` Biblioteca doctest  
- `Controle de Versão:` Git e GitHub
  
## Funcionalidades extras implementadas
- Tic Tac Toe 
- Jogo da Memória 
- Campo Minado 
- Exibir as regras dos jogos 
- Exibir o ranking específico para cada jogo

## Estrutura do Projeto
O projeto foi organizado em diferentes classes, cada uma com suas responsabilidades:

1. **Jogadores:**
   -  Implementa métodos relacionados aos jogadores (cadastrar, remover, listar) com persistência de dados em arquivo
   - Além disso, mostra as estatísticas (vitórias e derrotas) e ordena jogadores pelo nome ou apelido.
   - Métodos implementados:
     - pesquisaJogador(string Apelido)
     - logIn(string Apelido, vector<Jogadores> &jogadoresVector)
     - reescreveArquivo(vector<Jogadores> &jogadoresVector)
     - removeJogador(vector<Jogadores> &jogadoresVector, string &Apelido)
     - atualizaEstatisticas(char jogoEscolhido, vector<Jogadores> &jogadoresVector)
     - mostrarRanking(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector)
     - mostrarEstatisticas(vector<Jogadores> &jogadoresVector, const string &ordenacao)
     - carregarJogadores(vector<Jogadores> &jogadoresVector)
     - cadastrarJogadores(string apelido, string nome, Jogadores &Jogador, vector<Jogadores> &jogadoresVector)
     - ordenacaoApelido(vector<Jogadores> &jogadoresVector)
     - ordenacaoNome(vector<Jogadores> &jogadoresVector)
   - Erros: `ERRO: não foi possível abrir o arquivo Jogadores.txt`
     
     
2. **Tabuleiro:**
   - Contém os métodos e funcionalidades básicas para todos os jogos (classe pai).
   - Essa classe gerencia o tabuleiro, além de mostrar as regras, validar jogadas e fazer a conferência do ganhador.
   - Métodos implementados:
     - criaTabuleiro ( )
     - void imprimirTabuleiro ( )
     - validaJogada (int x, int y, char z) 
     - liberaMemoria ( )
     - confereGanhador ( ) = 0;
     - mostrarRegras (const char &jogoEscolhido)
   - Erros: `ERRO: não foi possível abrir o arquivo Regras.txt`

     
3. **Classes Herdeiras de Tabuleiro:**
   - *As classes herdeiras são: Lig4, Reversi, TicTacToe, CampoMinado e Memória. Elas impelementam a lógica de cada jogo, respectivamente.*

     
   3.1 **Lig4:**
      - Classe herdeira de classe base "Tabuleiro" que implementa a lógica específica do jogo Lig4.
      - Métodos que sobrescrevem os da classe "Tabuleiro":
        - validaJogada(int x, int y, char z)
        - confereGanhador ()

          
   3.2 **Reversi:**
      - Classe herdeira de classe base "Tabuleiro" que implementa a lógica específica do jogo Reversi.
      - Métodos que sobrescrevem os da classe "Tabuleiro":
        - validaJogada(int x, int y, char z)
        - confereGanhador ()
      - Métodos implementados:
        - inicializarJogo()
        - ehJogadaValida(int x, int y, char jogadorDaVez)
        - existeMovimentoPossivel(char jogadorDaVez)
        - mostrarLocaisJogada(char jogador)
        - verificarFimDeJogo()
        - inverterPecas(int x, int y, char jogadorDaVez)
      - Atributo privado:
        - char jogadorAtual

          
   3.3 **Tic Tac Toe:**
      - Classe herdeira de classe base "Tabuleiro" que implementa a lógica específica do jogo Tic Tac Toe (funcionalidade extra).
      - Método que sobrescreve o da classe "Tabuleiro":
        - confereGanhador ()

          
   3.4 **Campo Minado:**
      - Classe herdeira de classe base "Tabuleiro" que implementa a lógica específica do jogo Campo Minado (funcionalidade extra).
      - Método que sobrescreve o da classe "Tabuleiro":
        - confereGanhador ()
      - Métodos implementados:
        - iniciaTabuleiro()
        - minasAdj(int linha, int coluna)
        - revelaCelula(int linha, int coluna)
        - validaJogadaCampoMinado(int linha, int coluna)
        - escolheuBomba(int linha, int coluna)
        - jogarCampoMinado()
      - Atributos privados:
        - int bombas
        - int posicao_minas`[2][10]`

          
   3.5 **Memoria:**
      - Classe herdeira de classe base "Tabuleiro" que implementa a lógica específica do jogo da Memória (funcionalidade extra).
      - Método que sobrescreve o da classe "Tabuleiro":
        - confereGanhador ()
      - Métodos implementados:
        - ehJogadaValida(int x, int y, int x2, int y2, char jogadorDaVez)
        - validaJogada(int x, int y, int x2, int y2, char jogadorDaVez)
        - formamPares(int x, int y, int x2, int y2, char jogadorDaVez)
        - validaPares(int x, int y, int x2, int y2, char jogadorDaVez)
        - verificarFimDeJogo()
        - inicializaTabuleiroSimbolos()
      - Atributos privados:
        - int pontosJogador1
        - int pontosJogador2
        - int jogadorAtual
        - char aux`[4][4]`

    
4. **Execução de Partidas:**
   -  Na `main` existem as mecânicas para executar partidas entre jogadores, escolher o jogo, verificação de jogadas e atualização de estatísticas, valendo-se dos métodos das classes.

## Inputs
Os inputs foram os estabelecidos pelo enunciado, com as entradas e as eventuais mensagens de erro:

### Cadastro de Jogadores
- **Cadastrar Jogador**: `CJ <Apelido> <Nome>`
  - (obs. Considere que `<Apelido>` é composto por uma única palavra)
  - Sucesso: `Jogador <Apelido> cadastrado com sucesso`
  - Erros: `ERRO: entrada inválida`, `ERRO: jogador repetido`  

- **Remover Jogador**: `RJ <Apelido>`
  - Sucesso: `Jogador <Apelido> removido com sucesso`
  - Erro: `ERRO: entrada inválida`, `ERRO: jogador não encontrado` 

- **Listar Jogadores**:  `LJ A|N` `<Apelido> <Nome>`
  - Sucesso: lista de todos os jogadores ordenados por Apelido ou Nome, seguido pelo número de vitórias e derrotas em cada jogo
  - *Exemplo:*
    - `<Apelido>` `<Nome>`
    - REVERSI - V: <#vitorias> D: <#derrotas>
    - LIG4 - V: <#vitorias> D: <#derrotas>
    - TIC TAC TOE - V: <#vitorias> D: <#derrotas>
    - CAMPO MINADO - V: <#vitorias> D: <#derrotas>
    - MEMORIA - V: <#vitorias> D: <#derrotas>
  - Erro: `ERRO: entrada inválida`, `ERRO: comando inválido; escolha ordenar por (A)pelido ou (N)ome!`

### Execução de Partidas
- **Executar Partida**: `EP <Jogo: (R|L|T|C|M)> <Apelido Jogador 1> <Apelido Jogador 2>`
   - *Exemplo:* `EP R Ju Babi` (executa o jogo Reversi com jogadora Ju e jogadora Babi)
   - Erros:  `ERRO: entrada inválida`, `ERRO: jogo não encontrado`, `ERRO: São necessários dois jogadores para jogar este jogo`, `ERRO: primeiro jogador não encontrado` , `ERRO: segundo jogador não encontrado`, `Este jogo só possui um jogador`
   - Sucesso: `<Apelido Jogador 1> fez log in!`, `<Apelido Jogador 2> fez log in!` `<Jogo> foi escolhido!`
   - Sucesso: `J - JOGAR ` `L - Ler regras do jogo`
      - **Jogar:** `<J>`
      - **Regras:** `<L>` (funcionalidade extra)
      - **Erros:** `ERRO: Regras não encontradas para o jogo selecionado.`
   - OBS: *( R= Reversi | L=Lig4 | T=TicTacToe | C=CampoMinado | M=Memória )* 

- **Finalizar Sistema**: `FS`

## Inputs durante os Jogos
- **Jogada no Lig 4**: `<Coluna>`
  - Exemplo: `<1>` 
  - Erros: `ERRO: formato incorreto`, `Essa jogada é inválida! Passa a vez!`, `Não existem mais posições disponiveis nessa coluna! Perde a vez!`
    
- **Jogada no Reversi**: `<Linha>` `<Coluna>`
  - Exemplo: `<0>` `<2>` 
  - Erros: `ERRO: formato incorreto`, `ERRO: jogada inválida`

- **Jogada no TicTacToe**: `<Linha>` `<Coluna>`
  - Exemplo: `<0>` `<2>` 
  - Erros: `ERRO: formato incorreto`, `Essa jogada é inválida! Passa a vez!`
  - 
- **Jogada no Campo Minado**: `<Linha>` `<Coluna>`
  - Exemplo: `<0>` `<2>` 
  - Erros: `ERRO: jogada inválida!`,  `ERRO: formato incorreto`
    
- **Jogada no Jogo da Memória**: `<Linha1>` `<Coluna1>` `<Linha2>` `<Coluna2>`
  - Exemplo: `<0>` `<1>` `<0>` `<2>` 
  - Erros: `ERRO: formato incorreto`, `ERRO: jogada inválida`

(Ao final de cada partida o jogador tem a opção de ver o ranking do jogo ou voltar ao menu)
- **Visualizar ranking**: `VR` (funcionalidade extra)
- **Jogar novamente**: `JN`
  - Erros: `ERRO: entrada inválida; escolha (J)ogar (N)ovamente ou (V)er (R)anking!`
    
## Documentação
O projeto conta com diversas formas de documentação: esse READ-ME e os arquivos gerados pelo Doxygen (html e PDF). Para acessar o html basta ir na pasta `html` dentro do repositório, clicar no arquivo `index.html` com o `<Botão Direito do Mouse>` e selecionar a opção `Open With Live Server`

## Dificuldades encontradas 
Durante o desenvolvimento deste projeto, a equipe enfrentou alguns desafios:

- Uso do Git e Github:
  A utilização dessas ferramentas apresentou-se como um desafio para a equipe. No decorrer do projeto, tivemos dificuldades ao lidar com conflitos de merge, em entender o fluxo de trabalho nas branches e na utilização das funcionalidades para manter o código organizado.

- Uso de Makefile:
  O processo de compilação dos arquivos com o Makefile apresentou-se com um desafio na reta final. Algumas das dificuldades enfrentadas foram: erro com o arquivo executável, conjutamente com um erro relacionado ao tipo binário gerado na compilação (Exemplo: Relocation against symbol _zvcampominado can not be used when making a PIE object). Para lidar com o problema utilizamos o comando `make clean` e depois realizamos o processo de compilação novamente com `make`. Além disso acrescentamos no arquivo Makefile a linha: `CFLAGS=-std=c++11 -Wall -fPIC`, caso o problema estivesse relacionado a um trecho que envolva código compartilhado ou parte de uma biblioteca.

- Realização dos Testes:
  Compreender e executar os testes também se mostrou um processo desafiador. Houve dificuldades em entender a estrutura e como conseguir integrá-los no nosso processo de desenvolvimento.

- Salvar informações no arquivo Jogadores.txt:
  No processo de manipulação do arquivo, o grupo apresentou dificuldades para tratar um erro específico ao cadastrar usuário, que gerava uma linha em branco no arquivo. A presença desta linha acarretava o não funcionamento do executável, exibindo o seguinte errro: `terminate called after throwing an instance of 'std::invalid_argument' what(): stoi Aborted`   

Essas dificuldades, embora desafiadoras, contribuíram para um maior aprendizado por parte de toda a equipe. 

## Aprendizados com o projeto
Este projeto foi uma oportunidade valiosa para aprimorar nossas habilidades em programação, colaboração e gerenciamento de projetos. Os principais aprendizados incluem:

- Programação orientada a objetos em C++.
- Colaboração efetiva em um projeto conjunto.
- Comunicação.
- Uso avançado de Git e GitHub para controle de versão.
- Práticas de programação defensiva e tratamento de exceções.
- Criação e manutenção de Makefile.
- Geração de documentação utilizando Doxygen.
- Criação de testes.

## Github dos contribuintes

[Github Bárbara](https://github.com/barbaradinizabreu)  
[Github Isadora](https://github.com/isadorahorta)  
[Github Júlia](https://github.com/jufernandino)  
[Github Marcele](https://github.com/MarceleLouiseSAra)  
[Github Sarah](https://github.com/SarahMenks)
