#include "Reversi.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

Reversi::Reversi() {
  this -> rows = 8;
  this -> columns = 8;
}

int Reversi::confereGanhador() {
  int contadorX = 0;
  int contadorO = 0;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (p[i][j] == 'X') {
        contadorX++;
      } else if (p[i][j] == 'O') {
        contadorO++;
      }
    }
  }

    if(contadorX > contadorO) {
      return 1; //jogador 1 ganhou
    } else if (contadorO > contadorX) {
      return 2; //jogador 2 ganhou
    } else if (contadorX == contadorO) {
      return 3; //empate
    }

  return 0;
}

void Reversi::inicializarJogo() {
    p[3][3] = 'X';
    p[4][4] = 'X';
    p[3][4] = 'O';
    p[4][3] = 'O';

    jogadorAtual = 'X';
}

//função para avaliar se a jogada é possível
bool Reversi::ehJogadaValida(int x, int y, char jogadorDaVez) {

  // confere se a posição tá dentro do escopo do tabuleiro e tá vazia
  if (x < 0 || x >= rows || y < 0 || y >= columns || p[x][y] != ' ') {
    return false;
  }

  char corAdversario = ((jogadorDaVez == 'X') ? 'O' : 'X');

  const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

  for (int i = 0; i < 8; ++i) {
    int MoveLinha = direcoes[i][0];
    int MoveColuna = direcoes[i][1];
    int linhaAtual = x + MoveLinha;
    int colunaAtual = y + MoveColuna;
    bool encontrouAdversario = false;

    while (linhaAtual >= 0 && linhaAtual < rows && colunaAtual >= 0 && colunaAtual < columns) {
      if (p[linhaAtual][colunaAtual] == corAdversario) {
        encontrouAdversario = true;
      } else if (p[linhaAtual][colunaAtual] == jogadorDaVez && encontrouAdversario == true) {
        return true;
      } else {
        break;
      }
      linhaAtual = linhaAtual + MoveLinha;
      colunaAtual = colunaAtual + MoveColuna;
    }
  }
  return false;
}


//função para mostrar ao jogador da vez quais possíveis casas ele pode escolher
void Reversi::mostrarLocaisJogada(char jogadorDaVez) {
  cout << "Coordenadas para jogadas possíveis: ";
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (p[i][j] == ' ' && ehJogadaValida(i, j, jogadorDaVez)) {
        // Mostra a posição possível
        cout << "(" << i << "," << j << ") ";
      }
    }
  }
  cout << endl;
}

//se a jogada é valida (ehJogadaValida = verdadeiro), valida a jogada, coloca a peça no local e inverte as outras
void Reversi::validaJogada(int x, int y, char jogadorDaVez) {
  if (!ehJogadaValida(x, y, jogadorDaVez)) {
    cout << "ERRO: jogada inválida" << endl;
    return;
  }

  p[x][y] = jogadorDaVez;
  inverterPecas(x, y, jogadorDaVez);
}

void Reversi::inverterPecas(int x, int y, char jogadorDaVez) {
  char corAdversario = (jogadorDaVez == 'X') ? 'O' : 'X';
  const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

  for (int i = 0; i < 8; ++i) {
    int MoveLinha = direcoes[i][0];
    int MoveColuna = direcoes[i][1];
    int linhaAtual = x + MoveLinha;
    int colunaAtual = y + MoveColuna;

    //bool encontrouAdversario = false;

    //salva as posições que vão ser invertidas
    vector<pair<int, int>> pecasParaInverter;

    while (linhaAtual >= 0 && linhaAtual < rows && colunaAtual >= 0 && colunaAtual < columns) {
      if (p[linhaAtual][colunaAtual] == corAdversario) { //se for uma peça adversária
        // Adicionar ao vetor de posições a posição atual
        pecasParaInverter.push_back({linhaAtual, colunaAtual});
      } else if (p[linhaAtual][colunaAtual] == jogadorDaVez) { // Ao chegar na extremidada, em que volta a se a peça do jogador da vez
        //percorre todas as posições do vetor
        for (auto &peca : pecasParaInverter) {
          p[peca.first][peca.second] = jogadorDaVez; // Altera a cor
        }
        break;
      } else {
        break;
      }
      linhaAtual = linhaAtual + MoveLinha;
      colunaAtual = colunaAtual + MoveColuna;
    }
  }
}

bool Reversi::verificarFimDeJogo() {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (p[i][j] == ' ' && (ehJogadaValida(i, j, 'X') || ehJogadaValida(i, j, 'O'))) {
        return false;
      }
    }
  }
  return true;
}
