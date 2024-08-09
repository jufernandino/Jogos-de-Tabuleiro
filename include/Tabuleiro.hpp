#ifndef Tabuleiro_H
#define Tabuleiro_H

#include <iostream>
#include <string>

using namespace std;

class Tabuleiro {
public:
  char **p;
  int rows;
  int columns;

  Tabuleiro();

  void criaTabuleiro(); //aloca uma matriz dinamicamente que servirá como tabuleiro

  virtual void imprimirTabuleiro(); //imrpime o tabuleiro com -s e |s

  virtual void validaJogada(int x, int y, char z); //confere se os valores inseridos são menores que as dimensôes do tabuleiro e efetua a jogada

  void liberaMemoria(); //libera a memória alocada anteriomente em criaTabuleiro()

  virtual int confereGanhador() = 0; //confere se alguém venceu

  void mostrarRegras(const char &jogoEscolhido);

};

#endif