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
 * a lógica específica do jogo Lig4, incluindo a verificação de condição de vitoria
 * e a verificação de jogada válida.
 */
class lig4 : public Tabuleiro
{
public:
  /**
   * @brief Construtor da classe lig4.
   *
   * Inicializa um objeto lig4 com as configurações padrões do tabuleiro.
   */
  lig4();

  /**
   * @brief Valida uma jogada no tabuleiro.
   *
   * Esta função sobrescreve o método "validaJogada" da classe base "Tabuleiro"
   * e implementa a lógica para validar a jogada na partida de Lig4
   *
   * @param x Coordenada da linha.
   * @param y Coordenada da coluna.
   * @param z Peça do jogador (X ou O).
   */
  virtual void validaJogada(int x, int y, char z) override;

  /**
   * @brief Confere se há um ganhador no jogo.
   *
   * Esta função sobrescreve o método "confereGanhador" da classe base "Tabuleiro"
   * e implementa a lógica para verificar se há um vencedor na partida de Lig4.
   *
   * @return Retorna 1 se houver um vencedor, 0 caso contrário.
   */
  virtual int confereGanhador() override;
};

#endif