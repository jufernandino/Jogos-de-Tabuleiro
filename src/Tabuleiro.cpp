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

void Tabuleiro::imprimeTabuleiro() {
  cout << '\n';
  string aux = "-";
  cout << "  ";
  for (int k = 0; k < this->columns; k++) {
    cout << k << "   ";
    aux += "----";
  }
  cout << '\n';
  cout << aux;
  for (int i = 0; i < rows; i++) {
    cout << '\n';
    for (int j = 0; j < columns; j++) {
      cout << '|' << ' ' << p[i][j] << ' ';
    }
    cout << '|' << ' ' << i;
    cout << '\n';
    cout << aux;
  }
  cout << '\n';
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
  } else {
    cout << "\nEssa jogada é invalida! Passa a vez!\n" << endl;
  }
}