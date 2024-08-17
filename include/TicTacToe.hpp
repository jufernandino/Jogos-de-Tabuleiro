#ifndef TicTacToe_H
#define TicTacToe_H
#include "Tabuleiro.hpp"
#include <iostream>
#include <string>

using namespace std;

/**
 * @class TicTacToe
 * @brief Classe que representa o jogo Tic-Tac-Toe.
 *
 * A classe "TicTacToe" herda da classe base "Tabuleiro" e implementa
 * a lógica específica do jogo Tic-Tac-Toe, incluindo a verificação de
 * condições de vitória.
 */
class TicTacToe : public Tabuleiro
{
public:
  /**
   * @brief Construtor da classe TicTacToe.
   *
   * Inicializa um objeto TicTacToe com as configurações padrão do tabuleiro.
   */
  TicTacToe();

  /**
   * @brief Confere se há um ganhador no jogo Tic-Tac-Toe.
   *
   * Esta função sobrescreve o método "confereGanhador" da classe base "Tabuleiro"
   * e implementa a lógica para verificar se há um vencedor na partida de Tic-Tac-Toe.
   *
   * @return Retorna 1 se houver um vencedor, 0 caso contrário.
   */
  virtual int confereGanhador() override;
};

#endif