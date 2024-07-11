#include "Jogadores.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void clear_screen() {
  #ifdef __linux__
    system("clear");
  #elif __windows__
    system("cls");
  #else

  #endif
}

void to_lower(string &s) {
  int len = s.size();
  for (int i = 0; i < len; i++) {
    s[i] = tolower(s[i]);
  }
}

void showJogadores() {

  ifstream in("Jogadores.txt", fstream::in);

  if (in.is_open()) {
    string line;
    while (getline(in, line)) {
      cout << line << endl;
    }
  } else {
    cout << "O arquivo "
            "Jogadores.txt"
            " não pôde ser aberto."
         << endl;
    return;
  }

  in.close();
}

void loadJogadores (vector<Jogadores> &jogadoresVector) {

  ifstream in("Jogadores.txt", fstream::in);

  if (in.is_open()) {
    string line;
    while (getline(in, line)) {

      Jogadores jogador;
      string aux = "";
      long unsigned int i = 0;

      for (; i < line.size(); i++) {
        if (line[i] != ',') {
          aux = aux + line[i];
        } else {
          break;
        }
      }
      jogador.Apelido = aux;
      aux = "";
      i += 2;

      for (; i < line.size(); i++) {
        if (line[i] != ',') {
          aux = aux + line[i];
        } else {
          break;
        }
      }
      jogador.Nome = aux;
      aux = "";
      i += 2;

      for (; i < line.size(); i++) {
        if (line[i] != ',') {
          aux = aux + line[i];
        } else {
          break;
        }
      }
      jogador.reversisWins = stoi(aux, nullptr, 10);
      aux = "";
      i += 2;

      for (; i < line.size(); i++) {
        if (line[i] != ',') {
          aux = aux + line[i];
        } else {
          break;
        }
      }
      jogador.reversisDefeats = stoi(aux, nullptr, 10);
      aux = "";
      i += 2;

      for (; i < line.size(); i++) {
        if (line[i] != ',') {
          aux = aux + line[i];
        } else {
          break;
        }
      }
      jogador.lig4sWins = stoi(aux, nullptr, 10);
      aux = "";
      i += 2;

      for (; i < line.size(); i++) {
        if (line[i] != ';') {
          aux = aux + line[i];
        } else {
          break;
        }
      }
      jogador.lig4sDefeats = stoi(aux, nullptr, 10);
      aux = "";

      jogadoresVector.push_back(jogador);
    }
  } else {
    cout << "O arquivo "
            "Jogadores.txt"
            " não pôde ser aberto."
         << endl;
    return;
  }

  in.close();
}

int main() {

    vector <Jogadores> jogadoresVector;

    loadJogadores(jogadoresVector);

    Jogadores Jogador1, Jogador2;

    char d;
    while (1) {
      cout << "\nOlá! Vamos jogar? =) \n\nDê enter para continuar." << endl;
      getchar();

      clear_screen();
      
      cout << "PRIMEIRO JOGADOR" << endl;
      cout << "\nVocê deseja "
              "sign in (1)"
              " ou "
              "sing up (2)"
              "?"
           << endl;
      int x;
      cin >> x;
      cin.ignore();

      if (x == 1) {
        Jogadores jogador;
        string str;
        cout << "\nInsira seu nickname:" << endl;
        cin >> str;
        if (jogador.pesquisaJogador(str)) {
          jogador.signIn(str, jogadoresVector);
          Jogador1 = jogador;
          break;
        } else {
          cout << "Esse jogador não existe. Tente novamente. Caso queira voltar para o menu, tecle 0." << endl; //validação do arquivo não está dando certo
          cin >> d;
          if(d == 0){
            continue;
            clear_screen();
          }
        }
      }

      if (x == 2) {
        string str;
        Jogadores jogador(str);
        jogadoresVector.push_back(jogador);
        Jogador1 = jogador;
        break;
      }
    }

  clear_screen();

    while (1) {
      cout << "SEGUNDO JOGADOR" << endl;
      cout << "\nVocê deseja "
              "sign in (1)"
              " ou "
              "sing up (2)"
              "?"
           << endl;
      int x;
      cin >> x;

      if (x == 1) {
        Jogadores jogador;
        string str;
        cout << "\nInsira seu nickname:" << endl;
        cin >> str;
        if (str == Jogador1.Apelido) {
          cout << "Esse jogador já foi escolhido. Tente novamente." << endl;
          continue;
        }
        if (jogador.pesquisaJogador(str) && str != Jogador1.Apelido) {
          jogador.signIn(str, jogadoresVector);
          Jogador2 = jogador;
          break;
        } else {
          cout << "Esse jogador não existe. Tente novamente." << endl;
        }
      }

      if (x == 2) {
        string str;
        Jogadores jogador(str);
        jogadoresVector.push_back(jogador);
        Jogador2 = jogador;
        break;
      }
    }

  clear_screen();
  
    int gameMode = 0;
    cout << "Qual jogo gostariam de jogar? \n\nReversi (1) \nLig4 (2) \nTicTacToe (3)" << endl;
    cin >> gameMode;

  if (gameMode == 1) {
    cout << "\nReversi foi escolhido." << endl;
  } else if (gameMode == 2) {
    cout << "\nLig4 foi escolhido." << endl;
  } else if (gameMode == 3) {
    cout << "\nTicTacToe foi escolhido." << endl;
  } else {
    cout << "\nOpção inválida. Tente novamente." << endl;
  }

  cout << "\nUhuuuullllll\nTudo funcionando certinho <3" << endl;

  // falta a validação de quando um jogador ganha

  return 0;
}