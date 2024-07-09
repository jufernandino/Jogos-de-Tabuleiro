#include "Tabuleiro.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Tabuleiro::Tabuleiro() {
  this->rows = 0;
  this->columns = 0;
}

void Tabuleiro::criaTabuleiro(int x, int y) {
  this->rows = x;
  this->columns = y;
  p = new char *[rows];
  for (int i = 0; i < rows; i++) {
    // cout << "-------";
    cout << '\n';
    p[i] = new char[columns];
    for (int j = 0; j < columns; j++) {
      p[i][j] = ' ';
      cout << '|' << p[i][j];
    }
    cout << '|';
    cout << '\n';
  }
  // cout << "-------";
  cout << '\n';
}

void Tabuleiro::atualizaTabuleiro(int x, int y, char z) {
  for (int i = 0; i < rows; i++) {
    // cout << "-------";
    cout << '\n';
    for (int j = 0; j < columns; j++) {
      p[x][y] = z;
      cout << '|' << p[i][j];
    }
    cout << '|';
    cout << '\n';
  }
  // cout << "-------";
  cout << '\n';
}

void Tabuleiro::liberaMemoria() {
  for (int i = 0; i < rows; i++) {
    delete[] p[i];
  }
  delete[] p;
}
