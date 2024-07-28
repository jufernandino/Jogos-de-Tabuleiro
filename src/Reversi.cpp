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
}

void Reversi::validaJogada(int x, int y, char z) {
  int linha = x;
  int coluna = y;
  
  bool posicaoVazia = false;
  bool encontrouAdversario = false;
  bool posicaoOcupadaJogadorAtual = false;
  
  if (x < this -> rows && y < this -> columns && p[x][y] == ' ') { //~ confere se a posição tá vazia, usando a lógica da Marcele
    posicaoVazia = true;
  }

  char corAdversario = (jogadorAtual == 'X') ? 'O' : 'X';

  const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

  for (auto &direcao : direcoes) {
    int dLinha = direcao[0];
    int dColuna = direcao[1];
    int linhaAtual = linha + dLinha; //atualiza as coordenadas com base na direção testada
    int colunaAtual = coluna + dColuna;

    while (linhaAtual >= 0 && linhaAtual < 8 && colunaAtual >= 0 && colunaAtual < 8) {
      if (p[linhaAtual][colunaAtual] == corAdversario) {
        encontrouAdversario = true;
      } else if (p[linhaAtual][colunaAtual] == jogadorAtual && encontrouAdversario) {
        posicaoOcupadaJogadorAtual = true; //se, na posição, encontrar uma peça do mesmo jogador e houver pelo menos uma peça adversária entre as duas peças, a jogada é válida
      } else {
        break;
      }
      linhaAtual += dLinha;
      colunaAtual += dColuna;
    }

  if ((posicaoVazia) ||(posicaoOcupadaJogadorAtual)) {
    p[x][y] = z;
    //~ encaixar inverterPecas aqui
  }
}
}

bool Reversi::verificarFimDeJogo() {
  return false;
}


//void Reversi::fazerMovimento(int linha, int coluna) {}

//void Reversi::verificarMovimentoValido(int linha, int coluna) { }

//void Reversi::mudarJogador() { }

//void Reversi::colocarPeca(int linha, int coluna) { }

//void Reversi::inverterPecas(int linha, int coluna) { }

//int Reversi::contarPecas(char cor) { }
