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
    for (int j = 0; j < columns; j++) {
      if (p[i][j] == p[i][j + 1] && p[i][j] == p[i][j + 2] && p[i][j] != ' ') {
        cout << "entrei no primeiro if" << endl;
        return 1;
      }
      if (p[i][j] == p[i + 1][j] && p[i][j] == p[i + 2][j] && p[i][j] != ' ') {
        cout << "entrei no segundo if" << endl;
        return 1;
      }
    }
  }
  return 0;
}