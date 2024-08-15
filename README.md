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
2. **Tabuleiro:**
   - Contém os métodos e funcionalidades básicas para todos os jogos. Essa classe gerencia o tabuleiro, além de mostrar as regras, validar jogadas e fazer a conferência do ganhador.
   - *As classes herdeiras: CampoMinado, Lig4, Reversi, TicTacToe e Memória impelementam a lógica de cada jogo, respectivamente.*
3. **Execução de Partidas:**
   -  Na main existem as mecânicas para executar partidas entre jogadores, escolher o jogo, verificação de jogadas e atualização de estatísticas.

## Inputs
Os inputs foram os estabelecidos pelo enunciado, com as entradas e as eventuais mensagens de erro:
### Cadastro de Jogadores
- **Cadastrar Jogador**: `CJ <Apelido> <Nome>`
  - (obs. Considere que `<Apelido>` é composto por uma única palavra)
  - Exemplo: `Jogador <Apelido> cadastrado com sucesso`
  - Erros: `ERRO: dados incorretos`, `ERRO: jogador repetido`  

- **Remover Jogador**: `RJ <Apelido>`
  - Exemplo: `Jogador <Apelido> removido com sucesso`
  - Erro: `ERRO: jogador inexistente`

- **Listar Jogadores**:  `LJ A|N` `<Apelido> <Nome>`
  - ( Lista todos os jogadores ordenados por Apelido ou Nome, seguido pelo número de vitórias e derrotas em cada jogo)
  - REVERSI - V: <#vitorias> D: <#derrotas>
  - LIG4 - V: <#vitorias> D: <#derrotas>
  - TIC TAC TOE - V: <#vitorias> D: <#derrotas>
  - MEMORIA - V: <#vitorias> D: <#derrotas>  

### Execução de Partidas
- **Executar Partida**: `EP <Jogo: (R|L|T|M)> <Apelido Jogador 1> <Apelido Jogador 2>`  
   - Erros: `ERRO: dados incorretos` , `ERRO: jogador inexistente`

- **Finalizar Sistema**: `FS`
  
### Durante os Jogos
- **Jogada no Reversi**: `<Linha> <Coluna>`
  - Erros: `ERRO: formato incorreto`, `ERRO: jogada inválida`

- **Jogada no Lig 4**: `<Coluna>`
  - Erros: `ERRO: formato incorreto`, `Essa jogada é inválida! Passa a vez!`

- **Jogada no TicTacToe**: `<Linha> <Coluna>`
  - Erros: `ERRO: formato incorreto`, `Essa jogada é inválida! Passa a vez!`
    
- **Jogada no Jogo da Memória**: `<Linha> <Coluna>` `<Linha> <Coluna>`
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
