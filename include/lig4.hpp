#ifndef lig4_H
#define lig4_H
#include "Tabuleiro.hpp"
#include <iostream>
#include <string>

using namespace std;
/**
 * @class lig4
 * @brief Classe que representa o jogo Lig4
 *
 * A classe "Lig4" é uma classe herdeira de classe base "Tabuleiro" e implementa
 * a lógica específica do jogo Lig4, incluindo a verificação de condição de vitória
 * e a verificação de jogada válida.
 */
class lig4 : public Tabuleiro
{
public:
  /**
   * @brief Construtor da classe.
   *
   */
  lig4();

  /**
   * @brief Esta função sobrescreve o método "validaJogada" da classe base
   * "Tabuleiro"e implementa a lógica para validar a jogada na partida de Lig4.
   *
   * @param x int
   * @param y int
   * @param z char
   *
   * @retval none
   */
  virtual void validaJogada(int x, int y, char z) override;

  /**
   * @brief Esta função sobrescreve o método "confereGanhador" da classe base "Tabuleiro"
   * e implementa a lógica para verificar se há um vencedor na partida de Lig4.
   *
   * @retval int 0
   * @retval int 1
   * @retval int 2
   * @retval int 3
   */
  virtual int confereGanhador() override;
};

#endif