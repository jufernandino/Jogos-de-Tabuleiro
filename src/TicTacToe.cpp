#include "TicTacToe.hpp"
#include <iomanip>
#include <iostream>
#include <string>

TicTacToe::TicTacToe()
{
  this->rows = 3;
  this->columns = 3;
}

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
