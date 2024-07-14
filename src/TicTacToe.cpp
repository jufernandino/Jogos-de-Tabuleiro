#include "TicTacToe.hpp"
#include <iomanip>
#include <iostream>
#include <string>

TicTacToe::TicTacToe() {
  this->rows = 3;
  this->columns = 3;
}

void TicTacToe::validaJogada(int x, int y, char z) {
  if (x < 3 && y < 3 && p[x][y] == ' ') {
    p[x][y] = z;
  }
}

int TicTacToe::confereGanhador() {
  for (int i = 0; i < rows; i++) {
    // valida as linhas horizontais:
    if (p[i][0] == p[i][1] && p[i][0] == p[i][2] && p[i][0] != ' ') {
      if (p[i][0] == 'X') { // caso o Jogador1 vença
        return 1;
      }
      if (p[i][0] == 'O') { // caso o Jogador2 vença
        return 2;
      }
    }
    // valida as linhas verticais:
    if (p[0][i] == p[1][i] && p[0][i] == p[2][i] && p[0][i] != ' ') {
      if (p[0][i] == 'X') { // caso o Jogador1 vença
        return 1;
      }
      if (p[0][i] == 'O') { // caso o Jogador2 vença
        return 2;
      }
    }
  }
  // validam as linhas diagonais:
  if (p[0][0] == p[1][1] && p[0][0] == p[2][2] && p[0][0] != ' ') {
    if (p[0][0] == 'X') { // caso o Jogador1 vença
      return 1;
    }
    if (p[0][0] == 'O') { // caso o Jogador2 vença
      return 2;
    }
  }
  if (p[0][2] == p[1][1] && p[0][2] == p[2][2] && p[2][0] != ' ') {
    if (p[0][2] == 'X') { // caso o Jogador1 vença
      return 1;
    }
    if (p[0][2] == 'O') { // caso o Jogador2 vença
      return 2;
    }
  }
  // caso ninguém vença
  int i, j, a = 0;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      if (p[i][j] == ' ') {
        a = 1;
      }
    }
  }
  if (!a) {
    return 3;
  }
  return 0;
}