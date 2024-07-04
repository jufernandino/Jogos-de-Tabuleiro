#include "Jogadores.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int Jogadores::pesquisaJogador(string Apelido) {

  ifstream in("Jogadores.txt", fstream::in);

  if (in.is_open()) {
    string line;
    while (getline(in, line)) {
      string aux = "";
      for (int i = 0; i < line.size(); i++) {
        if (line[i] != ',') {
          aux = aux + line[i];
        } else {
          break;
        }
      }
      if (aux == Apelido) {
        return 1;
      }
    }
  } else {
    cout << "O arquivo "
            "Jogadores.txt"
            " não pôde ser aberto."
         << endl;
    return 0;
  }

  in.close();
  return 0;
}

Jogadores::Jogadores(string Apelido, string Nome) {

  cout << "Digite seu nome completo:" << endl;
  while (getline(cin, Nome)) {
    if (Nome != "") {
      break;
    }
  }

  cout << "Digite seu nickname de preferência:" << endl;

  while (1) {
    cin >> Apelido;
    if (this->pesquisaJogador(Apelido)) {
      cout << "ERRO: jogador repetido" << endl;
      cout << "Por favor, tente novamente:" << endl;
      continue;
    } else {
      break;
    }
  }

  this->Apelido = Apelido;
  this->Nome = Nome;
}