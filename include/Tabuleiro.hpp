#ifndef Tabuleiro_H
#define Tabuleiro_H
#include <iostream>
#include <string>

using namespace std;

class Tabuleiro
{
public:
  char **p;
  int rows;
  int columns;

  Tabuleiro();

  void criaTabuleiro();

  void imprimeTabuleiro();

  void liberaMemoria();

  char getPosicao(int linha, int coluna);            // Retorna qual a peça na posição especificada
  void setPosicao(int linha, int coluna, char peca); // Define uma peça para a posição especificada
};

#endif