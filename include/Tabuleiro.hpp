#ifndef Tabuleiro_H
#define Tabuleiro_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @class Tabuleiro
 * @brief Classe base para representar um tabuleiro de jogo.
 * 
 * A classe "Tabuleiro" fornece uma interface básica para criar, imprimir e manipular 
 * um tabuleiro de jogo, bem como conferir o ganhador de uma partida. 
 * Esta classe serve como base para tabuleiros específicos de jogos, permitindo 
 * herança e personalização.
 */
class Tabuleiro
{
public:
  char **matrix;
  int rows;
  int columns;

/**
 * @brief Construtor padrão da classe Tabuleiro.
 * 
 * Inicializa os atributos `rows` e `columns` com valores padrão e 
 * prepara a matriz para representar o tabuleiro.
 */
  Tabuleiro();

/**
 * @brief Cria o tabuleiro alocando memória dinamicamente para a matriz.
 * 
 * Esta função aloca uma matriz 2D de caracteres que será usada como 
 * tabuleiro de jogo, com as dimensões especificadas pelos atributos `rows` e `columns`.
 */
  void criaTabuleiro(); // aloca uma matriz dinamicamente que servirá como tabuleiro

/**
 * @brief Imprime o tabuleiro na tela.
 * 
 * Esta função imprime o tabuleiro com os caracteres de separação como `-` e `|` 
 * para representar as células do tabuleiro.
 */
  virtual void imprimirTabuleiro(); // imrpime o tabuleiro com -s e |s

/**
 * @brief Valida uma jogada no tabuleiro.
 * 
 * Verifica se os valores inseridos para a jogada estão dentro das dimensões do tabuleiro 
 * e, se válidos, efetua a jogada no tabuleiro.
 * 
 * @param x Coordenada da linha da jogada.
 * @param y Coordenada da coluna da jogada.
 * @param z Caractere que representa o jogador (ex: 'X' ou 'O').
 */
  virtual void validaJogada(int x, int y, char z); // confere se os valores inseridos são menores que as dimensôes do tabuleiro e efetua a jogada

/**
 * @brief Libera a memória alocada para o tabuleiro.
 * 
 * Esta função libera a memória previamente alocada para a matriz do tabuleiro, 
 * evitando vazamentos de memória.
 */
  void liberaMemoria(); // libera a memória alocada anteriomente em criaTabuleiro()

/**
 * @brief Confere se há um ganhador no jogo.
 * 
 * Função virtual pura que deve ser implementada pelas classes derivadas para 
 * verificar se há um vencedor na partida.
 * 
 * @return Um inteiro que indica o resultado da conferência (1 para vitória, 0 para nenhum vencedor).
 */
  virtual int confereGanhador() = 0; // confere se alguém venceu

/**
 * @brief Mostra as regras do jogo correspondente.
 * 
 * Esta função exibe as regras básicas do jogo escolhido pelo jogador.
 * 
 * @param jogoEscolhido Caracter que identifica o jogo escolhido.
 */
  void mostrarRegras(const char &jogoEscolhido);
};

#endif