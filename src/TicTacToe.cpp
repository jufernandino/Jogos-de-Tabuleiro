#include "TicTacToe.hpp"
#include <iomanip>
#include <iostream>
#include <string>

/**
 * @brief Construtor da classe TicTacToe.
 * 
 * Inicializa o tabuleiro do jogo Tic-Tac-Toe com 3 linhas e 3 colunas.
 */
TicTacToe::TicTacToe()
{
  this->rows = 3;
  this->columns = 3;
}

/**
 * @brief Confere se há um ganhador no jogo Tic-Tac-Toe.
 * 
 * Esta função verifica todas as condições de vitória possíveis em um jogo de Tic-Tac-Toe,
 * incluindo linhas horizontais, verticais e diagonais. Se um jogador tiver três símbolos
 * iguais alinhados, a função retorna 1 (vitória do Jogador 1) ou 2 (vitória do Jogador 2).
 * Se não houver espaços vazios e ninguém venceu, retorna 3 indicando um empate. Se o jogo
 * ainda não terminou, retorna 0.
 * 
 * @return int Retorna 1 se o Jogador 1 vencer, 2 se o Jogador 2 vencer, 3 para empate e 0 se não houver vencedor.
 */
int TicTacToe::confereGanhador()
{
  for (int i = 0; i < rows; i++)
  {
    // valida as linhas horizontais:
    if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0] != ' ')
    {
      if (matrix[i][0] == 'X')
      { // caso o Jogador1 vença
        return 1;
      }
      if (matrix[i][0] == 'O')
      { // caso o Jogador2 vença
        return 2;
      }
    }
    // valida as linhas verticais:
    if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i] && matrix[0][i] != ' ')
    {
      if (matrix[0][i] == 'X')
      { // caso o Jogador1 vença
        return 1;
      }
      if (matrix[0][i] == 'O')
      { // caso o Jogador2 vença
        return 2;
      }
    }
  }
  // validam as linhas diagonais:
  if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] && matrix[0][0] != ' ')
  {
    if (matrix[0][0] == 'X')
    { // caso o Jogador1 vença
      return 1;
    }
    if (matrix[0][0] == 'O')
    { // caso o Jogador2 vença
      return 2;
    }
  }
  if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0] && matrix[2][0] != ' ')
  {
    if (matrix[0][2] == 'X')
    { // caso o Jogador1 vença
      return 1;
    }
    if (matrix[0][2] == 'O')
    { // caso o Jogador2 vença
      return 2;
    }
  }
  // caso ninguém vença
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
