#include "Reversi.hpp"
#include <iomanip>
#include <iostream>
#include <string>

Reversi::Reversi() {
  this -> rows = 8;
  this -> columns = 8;
}

int Reversi::confereGanhador() {
  return 0;
}

void Reversi::inicializarJogo(int linha, int coluna) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (linha == 3 && coluna == 3) {
      p[linha][coluna] = 'X';
      } else if (linha == 4 && coluna == 4) {
        p[linha][coluna] = 'X';
      } else if (linha == 3 && coluna == 4) {
        p[linha][coluna] = 'O';
      } else if (linha == 4 && coluna == 3) {
        p[linha][coluna] = 'O';
      }
    }
  }
  jogadorAtual = 'X';
}

void Reversi::validaJogada(int x, int y, char z) {
  char jogadorDaVez = z;
  
  bool posicaoVazia = false;
  
  if (x < 0 || x >= this -> rows || y < 0 || y >= this -> columns || p[x][y] != ' ') { //confere se a posição tá dentro do escopo do tabuleiro e tá vazia
    cout << "Essa posição não está vazia. Tente novamente" << endl;
    posicaoVazia = true;
    return;
  }

  //char corAdversario = ((jogadorDaVez == 'X') ? 'O' : 'X');
  char corAdversario = ((jogadorDaVez == 'X') ? 'X' : '0');

  const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

  for (auto &direcao : direcoes) {
    int dLinha = direcao[0];
    int dColuna = direcao[1];
    int linhaAtual = x + dLinha; //atualiza as coordenadas com base na direção testada
    int colunaAtual = y + dColuna;
    bool encontrouAdversario = false;

  bool posicaoOcupadaJogadorAtual = false;
    while (linhaAtual >= 0 && linhaAtual < this -> rows && colunaAtual >= 0 && colunaAtual < this -> columns) {
      if (p[linhaAtual][colunaAtual] == corAdversario) {
        encontrouAdversario = true;
      } else if (p[linhaAtual][colunaAtual] == jogadorDaVez && encontrouAdversario) {
        posicaoOcupadaJogadorAtual = true; //se, na posição, encontrar uma peça do mesmo jogador e houver pelo menos uma peça adversária entre as duas peças, a jogada é válida
      } else {
        break;
      }
      linhaAtual += dLinha;
      colunaAtual += dColuna;
    }
  if (posicaoOcupadaJogadorAtual) {
    break;
  }
    
  if ((posicaoVazia) && (posicaoOcupadaJogadorAtual)) {
    p[x][y] = jogadorDaVez;
    //encaixar inverterPecas aqui
  } else {
    cout << "Jogada inválida. Tente novamente." << endl;
    break;
  }
}  
}

bool Reversi::verificarFimDeJogo() {
  return true;
}


//void Reversi::fazerMovimento(int linha, int coluna) {}

//void Reversi::verificarMovimentoValido(int linha, int coluna) { }

//void Reversi::mudarJogador() { }

//void Reversi::colocarPeca(int linha, int coluna) { }

//void Reversi::inverterPecas(int linha, int coluna) { }

/* int Reversi::contarPecas(int x, int y) { 
int contadorX = 0;
int contadorY = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (p[x][y] == 'X') {
                contadorX++;
            } else if (p[x][y] == 'O') {
            contadorY++;
            }
        }
    }
} */
