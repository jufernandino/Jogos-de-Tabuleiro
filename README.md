# Jogos de Tabuleiro

## Descrição do projeto
O projeto Jogos de Tabuleiro é uma aplicação desenvolvida como trabalho final da disciplina de Programação e Desenvolvimento de Software II (PDS II) do curso de Sistemas de Informação na UFMG. Este projeto implementa um sistema para jogar diferentes jogos, proporcionando funcionalidades cadastro de jogadores, exclusão de jogadores, estatísica dos jogadores e a listagem dos jogadores. Os jogos disponibilizados para serem jogados são:
- Campo Minado
- Reversi
- Tic Tac Toe
- Jogo da Memória
- Lig4

## Equipe
- Bárbara Diniz
- Isadora Horta
- Júlia Vasconcelos
- Marcele Louise
- Sarah Menks

## Tecnologias Utilizadas
- `Linguagem:` C++
- `Compilação:` Makefile  
- `Documentação:` Doxygen  
- `Testes:` Biblioteca doctest  
- `Controle de Versão:` Git e GitHub

## Estrutura do Projeto
O projeto foi organizado em diferentes classes, cada uma com suas responsabilidades:

1. **Jogadores:**
   -  Implementa métodos relacionados aos jogadores (cadastrar, remover, listar) com persistência de dados em arquivo
   - Além disso, mostra as estatísticas (vitórias e derrotas) e ordena jogadores pelo nome ou apelido.
   - Métodos implementados:
     - pesquisaJogador ( `<Apelido>`)
     - logar ( `<Apelido>`, `vector<Jogadores> &jogadoresVector` )
     - reescreveArquivo ( `vector<Jogadores> &jogadoresVector` )
     - removeJogador ( `vector<Jogadores> &jogadoresVector`, `string &Apelido` )
     - atualizaEstatisticas ( `<jogoEscolhido>`, `vector<Jogadores> &jogadoresVector` )
     - mostrarRanking ( `char &jogoEscolhido`, `vector<Jogadores> jogadoresVector` )
     - mostrarEstatisticas ( `vector<Jogadores> jogadoresVector`, `const string &ordenacao` )
     - carregarJogadores ( `vector<Jogadores> &jogadoresVector` )
     - cadastrarJogadores ( `<apelido>`, `<nome>`, `Jogadores &Jogador`, `vector<Jogadores> &jogadoresVector` )
     - ordenacaoApelido ( `vector<Jogadores> &jogadoresVector` )
     - ordenacaoNome ( `vector<Jogadores> &jogadoresVector` )
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
   - *As classes herdeiras são: CampoMinado, Lig4, Reversi, TicTacToe e Memória. Elas impelementam a lógica de cada jogo, respectivamente.*

    
4. **Execução de Partidas:**
   -  Na `main` existem as mecânicas para executar partidas entre jogadores, escolher o jogo, verificação de jogadas e atualização de estatísticas, valendo-se dos métodos das classes.

## Inputs
Os inputs foram os estabelecidos pelo enunciado, com as entradas e as eventuais mensagens de erro:

### Cadastro de Jogadores
- **Cadastrar Jogador**: `CJ <Apelido> <Nome>`
  - (obs. Considere que `<Apelido>` é composto por uma única palavra)
  - Sucesso: `Jogador <Apelido> cadastrado com sucesso`
  - Erros: `ERRO: dados incorretos`, `ERRO: jogador repetido`  

- **Remover Jogador**: `RJ <Apelido>`
  - Sucesso: `Jogador <Apelido> removido com sucesso`
  - Erro: `ERRO: jogador inexistente` 

- **Listar Jogadores**:  `LJ A|N` `<Apelido> <Nome>`
  - Sucesso: lista de todos os jogadores ordenados por Apelido ou Nome, seguido pelo número de vitórias e derrotas em cada jogo
  - *Exemplo:*
    - `<Apelido>` `<Nome>`
    - REVERSI - V: <#vitorias> D: <#derrotas>
    - LIG4 - V: <#vitorias> D: <#derrotas>
    - TIC TAC TOE - V: <#vitorias> D: <#derrotas>
    - CAMPO MINADO - V: <#vitorias> D: <#derrotas>
    - MEMORIA - V: <#vitorias> D: <#derrotas>  

### Execução de Partidas
- **Executar Partida**: `EP <Jogo: (R|L|T|C|M)> <Apelido Jogador 1> <Apelido Jogador 2>`
   - *Exemplo:* `EP R Ju Babi` (executa o jogo Reversi com jogadora Ju e jogadora Babi)
   - Erros: `ERRO: comando inválido`, `ERRO: dados incorretos` , `ERRO: jogador inexistente`
   - Sucesso: `J - JOGAR ` `L - Ler regras do jogo`
      - **Jogar:** `<J>`
      - **Regras:** `<L>`
      - **Erros:** `ERRO: Regras não encontradas para o jogo selecionado.`
   - OBS: *( R= Reversi | L=Lig4 | T=TicTacToe | C=CampoMinado | M=Memória )* 

- **Finalizar Sistema**: `FS`

## Inputs durante os Jogos
- **Jogada no Reversi**: `<Linha>` `<Coluna>`
  - Exemplo: `<0>` `<2>` 
  - Erros: `ERRO: formato incorreto`, `ERRO: jogada inválida`

- **Jogada no Lig 4**: `<Coluna>`
  - Exemplo: `<1>` 
  - Erros: `ERRO: formato incorreto`, `Essa jogada é inválida! Passa a vez!`

- **Jogada no TicTacToe**: `<Linha>` `<Coluna>`
  - Exemplo: `<0>` `<2>` 
  - Erros: `ERRO: formato incorreto`, `Essa jogada é inválida! Passa a vez!`
  - 
- **Jogada no Campo Minado**: `<Linha>` `<Coluna>`
  - Exemplo: `<0>` `<2>` 
  - Erros: `ERRO: formato incorreto`, `ERRO: jogada inválida!`
    
- **Jogada no Jogo da Memória**: `<Linha1>` `<Coluna1>` `<Linha2>` `<Coluna2>`
  - Exemplo: `<0>` `<1>` `<0>` `<2>` 
  - Erros: `ERRO: formato incorreto`, `ERRO: jogada inválida`

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
