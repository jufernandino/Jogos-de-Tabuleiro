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

  vector<Jogadores> jogadoresVector;

  loadJogadores(jogadoresVector);

  /*
  string str;

  Jogadores jogador1(str);

  jogadoresVector.push_back(jogador1);

  Jogadores jogador2(str);

  jogadoresVector.push_back(jogador2);

  Jogadores jogador3(str);

  jogadoresVector.push_back(jogador3);

  jogador2.removeJogador(jogadoresVector);

  // show Jogadores();
  */

  /*
  vector<Jogadores>::iterator it;

  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
    cout << (*it).Apelido << ", " << (*it).Nome << ", " << (*it).reversisWins
         << ", " << (*it).reversisDefeats << ", " << (*it).lig4sWins << ", "
         << (*it).lig4sDefeats << endl;
  }
  */

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

  /*
  cout << Jogador1.Apelido << ", " << Jogador1.Nome << ", "
       << Jogador1.reversisWins << ", " << Jogador1.reversisDefeats << ", "
       << Jogador1.lig4sWins << ", " << Jogador1.lig4sDefeats << endl;

  cout << Jogador2.Apelido << ", " << Jogador2.Nome << ", "
       << Jogador2.reversisWins << ", " << Jogador2.reversisDefeats << ", "
       << Jogador2.lig4sWins << ", " << Jogador2.lig4sDefeats << endl;
  */

  /*
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
  */
  
  /*
  int gameMode = 1;
  Jogador1.victory = true;
  Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
  */
  
  /*
  if(gameMode == 1) {
    cout << "Reversi foi escolhido." << endl;
  }
  if(gameMode == 2){
    cout << "Lig4 foi escolhido." << endl;
  }
  */
  return 0;
}