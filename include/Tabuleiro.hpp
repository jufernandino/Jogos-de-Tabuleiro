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
 * um tabuleiro de jogo. É uma classe base para o tabuleiro dos jogos.
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
   * Inicializa os atributos "rows" e "columns".
   */
  Tabuleiro();

  /**
   * @brief Cria o tabuleiro alocando memória dinamicamente para a matriz.
   *
   * Aloca a matriz que será utilizada como tabuleiro.
   * 
   * @retval none
   */
  void criaTabuleiro(); // aloca uma matriz dinamicamente que servirá como tabuleiro

  /**
   * @brief Imprime o tabuleiro na tela.
   *
   * Esta função imprime o tabuleiro.
   * 
   * @retval none
   */
  virtual void imprimirTabuleiro(); // imrpime o tabuleiro com -s e |s

  /**
   * @brief Valida uma jogada no tabuleiro.
   *
   * Verifica se os valores inseridos para a jogada estão dentro das dimensões do tabuleiro.
   *
   * @param x int 
   * @param y int
   * @param z int
   * 
   * @retval none
   */
  virtual void validaJogada(int x, int y, char z); // confere se os valores inseridos são menores que as dimensôes do tabuleiro e efetua a jogada

  /**
   * @brief Libera a memória alocada para o tabuleiro.
   *
   * Esta função libera a memória previamente alocada.
   * 
   * @retval none
   */
  void liberaMemoria(); // libera a memória alocada anteriomente em criaTabuleiro()

  /**
   * @brief Confere se há um ganhador no jogo.
   *
   * Função virtual pura que deve ser implementada pelas classes derivadas para
   * verificar se há um vencedor na partida.
   *
   * @retval int
   */
  virtual int confereGanhador() = 0; /// confere se alguém venceu

  /**
   * @brief Mostra as regras do jogo correspondente.
   *
   * Esta função exibe as regras jogo escolhido pelo jogador.
   *
   * @param jogoEscolhido char
   * 
   * @retval none
   */
  void mostrarRegras(const char &jogoEscolhido);
};

#endif