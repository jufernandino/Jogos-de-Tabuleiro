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
`Compilação: `Makefile  
`Documentação: `Doxygen  
`Testes: `Biblioteca doctest  
`Controle de Versão: `Git e GitHub

## Estrutura do Projeto
O projeto foi organizado em classes, cada uma com suas responsabilidades.

- **Jogadores:** Implementa métodos relacionados aos jogadores, além de mostrar as estatísticas e ordenar.
- **Tabuleiro:** Contém os métodos que gerenciam o tabuleiro, além de mostrar as regras e fazer a conferência do ganhador.
- *As classes CampoMinado, Lig4, Reversi, TicTacToe e Memória impelementam a lógica de cada jogo, respectivamente.*

## Inputs
Os inputs foram os estabelecidos pelo enunciado, com as entradas e as eventuais mensagens de erro:

**Cadastrar Jogador**
CJ <Apelido> <Nome> (obs. Considere que <Apelido> é composto por uma única palavra)  
Jogador <Apelido> cadastrado com sucesso  
ERRO: dados incorretos  
ERRO: jogador repetido  

**Remover Jogador**
RJ <Apelido>  
Jogador <Apelido> removido com sucesso  
ERRO: jogador inexistente

**Listar todos os jogadores ordenados por Apelido ou Nome, seguido pelo número de vitórias e derrotas em cada jogo:**  
LJ A|N
<Apelido> <Nome>  
REVERSI - V: <#vitorias> D: <#derrotas>  
LIG4 - V: <#vitorias> D: <#derrotas>  

**Executar Partida**  
EP <Jogo: (R|L)> <Apelido Jogador 1> <Apelido Jogador 2>  
ERRO: dados incorretos  
ERRO: jogador inexistente  

**Finalizar Sistema**  
FS  

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
