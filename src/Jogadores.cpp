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
  this->reversiWins = 0;
  this->reversiDefeats = 0;
  this->lig4Wins = 0;
  this->lig4Defeats = 0;
  this->tictactoeWins = 0;
  this->tictactoeDefeats = 0;
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
      cout << "Por favor, tente novamente: " << endl;
      continue;
    } else {
      break;
    }
  }

  this->Apelido = Apelido;
  this->Nome = Nome;
  this->reversiWins = 0;
  this->reversiDefeats = 0;
  this->lig4Wins = 0;
  this->lig4Defeats = 0;
  this->tictactoeWins = 0;
  this->tictactoeDefeats = 0;
  this->victory = false;
  
  ofstream out("Jogadores.txt", fstream::app);

  if (out.is_open()) {
    out << '\n'
        << this->Apelido << ", " << this->Nome << ", " << this->reversiWins
        << ", " << this->reversiDefeats << ", " << this->lig4Wins << ", "
        << this->lig4Defeats << ", " << this->tictactoeWins << ", "
        << this->tictactoeDefeats;
  } else {
    cout << "ERRO: não foi possível abrir o arquivo Jogadores.txt" << endl;
    return;
  }

  out.close();

  cout << "Jogador " << Apelido << " cadastrado com sucesso" << endl;
}

void Jogadores::signIn(string Apelido, vector<Jogadores> &jogadoresVector) {

  vector<Jogadores>::iterator it;
  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
    if ((*it).Apelido == Apelido) {
      this->Apelido = (*it).Apelido;
      this->Nome = (*it).Nome;
      this->reversiWins = (*it).reversiWins;
      this->reversiDefeats = (*it).reversiDefeats;
      this->lig4Wins = (*it).lig4Wins;
      this->lig4Defeats = (*it).lig4Defeats;
      this->tictactoeWins = (*it).tictactoeWins;
      this->tictactoeDefeats = (*it).tictactoeDefeats;
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
      out << (*it).Apelido << ", " << (*it).Nome << ", " << (*it).reversiWins
          << ", " << (*it).reversiDefeats << ", " << (*it).lig4Wins << ", "
          << (*it).lig4Defeats << ", " << (*it).tictactoeWins << ", "
          << (*it).tictactoeDefeats << '\n';
    } else {
      cout << "ERRO: não foi possível abrir o arquivo Jogadores.txt" << endl;
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
    if ((*it).Apelido == this->Apelido) {
      if (gameMode == 1) {
        if (this->victory) {
          (*it).reversiWins++;
          break;
        } else {
          (*it).reversiDefeats++;
          break;
        }
      }
      if (gameMode == 2) {
        if (this->victory) {
          (*it).lig4Wins++;
          break;
        } else {
          (*it).lig4Defeats++;
          break;
        }
      }
      if (gameMode == 3) {
        if (this->victory) {
          (*it).tictactoeWins++;
          break;
        } else {
          (*it).tictactoeDefeats++;
          break;
        }
      }
    }
  }
  this->reescreveArquivo(jogadoresVector);
}

void Jogadores::showRanking(const int &gameMode, vector<Jogadores> &jogadoresVector) {
  for (const auto &jogador : jogadoresVector) {
    switch(gameMode) {
      case 1:
        cout << "Reversi: " << jogador.reversiWins << " vitorias, " << jogador.reversiDefeats << " derrotas" << endl;
      break;

      case 2:
        cout << "Liga 4: " << jogador.lig4Wins << " vitorias, " << jogador.lig4Defeats << " derrotas" << endl;
      break;

      case 3:
        cout << "Tic Tac Toe: " << jogador.tictactoeWins << " vitorias, " << jogador.tictactoeDefeats << " derrotas" << endl;
      break;

      default:
        cout << "Erro irmao" << endl;
    }
  }
}