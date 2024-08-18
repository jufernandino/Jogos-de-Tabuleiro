#ifndef CampoMinado_H
#define CampoMinado_H
#include "Tabuleiro.hpp"

using namespace std;
/**
 * @class CampoMinado
 * @brief Classe que representa o jogo Campo Minado
 *
 * A classe "Campo Minado" é uma classe herdeira de classe base "Tabuleiro" e implementa a lógica específica do
 * jogo de Campo Minado, incluindo a verificação de condição de vitoria (função que sobrescreve a da classe base).
 * Além disso inclui métodos próprios como: inicialização do tabuleiro, revelar o conteúdo de cada casa, validação
 * de jogadas, conferir se uma bomba foi escolhida, e a jogabilidade em si.
 */
class CampoMinado : public Tabuleiro
{
public:
  /**
   * @brief Construtor da classe CampoMinado.
   *
   * Inicializa um objeto CampoMinado com as configurações padrões do tabuleiro.
   */
  CampoMinado();

  /**
   * @brief Incializa o tabuleiro do Campo Minado
   *
   * Esta função inicializa o tabuleiro, preenchendo todas casas com o simbolo "+".
   * E salva, em um vetor, as posições das minas que são geradas aleatoriamente.
   */
  void iniciaTabuleiro();

  /**
   * @brief Realiza o cálculo de quantas minas existem ao redor de uma determinada posição.
   *
   * A partir de uma posição passada por parâmetro (linha, coluna) a função verifica quantas
   * bombas existem nas casas adjacentes à coordenada.
   *
   * @param linha Linha da coordenada.
   * @param coluna Coluna da coordenada.
   *
   * @return Retorna o número de bombas adjacentes à coordenada especificada.
   */
  int minasAdj(int linha, int coluna);

  /**
   * @brief Esboça no tabuleiro as casas que não possuem bombas
   *
   * A partir de uma posição passada por parâmetro (linha, coluna), a função
   * revela o conteúdo da célula escolhida (ou seja, o número de bombas adjacentes).
   * Caso o número seja igual 0, vai revelando das outras casas ao redor.
   *
   * @param linha Linha da coordenada.
   * @param coluna Coluna da coordenada.
   */
  void revelaCelula(int linha, int coluna);

  /**
   * @brief Verifica se a jogada é valida de acordo com as regras do Campo Minado.
   *
   * Esta função booleana agrupa todas as condições para determinar se uma jogada
   * é válida de acordo com as regras do jogo do Campo Minado.
   *
   * @param linha Linha da coordenada.
   * @param coluna Coluna da coordenada.
   *
   * @return Retorna verdadeiro, caso seja uma jogada válida.
   * @return Retorna falso caso contrário.
   */
  bool validaJogadaCampoMinado(int linha, int coluna);

  /**
   * @brief Verifica se a posição escolhida corresponde a de uma bomba.
   *
   * Esta função booleana verifica se a coordenada passada por parâmetro,
   * é equivalente a uma bomba.
   *
   * @param linha Linha da coordenada.
   * @param coluna Coluna da coordenada.
   *
   * @return Retorna verdadeiro, caso tenha uma bomba na posição.
   * @return Retorna falso, caso não tenha uma bomba na posição.
   */
  bool escolheuBomba(int linha, int coluna);

  /**
   * @brief Confere se o jogador ganhou ou perdeu.
   *
   * Esta função sobrescreve o método "confereGanhador" da classe base "Tabuleiro"
   * e implementa a lógica para verificar se o jogador venceu na partida de Campo Minado.
   *
   * @return Retorna 0 caso ainda tenha jogadas possiveis.
   * @return Retorna 1 caso o jogo tenha acabado.
   */
  int confereGanhador() override;

  /**
   * @brief Organiza o processo de jogabilidade de Campo Minado.
   *
   * Esta função é responsável por organizar cada passo do jogo em si.
   *
   * @return Retorna 0 caso o jogador perca/encontre uma bomba.
   * @return Retorna 1 caso o jogador ganhe.
   */
  int jogarCampoMinado();

private:
  /**
   * @brief Variável para armazenar o número de bombas
   */
  int bombas;
  /**
   * @brief Matriz para armazenar as posições das minas
   */
  int posicao_minas[2][10];
};

#endif