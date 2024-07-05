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

  string line;
  vector<string> lines;

  if (in.is_open()) {
    while (getline(in, line, ';')) {
      lines.push_back(line);
    }
  } else {
    cout << "O arquivo "
            "Jogadores.txt"
            " não pôde ser aberto."
         << endl;
    return;
  }
  
  in.close();

  vector<string>::iterator it_v;
  for (it_v = lines.begin(); it_v != lines.end(); it_v++) {
    cout << *it_v;
  }
  
  vector<Jogadores>::iterator it_J;
  for (it_J = jogadoresVector.begin(); it_J != jogadoresVector.end(); it_J++) {
    cout << (*it_J).Apelido;
  }
  
}

int main() {

  //vector<Jogadores> jogadoresVector;
  //loadJogadores(jogadoresVector);
  // vector<Jogadores>::iterator it;
  // for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
  //   cout << (*it).Apelido << ' ' << (*it).Nome << endl;
  // }

  /*
  string str1, str2;

  Jogadores jogador1(str1, str2);

  jogadoresVector.push_back(jogador1);

  Jogadores jogador2(str1, str2);

  jogadoresVector.push_back(jogador2);

  Jogadores jogador3(str1, str2);

  jogadoresVector.push_back(jogador3);

  //jogador2.removeJogador(jogadoresVector);

  */

  /*
  int i = 1;
  while(i != 3){

    string str;
    cout << "Você deseja ""sign in"" ou ""sing up""?" << endl;
    cin >> str;
    to_lower(str);

    switch (str){
      case 'sign up':

        string str1, str2;

        Jogadores jogador(str1, str2);

        jogadoresVector.push_back(jogador);

        cout << jogador.Apelido << ' ' << jogador.Nome << endl;

        break;

      case 'sign in':



      break;

      default:

    }
    i++;
  }
  */

  // showJogadores();
}