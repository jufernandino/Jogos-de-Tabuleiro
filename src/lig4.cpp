#include "lig4.hpp"
#include <iomanip>
#include <iostream>
#include <string>

/**
 * @brief Construtor da classe lig4.
 *
 * Inicializa o tabuleiro do jogo Lig4 com 6 linhas e 7 colunas.
 */
lig4::lig4()
{
  this->rows = 6;
  this->columns = 7;
}

/**
 * @brief Valida uma jogada no tabuleiro.
 *
 * Esta função verifica se uma jogada é valida na partida de Lig4:
 * Primeiro verifica se a posição `(x, y)` está dentro das dimensões do tabuleiro.
 * Confere qual linha da coluna y está vazia para colocar a peça (loop para x ir de 5 até 0).
 * Se não houver casas vazias na coluna escolhida, informa ao jogador e ele perde a vez.
 * Caso tenha casa vazia e a jogada for válida, a célula recebe o caractere `z` representando o jogador.
 * Caso contrário, informa que a jogada é inválida e passa a vez.
 *
 * @param x Coordenada da linha.
 * @param y Coordenada da coluna.
 * @param z Caractere do jogador (X ou O).
 */
void lig4::validaJogada(int x, int y, char z)
{
  bool existeCasaVazia = false;
  if (y < this->columns)
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
 * @brief Confere se há um ganhador no jogo Lig4.
 *
 * Esta função verifica todas as condições de vitória possíveis em um jogo de Lig4,
 * incluindo linhas horizontais, verticais e diagonais. Se um jogador tiver quatro símbolos
 * iguais alinhados, a função retorna 1 (vitória do Jogador 1) ou 2 (vitória do Jogador 2).
 * Se não houver espaços vazios e ninguém venceu, retorna 3 indicando um empate. Se o jogo
 * ainda não terminou, retorna 0.
 *
 * @return Retorna 0 caso o ainda não tenha acabado o jogo
 * @return Retorna 1 caso o Jogador1 vença
 * @return Retorna 2 caso o Jogador2 vença
 * @return Retorna 3 caso tenha empate
 */

int lig4::confereGanhador()
{
  /// Verifica linhas horizontais
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns - 3; j++)
    {
      if (matrix[i][j] == matrix[i][j + 1] && matrix[i][j] == matrix[i][j + 2] &&
          matrix[i][j] == matrix[i][j + 3] && matrix[i][j] != ' ')
      {
        if (matrix[i][j] == 'X')
        { /// caso o Jogador1 vença
          return 1;
        }
        if (matrix[i][j] == 'O')
        { /// caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  /// Verifica linhas verticais
  for (int i = 0; i < rows - 3; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (matrix[i][j] == matrix[i + 1][j] && matrix[i][j] == matrix[i + 2][j] &&
          matrix[i][j] == matrix[i + 3][j] && matrix[i][j] != ' ')
      {
        if (matrix[i][j] == 'X')
        { /// caso o Jogador1 vença
          return 1;
        }
        if (matrix[i][j] == 'O')
        { /// caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  /// Verifica diagonais descendentes (\)
  for (int i = 0; i < rows - 3; i++)
  {
    for (int j = 0; j < columns - 3; j++)
    {
      if (matrix[i][j] == matrix[i + 1][j + 1] && matrix[i][j] == matrix[i + 2][j + 2] &&
          matrix[i][j] == matrix[i + 3][j + 3] && matrix[i][j] != ' ')
      {
        if (matrix[i][j] == 'X')
        { /// caso o Jogador1 vença
          return 1;
        }
        if (matrix[i][j] == 'O')
        { /// caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  /// Verifica diagonais ascendentes (/)
  for (int i = 3; i < rows; i++)
  {
    for (int j = 0; j < columns - 3; j++)
    {
      if (matrix[i][j] == matrix[i - 1][j + 1] && matrix[i][j] == matrix[i - 2][j + 2] &&
          matrix[i][j] == matrix[i - 3][j + 3] && matrix[i][j] != ' ')
      {
        if (matrix[i][j] == 'X')
        { /// caso o Jogador1 vença
          return 1;
        }
        if (matrix[i][j] == 'O')
        { /// caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  /// Verifica se há empate
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
