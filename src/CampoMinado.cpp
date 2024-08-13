#include "CampoMinado.hpp"
#include <iostream>
#include <cstdlib>

CampoMinado::CampoMinado()
{
  this->rows = 7;
  this->columns = 7;
  this->bombas = 10;

  for(int coloca_bomba = 0; coloca_bomba < bombas; ++coloca_bomba){
    matrix[rand() % rows][rand() % columns] = 'b';
  }
}

void CampoMinado::jogarCampoMinado()
{

  int chute_linha, chute_coluna;

  do{
  cin>> chute_linha >> chute_coluna;

  if(!validaJogada(chute_linha, chute_coluna)){
    break;
  }

  if(matrix[chute_linha][chute_coluna] == 'b'){
    cout << "BOOM! Você perdeu!" << endl;
    return;
  }

  if(matrix[chute_linha][chute_coluna] == ' '){
      matrix[chute_linha][chute_coluna] = 'X';
  }

  if(confereGanhador()){
    cout<< "Parabéns! Você ganhou!" << endl;
    return;
  }
    
  } while(1);
}

int CampoMinado::confereGanhador(){
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < columns; ++j){
      if(matrix[i][j] == ' '){
        return 0;
      }
    }
  }

  return 1;
}

bool CampoMinado::validaJogada(int x, int y)
{
  if (x < 0 || x >= rows || y < 0 || y >= columns || matrix[x][y]=='x'){
    cout << "ERRO: jogada inválida" << endl;
    return false;
  }
  else{
    return true;
  }
}

