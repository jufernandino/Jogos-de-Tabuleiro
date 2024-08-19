#ifndef Reversi_H
#define Reversi_H
#include "Tabuleiro.hpp"

using namespace std;
/**
 * @class Reversi
 * @brief Classe que representa o jogo Reversi
 *
 * A classe "Reversi" é uma classe herdeira de classe base "Tabuleiro" e implementa
 * a lógica específica do jogo Reversi, incluindo a verificação de condição de vitória e
 * a validação de uma jogada (funções que sobrescrevem as da classe base).
 * Além disso inclui métodos próprios como: inicialização das peças iniciais do jogo,
 * verificação se a jogada é valida de acordo com as regras do Reversi,
 * verificação de movimentos possíveis, mostrar locais de possíveis jogadas,
 * verificação da disponibilidade de movimentos, inversão das peças.
 */
class Reversi : public Tabuleiro
{
public:
  /**
   * @brief Construtor da classe.
   */
  Reversi();

  /**
   * @brief Esta função sobrescreve o método "confereGanhador" da classe base "Tabuleiro"
   * e implementa a lógica para verificar se há um vencedor na partida de Reversi.
   *
   * @retval int 0
   * @retval int 1
   * @retval int 2
   * @retval int 3
   */
  virtual int confereGanhador() override;

  /**
   * @brief Esta função sobrescreve o método "validaJogada" da classe base "Tabuleiro"
   * e implementa a lógica para validar a jogada na partida de Reversi.
   *
   * @param x int
   * @param y int
   * @param z char
   *
   * @retval none
   */
  virtual void validaJogada(int x, int y, char z) override;

  /**
   * @brief Inicialização específica do Reversi.
   *
   * @retval none
   */
  void inicializarJogo();

  /**
   * @brief Validação da jogada.
   *
   * @param x int
   * @param y int
   * @param jogadorDaVez char
   *
   * @retval true
   * @retval false
   */
  bool ehJogadaValida(int x, int y, char jogadorDaVez);

  /**
   * @brief Validação da existência de movimentos possívei no turno.
   *
   * @param jogadorDaVez char
   *
   * @retval true
   * @retval false
   */
  bool existeMovimentoPossivel(char jogadorDaVez);

  /**
   * @brief Informação sobre possíveis jogadas no turno.
   *
   * @param jogador char
   *
   * @retval none
   */
  void mostrarLocaisJogada(char jogador);

  /**
   * @brief Verificador de fim da partida.
   *
   * @retval true
   * @retval false
   */
  bool verificarFimDeJogo(); /// chamada todas as vezes que um movimento é feito

  /**
   * @brief Inversão das peças a cada jogada.
   *
   * @param x int
   * @param y int
   * @param jogadorDaVez chars
   *
   * @retval none
   */
  void inverterPecas(int x, int y, char jogadorDaVez);

private:
  /**
   * @brief Variável para armazenar qual a peça do jogador atual (ou X ou O).
   * @var
   */
  char jogadorAtual;
};

#endif