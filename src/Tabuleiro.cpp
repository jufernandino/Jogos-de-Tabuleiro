#include "Tabuleiro.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Tabuleiro::Tabuleiro() {
  this->rows = 0;
  this->columns = 0;
}

void Tabuleiro::criaTabuleiro() {
  p = new char *[rows];
  for (int i = 0; i < rows; i++) {
    p[i] = new char[columns];
    for (int j = 0; j < columns; j++) {
      p[i][j] = ' ';
    }
  }
}

void Tabuleiro::liberaMemoria() {
  for (int i = 0; i < rows; i++) {
    delete[] p[i];
  }
  delete[] p;
}

void Tabuleiro::validaJogada(int x, int y, char z) {
  if (x < this->rows && y < this->columns && p[x][y] == ' ') {
    p[x][y] = z;
  }
}