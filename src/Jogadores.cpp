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

Jogadores::Jogadores() {
  this->Apelido = "";
  this->Nome = "";
  this->reversisWins = 0;
  this->reversisDefeats = 0;
  this->lig4sWins = 0;
  this->lig4sDefeats = 0;
  this->victory = false;
}

Jogadores::Jogadores(string Apelido) {

  string Nome;
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
  this->reversisWins = 0;
  this->reversisDefeats = 0;
  this->lig4sWins = 0;
  this->lig4sDefeats = 0;
  this->victory = false;

  ofstream out("Jogadores.txt", fstream::app);

  if (out.is_open()) {
    out << '\n'
        << this->Apelido << ", " << this->Nome << ", " << this->reversisWins
        << ", " << this->reversisDefeats << ", " << this->lig4sWins << ", "
        << this->lig4sDefeats;
  } else {
    cout << "O arquivo "
            "Jogadores.txt"
            " não pôde ser aberto."
         << endl;
    return;
  }

  out.close();

  cout << "Novo jogador criado com sucesso." << endl;
}

void Jogadores::signIn(string Apelido, vector<Jogadores> &jogadoresVector) {

  vector<Jogadores>::iterator it;
  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
    if ((*it).Apelido == Apelido) {
      this->Apelido = (*it).Apelido;
      this->Nome = (*it).Nome;
      this->reversisWins = (*it).reversisWins;
      this->reversisDefeats = (*it).reversisDefeats;
      this->lig4sWins = (*it).lig4sWins;
      this->lig4sDefeats = (*it).lig4sDefeats;
    }
  }
  return;
}

void Jogadores::reescreveArquivo(vector<Jogadores> &jogadoresVector) {
  ofstream out("Jogadores.txt", fstream::out);
  out << "";
  out.close();

  out.open("Jogadores.txt", ios::app);

  vector<Jogadores>::iterator it;
  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
    if (out.is_open()) {
      out << (*it).Apelido << ", " << (*it).Nome << ", " << (*it).reversisWins
          << ", " << (*it).reversisDefeats << ", " << (*it).lig4sWins << ", "
          << (*it).lig4sDefeats << '\n';
    } else {
      cout << "O arquivo "
              "Jogadores.txt"
              " não pôde ser aberto."
           << endl;
      return;
    }
  }

  out.close();
}

void Jogadores::removeJogador(vector<Jogadores> &jogadoresVector) {

  vector<Jogadores>::iterator it;
  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
    if ((*it).Apelido == this->Apelido) {
      jogadoresVector.erase(it);
    }
  }
  this->reescreveArquivo(jogadoresVector);
}

void Jogadores::atualizaEstatisticas(int gameMode,
                                     vector<Jogadores> &jogadoresVector) {

  vector<Jogadores>::iterator it;
  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
    if ((*it).Apelido == Apelido) {
      if (gameMode == 1) {
        if ((*it).victory) {
          (*it).reversisWins++;
          break;
        } else {
          (*it).reversisDefeats++;
          break;
        }
      }
      if (gameMode == 2) {
        if ((*it).victory) {
          (*it).lig4sWins++;
          break;
        } else {
          (*it).lig4sDefeats++;
          break;
        }
      }
    }
  }
  this->reescreveArquivo(jogadoresVector);
}
