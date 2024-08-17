#ifndef Reversi_H
#define Reversi_H
#include "Tabuleiro.hpp"

using namespace std;
/**
 * @class Reversi
 * @brief Classe que representa o jogo Reversi
 *
 * A classe "Reversi" é uma classe herdeira de classe base "Tabuleiro" e implementa
 * a lógica específica do jogo Reversi, incluindo a verificação de condição de vitoria e
 * a validação de uma jogada (funções que sobrescrevem as da classe base).
 * Além disso inclui métodos próprios como: inicialização das peças iniciais do jogo,
 * verificação se a jogada é valida de acordo com as regras do Reversi,
 * verificação de movimentos possíveis, mostrar locais de possíveis jogadas,
 * verificação da disponibilidade de movimentos, inversão das peças
 */
class Reversi : public Tabuleiro
{
public:
  /**
   * @brief Construtor da classe Reversi.
   *
   * Inicializa um objeto Reversi com as configurações padrões do tabuleiro.
   */
  Reversi();

  /**
   * @brief Confere se há um ganhador no jogo.
   *
   * Esta função sobrescreve o método "confereGanhador" da classe base "Tabuleiro"
   * e implementa a lógica para verificar se há um vencedor na partida de Reversi.
   *
   * @return Retorna 1 se houver um vencedor, 0 caso contrário.
   */
  virtual int confereGanhador() override;

  /**
   * @brief Valida uma jogada no tabuleiro.
   *
   * Esta função sobrescreve o método "validaJogada" da classe base "Tabuleiro"
   * e implementa a lógica para validar a jogada na partida de Reversi.
   *
   * @param x Coordenada da linha.
   * @param y Coordenada da coluna.
   * @param z Peça do jogador (X ou O).
   */
  virtual void validaJogada(int x, int y, char z) override;

  /**
   * @brief Inicializa o jogo Reversi
   *
   * Esta função implementa as condições iniciais para o Reversi
   *
   */
  void inicializarJogo();

  /**
   * @brief Verifica se a jogada é valida de acordo com as regras do Reversi.
   *
   * Esta função booleana agrupa todas as condições para determinar se uma jogada
   * é válida de acordo com as regras do Reversi.
   *
   * @param x Coordenada da linha.
   * @param y Coordenada da coluna.
   * @param jogadorDaVez Peça do jogador (X ou O).
   *
   * @return Retorna verdadeiro, caso atenda a todas as condições de ser uma jogada válida.
   * @return Retorna falso caso contrário.
   */
  bool ehJogadaValida(int x, int y, char jogadorDaVez);

  /**
   * @brief Verifica se existe ao menos um movimento a ser feito no turno do jogador.
   *
   * Esta função booleana confere se existem locais no tabuleiro para realizar
   * uma jogada válida, durante o turno de um jogador
   *
   * @param jogadorDaVez Peça do jogador (X ou O).
   *
   * @return Retorna verdadeiro, se existir pelo menos um movimento possível.
   * @return Retorna falso, caso não exista nenhum movimento possível.
   */
  bool existeMovimentoPossivel(char jogadorDaVez);

  /**
   * @brief Exibe as coordenadas de possíveis jogadas.
   *
   * Esta função avalia e exibe todas as coordenadas válidas do
   * tabuleiro que o jogador poderá escolher durante seu turno.
   *
   * @param jogador Peça do jogador (X ou O).
   */
  void mostrarLocaisJogada(char jogador);

  /**
   * @brief Verifica as condições do Reversi para decretar o fim de uma partida.
   *
   * Esta função booleana confere todas as condições para determinar se o jogo acabou ou não.
   *
   * @return retorna verdadeiro, se o jogo tiver acabado, e falso, caso contrário.
   */
  bool verificarFimDeJogo(); /// chamada todas as vezes que um movimento é feito

private:
  /**
   * @brief Variável para armazenar qual a peça do jogador atual (ou X ou O)
   */
  char jogadorAtual;

  /**
   * @brief Responsável por realizar a inversão das peças a cada jogada .
   *
   * Esta função altera todas as cores das peças adversárias
   * que estão confinadas entre duas peças do jogador da vez.
   *
   * @param x Coordenada da linha.
   * @param y Coordenada da coluna.
   * @param jogadorDaVez Peça do jogador (X ou O).
   */
  void inverterPecas(int x, int y, char jogadorDaVez);
};

#endif