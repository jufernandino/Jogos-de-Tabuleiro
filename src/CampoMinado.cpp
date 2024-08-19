#include "CampoMinado.hpp"
#include <cstdlib>
#include <iostream>

/**
 * @brief Construtor:
 *
 * Inicializa um objeto CampoMinado com as configurações padrões
 * do tabuleiro, especificando seu tamanho com 7 linhas e 7 colunas.
 * Além disso, inicializa a quantidade de bombas do jogo como 10.
 */
CampoMinado::CampoMinado()
{
  this->rows = 7;
  this->columns = 7;
  this->bombas = 10;

  criaTabuleiro();
  iniciaTabuleiro();
}

/**
 * @brief Inicia o tabuleiro do Campo Minado:
 *
 * Esta função inicializa o tabuleiro, preenchendo todas casas com o simbolo "+".
 * Cria um vetor para guardar as coordenadas das minas, que são geradas de maneira aleatória.
 */
void CampoMinado::iniciaTabuleiro()
{
  /// inicia todo o tabuleiro com +
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < columns; ++j)
    {
      matrix[i][j] = '+';
    }
  }

  /// cria um vetor que guarda as coordenadas das minas
  srand(time(0));
  for (int i = 0; i < 10; ++i)
  {
    this->posicao_minas[0][i] = rand() % this->rows;
    this->posicao_minas[1][i] = rand() % this->columns;
  }
}

/**
 * @brief Realiza o cálculo de quantas minas existem ao redor de uma determinada posição:
 *
 * A partir de uma posição passada por parâmetro (linha, coluna) a função verifica em
 * todas as casas adjacentes (duas laterais, quatro diagonais, uma em cima e uma em baixo) se
 * as coordenadas de cada uma delas possui uma equivalência com a posição de uma mina.
 * Se forem equivalentes, o contador de bombas adjacentes recebe um acréscimo.
 *
 * @param linha linha da coordenada.
 * @param coluna coluna da coordenada.
 *
 * @return O número de bombas adjacentes à coordenada especificada.
 */
int CampoMinado::minasAdj(int linha, int coluna)
{
  int bombas_adj = 0;

  for (int x = -1; x <= 1; ++x)
  {
    for (int y = -1; y <= 1; ++y)
    {

      for (int iterador = 0; iterador < this->bombas; ++iterador)
      {
        if (linha + x == posicao_minas[0][iterador] &&
            coluna + y == posicao_minas[1][iterador])
          bombas_adj++;
      }
    }
  }

  return bombas_adj;
}

/**
 * @brief Esboça no tabuleiro o conteúdo de uma célula (que não possui bomba):
 *
 * A partir de uma posição passada por parâmetro (linha, coluna),se for uma jogada válida,
 * a casa escolhida recebe como conteúdo o número correspondete às suas minas adjacentes.
 * Porém, no caso do número de bombas adjacentes ser equivalente a zero, a célula fica vazia e
 * a função "revelaCelula" é chamada para todas as casas ao seu redor,
 * até serem preenchidas com um número maior do que zero.
 *
 * @param linha linha da coordenada.
 * @param coluna coluna da coordenada.
 */
void CampoMinado::revelaCelula(int linha, int coluna)
{
  int minas_adj = minasAdj(linha, coluna);

  if (!validaJogadaCampoMinado(linha, coluna))
  {
    return;
  }

  if (minas_adj > 0)
  {
    matrix[linha][coluna] = '0' + minas_adj;
  }
  else
  { // se não tem bomba adjacente, marca com espaco em branco e revela as células adjacentes
    matrix[linha][coluna] = ' ';

    for (int x = -1; x <= 1; ++x)
    {
      for (int y = -1; y <= 1; ++y)
      {
        revelaCelula(linha + x, coluna + y);
      }
    }
  }
}

/**
 * @brief Verifica se a jogada é valida de acordo com as regras do Campo Minado:
 *
 * Esta função booleana agrupa todas as condições para determinar se uma jogada é válida ou não.
 * Primeiro, verifica se a coordenada `(linha, coluna)`, passada por parâmetro,se encontra dentro
 * das dimensões do tabuleiro. E segundo, verifica se ela não foi revelada ainda (contém o simbolo `+`) .
 *
 * @param linha linha da coordenada.
 * @param coluna coluna da coordenada.
 *
 * @return Verdadeiro, caso atenda a todas as condições de ser uma jogada válida.
 * @return Falso, caso não atenda a pelo menos uma das condições.
 */
bool CampoMinado::validaJogadaCampoMinado(int linha, int coluna)
{
  if (linha < 0 || linha >= rows || coluna < 0 || coluna >= columns ||
      matrix[linha][coluna] != '+')
  {
    return false;
  }
  else
  {
    return true;
  }
}

/**
 * @brief Averigua se a posição escolhida corresponde a de uma bomba:
 *
 * Esta função booleana verifica se a coordenada passada por parâmetro,
 * `(linha, coluna)`, é equivalente a alguma das coordenadas das posições das minas.
 *
 * @param linha linha da coordenada.
 * @param coluna coluna da coordenada.
 *
 * @return Verdadeiro, caso tenha uma bomba na posição.
 * @return Falso, caso não tenha uma bomba na posição.
 */
bool CampoMinado::escolheuBomba(int linha, int coluna)
{
  for (int i = 0; i < this->bombas; ++i)
  {
    if (linha == posicao_minas[0][i] && coluna == posicao_minas[1][i])
      return true;
  }
  return false;
}

/**
 * @brief Condição de vitória em um jogo de Campo Minado:
 *
 * Esta função confere se ainda existe alguma casa `+` no tabuleiro que não foi escolhidas pelo jogador e,
 * além disso, averigua se ela não é correspondentes a uma bomba. Caso ainda exista, significa
 * que tem jogadas pendentes a serem realizadas. Em caso negativo, o jogo acabou e nenhuma bomba foi encontrada.
 * Ou seja, o jogador ganhou.
 *
 * @return 0, caso ainda exista jogadas possíveis.
 * @return 1, caso o jogo tenha acabado.
 */
int CampoMinado::confereGanhador()
{
  int faltou = 0;

  for (int coordX = 0; coordX < rows; ++coordX)
  {
    for (int coordY = 0; coordY < columns; ++coordY)
    {
      for (int iterador = 0; iterador < 10; ++iterador)
      {
        if (matrix[coordX][coordY] == '+' &&
            !(posicao_minas[0][iterador] == coordX &&
              posicao_minas[1][iterador] == coordY))
        {
          faltou++;
        }
      }
    }
  }

  if (faltou != 0)
  {
    return 0;
  }
  else if (faltou == 0)
  {
    return 1;
  }
  return 2;
}
