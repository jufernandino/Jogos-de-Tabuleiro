#include "lig4.hpp"
#include <iomanip>
#include <iostream>
#include <string>

/**
 * @brief Construtor:
 *
 * Inicializa um objeto lig4 com as configurações padrões do
 * tabuleiro, especificando seu tamanho como 6 linhas e 7 colunas.
 */
lig4::lig4()
{
  this->rows = 6;
  this->columns = 7;
  criaTabuleiro();
}

/**
 * @brief Validação de uma jogada no Lig4:
 *
 * Primeiro verifica se a posição `(x, y)`, passada por parâmetro, está dentro das dimensões do tabuleiro.
 * Confere qual linha da coluna y está vazia para receber a peça (loop para x ir de 5 até 0).
 * Se não houver casas vazias na coluna escolhida, isso é informado ao jogador e ele perde a vez.
 * Caso tenha a casa vazia e a jogada seja válida, a célula recebe o caractere `z` representando o jogador.
 * Caso contrário, informa que a jogada é inválida e passa-se a vez.
 *
 * @param x coordenada da linha.
 * @param y coordenada da coluna.
 * @param z caractere do jogador (X ou O).
 */
void lig4::validaJogada(int x, int y, char z)
{
  bool existeCasaVazia = false;
  if (y < this->columns && y >= 0)
  {
    for (int i = 5; i >= 0; i--)
    {
      if (matrix[i][y] == ' ')
      {
        matrix[i][y] = z;
        existeCasaVazia = true;
        break;
      }
      else
      {
        continue;
      }
    }
    if (!existeCasaVazia)
    {
      cout << "\nNão existem mais posições disponiveis nessa coluna! Perde a vez!\n"
           << endl;
    }
  }
  else
  {
    cout << "\nEssa jogada é invalida! Passa a vez!\n"
         << endl;
  }
}
/**
 * @brief Condição de vitória em um jogo de Lig4:
 *
 * Se um jogador tiver quatro símbolos iguais alinhados (incluindo linhas horizontais, verticais e diagonais),
 * a função ou retorna 1 (vitória do Jogador 1) ou retorna 2 (vitória do Jogador 2).
 * Se não houver espaços vazios e ninguém consegui alinhar quatro simbolos, então retorna 3, indicando um empate.
 * Se o jogo ainda não tiver acabado, retorna 0.
 *
 * @return 0, caso ainda não tenha acabado o jogo.
 * @return 1, caso o Jogador1 vença.
 * @return 2, caso o Jogador2 vença.
 * @return 3, caso ocorra um empate.
 */

int lig4::confereGanhador()
{
  // Verifica linhas horizontais
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns - 3; j++)
    {
      if (matrix[i][j] == matrix[i][j + 1] && matrix[i][j] == matrix[i][j + 2] &&
          matrix[i][j] == matrix[i][j + 3] && matrix[i][j] != ' ')
      {
        if (matrix[i][j] == 'X')
        { // Caso o Jogador1 vença
          return 1;
        }
        if (matrix[i][j] == 'O')
        { // Caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  // Verifica linhas verticais
  for (int i = 0; i < rows - 3; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (matrix[i][j] == matrix[i + 1][j] && matrix[i][j] == matrix[i + 2][j] &&
          matrix[i][j] == matrix[i + 3][j] && matrix[i][j] != ' ')
      {
        if (matrix[i][j] == 'X')
        { // Caso o Jogador1 vença
          return 1;
        }
        if (matrix[i][j] == 'O')
        { // Caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  // Verifica diagonais descendentes (\)
  for (int i = 0; i < rows - 3; i++)
  {
    for (int j = 0; j < columns - 3; j++)
    {
      if (matrix[i][j] == matrix[i + 1][j + 1] && matrix[i][j] == matrix[i + 2][j + 2] &&
          matrix[i][j] == matrix[i + 3][j + 3] && matrix[i][j] != ' ')
      {
        if (matrix[i][j] == 'X')
        { // Caso o Jogador1 vença
          return 1;
        }
        if (matrix[i][j] == 'O')
        { // Caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  // Verifica diagonais ascendentes (/)
  for (int i = 3; i < rows; i++)
  {
    for (int j = 0; j < columns - 3; j++)
    {
      if (matrix[i][j] == matrix[i - 1][j + 1] && matrix[i][j] == matrix[i - 2][j + 2] &&
          matrix[i][j] == matrix[i - 3][j + 3] && matrix[i][j] != ' ')
      {
        if (matrix[i][j] == 'X')
        { // Caso o Jogador1 vença
          return 1;
        }
        if (matrix[i][j] == 'O')
        { // Caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  // Verifica se há empate
  bool empate = true;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (matrix[i][j] == ' ')
      {
        empate = false;
        break;
      }
    }
    if (!empate)
    {
      break;
    }
  }

  if (empate)
  {
    return 3;
  }

  return 0;
}
