#ifndef CampoMinado_H
#define CampoMinado_H
#include "Tabuleiro.hpp"

using namespace std;
/**
 * @class CampoMinado
 * @brief Classe que representa o jogo Campo Minado
 *
 * A classe "Campo Minado" é uma classe herdeira de classe base "Tabuleiro" e implementa a lógica específica do
 * jogo de Campo Minado, incluindo a verificação de condição de vitória (função que sobrescreve a da classe base).
 * Além disso inclui métodos próprios como: inicialização do tabuleiro, revelar o conteúdo de cada casa, validação
 * de jogadas, conferir se uma bomba foi escolhida, e a jogabilidade em si.
 */
class CampoMinado : public Tabuleiro
{
public:
  /**
   * @brief Construtor da classe.
   *
   */
  CampoMinado();

  /**
   * @brief Inicialização do tabuleiro.
   *
   * @retval none
   */
  void iniciaTabuleiro();

  /**
   * @brief Cálculo das minas adjacentes a uma posição.
   *
   * @param linha int
   * @param coluna int
   *
   * @retval int n
   */
  int minasAdj(int linha, int coluna);

  /**
   * @brief Exposição do conteúdo de uma casa do tabuleiro.
   *
   * @param linha int
   * @param coluna int
   *
   * @retval none
   */
  void revelaCelula(int linha, int coluna);

  /**
   * @brief Validação da jogada.
   *
   * @param linha int
   * @param coluna int
   *
   * @retval true
   * @retval false
   */
  bool validaJogadaCampoMinado(int linha, int coluna);

  /**
   * @brief Verificação se existe bomba em uma posição.
   *
   * @param linha int
   * @param coluna int
   *
   * @retval true
   * @retval false
   */
  bool escolheuBomba(int linha, int coluna);

  /**
   * @brief Esta função sobrescreve o método "confereGanhador" da classe base "Tabuleiro"
   * e implementa a lógica para verificar se o jogador venceu na partida de Campo Minado.
   *
   * @retval int 0
   * @retval int 1
   */
  int confereGanhador() override;

  /**
   * @brief Organização da jogabilidade passo-a-passo.
   *
   * @retval int 0
   * @retval int 1
   */
  int jogarCampoMinado();

private:
  /**
   * @brief Variável para armazenar o número de bombas.
   * @var
   */
  int bombas;
  /**
   * @brief Matriz para armazenar as posições das minas.
   * @var
   */
  int posicao_minas[2][10];
};

#endif