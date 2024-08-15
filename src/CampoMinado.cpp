/*
#include "CampoMinado.hpp"
#include <iostream>
#include <cstdlib>

CampoMinado::CampoMinado() {
  this->rows = 7;
  this->columns = 7;
  this->bombas = 10;

  iniciaTabuleiro();
}

void iniciaTabuleiro() {
  //inicia todo o tabuleiro com +
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < columns; ++j){
      matrix[i][j] = '+';
    }
  }

  //cria um vetor que guarda as coordenadas das minas
  srand(time(0));
  for(int i = 0; i < this->bombas; ++i){
      this->posicao_minas[0][i] = rand() % this->rows;
      this->posicao_minas[1][i] = rand() % this->columns;
  }
}

int CampoMinado::minasAdj(int linha, int coluna) {
  int bombas_adj = 0;

    for(int x = -1 ; x <= 1; ++x){
      for(int y = -1 ; y <= 1; ++y){
        
        for(int iterador = 0; iterador < this->bombas; ++iterador){
          if(linha+x == posicao_minas[0][iterador] && coluna+y == posicao_minas[1][iterador])
            bombas_adj++;
        }
      }
    }

  return bombas_adj;
}

void CampoMinado::revelaCelula(int linha, int coluna) {
  int minas_adj = minasAdj(linha, coluna);

  if(validaJogada(linha, coluna)){
    return;
  }
  
  if(minas_adj > 0){
    matrix[linha][coluna] = '0' + bombas_adj;
  }
  else{ //se nao tem bomba adjacente, marca com espaco em branco e revela as celulas adjacentes
    matrix[linha][coluna] = ' ';

    for(int x= -1; x <= 1 ; ++x){
      for(int y = -1; y <= 1 ; ++y){
        revelaCelula(linha+x, coluna+y);   
      }
    }
  }
}

bool CampoMinado::validaJogada(int linha, int coluna){
  if (linha < 0 || linha >= rows || coluna < 0 || coluna >= columns || matrix[linha][coluna]!='+'){
    return false;
  }
  else{
    return true;
  }
}

bool CampoMinado::escolheuBomba(int linha, int coluna) {
  for(int i = 0; i < this->bombas; ++i){
    if(linha == posicao_minas[0][i] && coluna == posicao_minas[1][i])
      return true;
  }
  return false;
}

int CampoMinado::confereGanhador(){
  int faltou = 0;
  
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < columns; ++j){
      if(matrix[i][j] == '+'){
        faltou++;
      }
    }
  }

  if(faltou != 0){
    return 0;
  
  } else if(faltou == 0) {
    return 1;
  }
}

void CampoMinado::jogarCampoMinado()
{

  imprimirTabuleiro();  

  cout<<"Escreva as coordenadas no formato: linha coluna" << endl;
  
  int chute_linha, chute_coluna;

  do{
  cin>> chute_linha >> chute_coluna;

  if(!validaJogada(chute_linha, chute_coluna)){
    cout << "ERRO: jogada inválida" << endl;
    break;
  }

  if(escolheuBomba(chute_linha, chute_coluna)){
    cout << "BOOM! Você perdeu!" << endl;
    return;
  }
    
  if(confereGanhador()){
    cout<< "Parabéns! Você ganhou!" << endl;
    return;
  }

  minasAdj();
  revelaCelula();

  } while(1);
}
*/