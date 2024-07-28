#include "lig4.hpp"
#include <iomanip>
#include <iostream>
#include <string>

lig4::lig4() {
  this->rows = 6;
  this->columns = 7;
}

void lig4::validaJogada(int x, int y, char z) {
  if (y < this->columns) {
    for (int i = 5; i >= 0; i--) {
      if (p[i][y] == ' ') {
        p[i][y] = z;
        break;
      } else {
        continue;
      }
    }
  } else {
    cout << "\nEssa jogada é invalida! Passa a vez!\n" << endl;
  }
}

int lig4::confereGanhador() {
  // Verifica linhas horizontais
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns - 3; j++) {
      if (p[i][j] == p[i][j + 1] && p[i][j] == p[i][j + 2] &&
          p[i][j] == p[i][j + 3] && p[i][j] != ' ') {
        if (p[i][j] == 'X') { // caso o Jogador1 vença
          return 1;
        }
        if (p[i][j] == 'O') { // caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  // Verifica linhas verticais
  for (int i = 0; i < rows - 3; i++) {
    for (int j = 0; j < columns; j++) {
      if (p[i][j] == p[i + 1][j] && p[i][j] == p[i + 2][j] &&
          p[i][j] == p[i + 3][j] && p[i][j] != ' ') {
        if (p[i][j] == 'X') { // caso o Jogador1 vença
          return 1;
        }
        if (p[i][j] == 'O') { // caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  // Verifica diagonais descendentes (\)
  for (int i = 0; i < rows - 3; i++) {
    for (int j = 0; j < columns - 3; j++) {
      if (p[i][j] == p[i + 1][j + 1] && p[i][j] == p[i + 2][j + 2] &&
          p[i][j] == p[i + 3][j + 3] && p[i][j] != ' ') {
        if (p[i][j] == 'X') { // caso o Jogador1 vença
          return 1;
        }
        if (p[i][j] == 'O') { // caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  // Verifica diagonais ascendentes (/)
  for (int i = 3; i < rows; i++) {
    for (int j = 0; j < columns - 3; j++) {
      if (p[i][j] == p[i - 1][j + 1] && p[i][j] == p[i - 2][j + 2] &&
          p[i][j] == p[i - 3][j + 3] && p[i][j] != ' ') {
        if (p[i][j] == 'X') { // caso o Jogador1 vença
          return 1;
        }
        if (p[i][j] == 'O') { // caso o Jogador2 vença
          return 2;
        }
      }
    }
  }

  // Verifica se há empate
  bool empate = true;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (p[i][j] == ' ') {
        empate = false;
        break;
      }
    }
    if (!empate) {
      break;
    }
  }

  if (empate) {
    return 3;
  }

  return 0;
}