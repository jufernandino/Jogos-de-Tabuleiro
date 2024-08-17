#include "CampoMinado.hpp"
#include <iostream>
#include <cstdlib>

CampoMinado::CampoMinado()
{
  this->rows = 7;
  this->columns = 7;
  this->bombas = 10;
}

void CampoMinado::iniciaTabuleiro()
{
  // inicia todo o tabuleiro com +
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < columns; ++j)
    {
      matrix[i][j] = '+';
    }
  }

  // cria um vetor que guarda as coordenadas das minas
  srand(time(0));
  for (int i = 0; i < 10; ++i)
  {
    this->posicao_minas[0][i] = rand() % this->rows;
    this->posicao_minas[1][i] = rand() % this->columns;
  }
}

int CampoMinado::minasAdj(int linha, int coluna)
{
  int bombas_adj = 0;

  for (int x = -1; x <= 1; ++x)
  {
    for (int y = -1; y <= 1; ++y)
    {

      for (int iterador = 0; iterador < this->bombas; ++iterador)
      {
        if (linha + x == posicao_minas[0][iterador] && coluna + y == posicao_minas[1][iterador])
          bombas_adj++;
      }
    }
  }

  return bombas_adj;
}

void CampoMinado::revelaCelula(int linha, int coluna)
{
  int minas_adj = minasAdj(linha, coluna);

  if (!validaJogadaCampoMinado(linha, coluna))
  {
    return;
  }

  if (minas_adj > 0)
  {
    matrix[linha][coluna] = '0' + minas_adj;
  }
  else
  { // se nao tem bomba adjacente, marca com espaco em branco e revela as celulas adjacentes
    matrix[linha][coluna] = ' ';

    for (int x = -1; x <= 1; ++x)
    {
      for (int y = -1; y <= 1; ++y)
      {
        revelaCelula(linha + x, coluna + y);
      }
    }
  }
}

bool CampoMinado::validaJogadaCampoMinado(int linha, int coluna)
{
  if (linha < 0 || linha >= rows || coluna < 0 || coluna >= columns || matrix[linha][coluna] != '+')
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool CampoMinado::escolheuBomba(int linha, int coluna)
{
  for (int i = 0; i < this->bombas; ++i)
  {
    if (linha == posicao_minas[0][i] && coluna == posicao_minas[1][i])
      return true;
  }
  return false;
}

int CampoMinado::confereGanhador()
{
  int faltou = 0;

  for (int coordX = 0; coordX < rows; ++coordX)
  {
    for (int coordY = 0; coordY < columns; ++coordY)
    {
      for (int iterador = 0; iterador < 10; ++iterador)
      {
        if (matrix[coordX][coordY] == '+' && !(posicao_minas[0][iterador] == coordX && posicao_minas[1][iterador] == coordY))
        {
          faltou++;
        }
      }
    }
  }

  if (faltou != 0)
  {
    return 0;
  }
  else if (faltou == 0)
  {
    return 1;
  }
}

int CampoMinado::jogarCampoMinado()
{
  iniciaTabuleiro();
  imprimirTabuleiro();

  while (1)
  {
    cout << "Escreva as coordenadas no formato: linha coluna" << endl;

    int chute_linha, chute_coluna;
    cin >> chute_linha >> chute_coluna;

    if (!validaJogadaCampoMinado(chute_linha, chute_coluna))
    {
      cout << "ERRO: jogada inválida" << endl;
    }

    if (escolheuBomba(chute_linha, chute_coluna))
    {
      cout << "BOOM! Você perdeu!" << endl;
      return 0;
    }

    if (confereGanhador())
    {
      cout << "Parabéns! Você ganhou!" << endl;
      return 1;
    }

    minasAdj(chute_linha, chute_coluna);
    revelaCelula(chute_linha, chute_coluna);
    imprimirTabuleiro();
  }
}
