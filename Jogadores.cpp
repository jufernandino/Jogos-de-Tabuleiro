#include "Jogadores.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

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
  this->winsReversi = 0;
  this->lossesReversi = 0;
  this->winsLig4 = 0;
  this->lossesLig4 = 0;

  ofstream in("Jogadores.txt", ios::app);
  in << '\n'
     << this->Apelido << ", " << this->Nome << ", " << this->winsReversi << ", "
     << this->lossesReversi << ", " << this->winsLig4 << ", "
     << this->lossesLig4 << ';';
}

void Jogadores::removeJogador(vector<Jogadores> &jogadoresVector) {
  vector<Jogadores>::iterator it;
  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
    if ((*it).Apelido == this->Apelido) {
      jogadoresVector.erase(it);
    }
  }

  ofstream out("Jogadores.txt", fstream::out);
  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
    if (out.is_open()) {
      cout << "foi" << endl;
      out << (*it).Apelido << ", " << (*it).Nome << ", " << (*it).winsReversi
          << ", " << (*it).lossesReversi << ", " << (*it).winsLig4 << ", "
          << (*it).lossesLig4 << ';';
    } else {
      cout << "O arquivo "
              "Jogadores.txt"
              " não pôde ser aberto."
           << endl;
      return;
    }
  }
}