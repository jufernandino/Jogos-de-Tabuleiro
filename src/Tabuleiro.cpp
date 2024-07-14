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
  cout << "0  1  2" << endl;
  cout << "-------";
  for (int i = 0; i < rows; i++) {
    cout << '\n';
    p[i] = new char[columns];
    for (int j = 0; j < columns; j++) {
      p[i][j] = ' ';
      cout << '|' << p[i][j];
    }
    cout << '|' << ' ' << i;
    cout << '\n';
    cout << "-------";
  }
  cout << '\n';
}

void Tabuleiro::imprimeTabuleiro() {
  cout << "0  1  2" << endl;
  cout << "-------";
  for (int i = 0; i < rows; i++) {
    cout << '\n';
    for (int j = 0; j < columns; j++) {
      cout << '|' << p[i][j];
    }
    cout << '|' << ' ' << i;
    cout << '\n';
    cout << "-------";
  }
  cout << '\n';
}

void Tabuleiro::liberaMemoria() {
  for (int i = 0; i < rows; i++) {
    delete[] p[i];
  }
  delete[] p;
}
