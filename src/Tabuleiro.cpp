#include "Tabuleiro.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Tabuleiro::Tabuleiro() {
  this->rows = 0;
  this->columns = 0;
}

void Tabuleiro::criaTabuleiro()
{
  p = new char *[rows];
  for (int i = 0; i < rows; i++) {
    p[i] = new char[columns];
    for (int j = 0; j < columns; j++)
    {
      p[i][j] = ' ';
    }
  }
}

void Tabuleiro::imprimeTabuleiro() {
  cout << '\n';
  string aux = "-";
  cout << "  ";
  for (int k = 0; k < this->columns; k++) {
    cout << k << "   ";
    aux += "----";
  }
  cout << '\n';
  cout << aux;
  for (int i = 0; i < rows; i++) {
    cout << '\n';
    for (int j = 0; j < columns; j++) {
      cout << '|' << ' ' << p[i][j] << ' ';
    }
    cout << '|' << ' ' << i;
    cout << '\n';
    cout << aux;
  }
  cout << '\n';
}

void Tabuleiro::liberaMemoria()
{
  for (int i = 0; i < rows; i++)
  {
    delete[] p[i];
  }
  delete[] p;
}

void Tabuleiro::validaJogada(int x, int y, char z) {
  if (x < this->rows && y < this->columns && p[x][y] == ' ') {
    p[x][y] = z;
  } else {
    cout << "\nEssa jogada é invalida! Passa a vez!\n" << endl;
  }
}

void Tabuleiro::showRegras(const char &jogoEscolhido) {
  cout << "\nJ - JOGAR\n"
       << "LR - Ler regras do jogo\n" << endl;

  string lerRegras;
  cin >> lerRegras;

  if (lerRegras == "J") {
    cout << "\n--------\nJOGAR PARTIDA\n--------\n" << endl;
    return;
  } else if (lerRegras == "LR") {

    ifstream arquivo("Regras.txt");

    if (!arquivo.is_open()) {
      cout << "ERRO: não foi possível abrir o arquivo Regras.txt" << endl;
      return;
    }

    string linha, regras;
    
    bool continuar = false;
    
    string escolha(1, jogoEscolhido); //conversão string para char
    string aux = "(" + escolha + ")";

    while (getline(arquivo, linha)) {
      if (linha == aux) {
        continuar = true;
        continue;
    }
        if (linha.find('(') != string::npos && linha.find(')') != string::npos) {
          if (continuar) {
            break;
          }
        }

        if (continuar) {
          regras += linha + "\n";
        }
      }

    arquivo.close();

    if (!regras.empty()) {
      cout << "\n-------- \nREGRAS DO JOGO\n-------- \n" << regras << endl;

      cout << "Vamos começar? Tecle ENTER para iniciar o jogo" << endl;

      cin.ignore();
      cin.get();

      cout << "\n--------\nJOGAR PARTIDA\n--------" << endl;
    }
  }
}