#include "Jogadores.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

void loadJogadores(vector<Jogadores> &jogadoresVector) {

  ifstream in("Jogadores.txt", fstream::in);

  if (in.is_open()) {
    string line;
    while (getline(in, line)) {

      Jogadores jogador;
      string aux = "";
      int i = 0;

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

  cout << "Teste" << endl;

  /*

    vector<Jogadores> jogadoresVector;

    loadJogadores(jogadoresVector);

    Jogadores Jogador1, Jogador2;

    while (1) {
      cout << "primeiro while" << endl;
      cout << "Você deseja "
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
        cout << "Insira seu nickname:" << endl;
        cin >> str;
        if (jogador.pesquisaJogador(str)) {
          jogador.signIn(str, jogadoresVector);
          Jogador1 = jogador;
          break;
        } else {
          cout << "Esse jogador não existe. Tente novamente." << endl;
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

    while (1) {
      cout << "segundo while" << endl;
      cout << "Você deseja "
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
        cout << "Insira seu nickname:" << endl;
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

    int gameMode = 0;
    cout << "Que jogo gostariam de jogar?, Reversi (1) ou Lig4 (2)?" << endl;
    cin >> gameMode;

    switch (gameMode) {
    case 1:
      cout << "Reversi foi escolhido." << endl;
      break;
    case 2:
      cout << "Lig4 foi escolhido." << endl;
      break;
    }

    /*
    if(gameMode == 1) {
      cout << "Reversi foi escolhido." << endl;
    }
    if(gameMode == 2){
      cout << "Lig4 foi escolhido." << endl;
    }
    */

  // falta a validação de quando um jogador ganha

  return 0;
}