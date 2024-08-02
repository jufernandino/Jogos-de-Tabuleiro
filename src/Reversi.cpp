#include "Reversi.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

Reversi::Reversi()
{
  this->rows = 8;
  this->columns = 8;
}

// void Reversi::inicializarJogo(int linha, int coluna) {
void Reversi::inicializarJogo()
{
  p[3][3] = 'X';
  p[4][4] = 'X';
  p[3][4] = 'O';
  p[4][3] = 'O';

  jogadorAtual = 'X';
}
// Função para avaliar se a jogada é valida
bool Reversi::ehJogadaValida(int x, int y, char jogadorDaVez)
{
  // confere se a posição tá dentro do escopo do tabuleiro e tá vazia
  if (x < 0 || x >= rows || y < 0 || y >= columns || p[x][y] != ' ')
  {
    return false;
  }

  char corAdversario = (jogadorDaVez == 'X') ? 'O' : 'X';
  const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

  for (int i = 0; i < 8; ++i)
  {
    int MovimentoLinha = direcoes[i][0];
    int MovimentoColuna = direcoes[i][1];
    int linhaAtual = x + MovimentoLinha;
    int colunaAtual = y + MovimentoColuna;
    bool encontrouAdversario = false;

    while (linhaAtual >= 0 && linhaAtual < rows && colunaAtual >= 0 && colunaAtual < columns)
    {
      if (p[linhaAtual][colunaAtual] == corAdversario)
      {
        encontrouAdversario = true;
      }
      else if (p[linhaAtual][colunaAtual] == jogadorDaVez && encontrouAdversario == true)
      {
        return true;
      }
      else
      {
        break;
      }
      linhaAtual = linhaAtual + MovimentoLinha;
      colunaAtual = colunaAtual + MovimentoColuna;
    }
  }
  return false;
}

void Reversi::mostrarLocaisJogada(char jogadorDaVez)
{
  cout << "Locais para jogadas possíveis:";
  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      if (p[i][j] == ' ' && ehJogadaValida(i, j, jogadorDaVez))
      {
        // Mostra a posição possível (aqui usamos um formato simples, você pode melhorar a visualização)
        cout << "(" << i << "," << j << ") ";
      }
    }
  }
  cout << endl;
}

void Reversi::validaJogada(int x, int y, char jogadorDaVez)
{
  if (!ehJogadaValida(x, y, jogadorDaVez))
  {
    cout << "Jogada inválida. Tente novamente." << endl;
    return;
  }

  p[x][y] = jogadorDaVez;
  inverterPecas(x, y, jogadorDaVez);
}

// se há pelo menos um 0 entre dois X, a jogada é válida
// conferir se posição está vazia
// primeiro achar se há uma peça BRANCA adjacente a peça do jogador atual PRETA, guardar essa info
// se tiver, jogada é válida, peça PRETA pode ser colocada ao lado da BRANCA
// checar se a entrada do jogador bate com a entrada disponível
// se escolher a disponível, coloca a peça PRETA e inverte as BRANCAS entre as peças PRETAS
// se não houver jogadas disponíveis, passa a vez

void Reversi::inverterPecas(int x, int y, char jogadorDaVez)
{
  char corAdversario = (jogadorDaVez == 'X') ? 'O' : 'X';
  const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

  for (int i = 0; i < 8; ++i)
  {
    int MovimentoLinha = direcoes[i][0];
    int MovimentoColuna = direcoes[i][1];
    int linhaAtual = x + MovimentoLinha;
    int colunaAtual = y + MovimentoColuna;
    bool encontrouAdversario = false;
    vector<pair<int, int>> pecasParaInverter;

    while (linhaAtual >= 0 && linhaAtual < rows && colunaAtual >= 0 && colunaAtual < columns)
    {
      if (p[linhaAtual][colunaAtual] == corAdversario)
      {
        pecasParaInverter.push_back({linhaAtual, colunaAtual});
      }
      else if (p[linhaAtual][colunaAtual] == jogadorDaVez)
      {
        for (auto &peca : pecasParaInverter)
        {
          p[peca.first][peca.second] = jogadorDaVez;
        }
        break;
      }
      else
      {
        break;
      }
      linhaAtual += MovimentoLinha;
      colunaAtual += MovimentoColuna;
    }
  }
}

bool Reversi::verificarFimDeJogo()
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < columns; ++j)
    {
      if (p[i][j] == ' ' && (ehJogadaValida(i, j, 'X') || ehJogadaValida(i, j, 'O')))
      {
        return false;
      }
    }
  }
  return true;
}

int Reversi::confereGanhador()
{
  int ContadorX = 0;
  int ContadorO = 0;

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < columns; ++j)
    {
      if (p[i][j] == 'X')
      {
        ++ContadorX;
      }
      else if (p[i][j] == 'O')
      {
        ++ContadorO;
      }
    }
  }

  if (ContadorX > ContadorO)
  {
    return 1; // Jogador1 X ganhou
  }
  else if (ContadorO > ContadorX)
  {
    return 2; // Jogador2 O ganhou
  }
  else
  {
    return 3; // Empate
  }
}
// void Reversi::fazerMovimento(int linha, int coluna) {}

// void Reversi::verificarMovimentoValido(int linha, int coluna) { }

// void Reversi::mudarJogador() { }

// void Reversi::colocarPeca(int linha, int coluna) { }

// void Reversi::inverterPecas(int linha, int coluna) { }

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
