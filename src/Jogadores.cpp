#include "Jogadores.hpp"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int Jogadores::pesquisaJogador(string apelido) {

  ifstream in("Jogadores.txt", fstream::in);

  if (in.is_open()) {
    string line;
    while (getline(in, line)) {
      string aux = "";
      for (long unsigned int i = 0; i < line.size(); i++) {
        if (line[i] != ',') {
          aux = aux + line[i];
        } else {
          break;
        }
      }
      if (aux == apelido) {
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

Jogadores::Jogadores(string apelido, string nome) {
  this->Apelido = apelido;
  this->Nome = nome;
  this->reversiWins = 0;
  this->reversiDefeats = 0;
  this->lig4Wins = 0;
  this->lig4Defeats = 0;
  this->tictactoeWins = 0;
  this->tictactoeDefeats = 0;
  this->victory = false;

  ofstream out("Jogadores.txt", fstream::app);
  if (out.is_open()) {
      out << '\n' << this->Apelido << ", " << this->Nome << ", " 
          << this->reversiWins << ", " << this->reversiDefeats 
          << ", " << this->lig4Wins << ", " << this->lig4Defeats 
          << ", " << this->tictactoeWins << ", " << this->tictactoeDefeats;
      out.close();
  } else {
      cout << "ERRO: não foi possível abrir o arquivo Jogadores.txt" << endl;
  }
}


bool Jogadores::logar(string Apelido, vector<Jogadores> &jogadoresVector) {

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
      return true;
    }
  }
  return false;
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

void Jogadores::removeJogador(vector<Jogadores> &jogadoresVector, string &Apelido) {

  vector<Jogadores>::iterator it;
  bool jogadorEncontrado = false;

  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); ++it) {
      if (it->Apelido == Apelido) {
          jogadoresVector.erase(it);
          jogadorEncontrado = true;
          break;
      }
  }

  if (jogadorEncontrado) {
      this->reescreveArquivo(jogadoresVector);
      cout << "Jogador " << Apelido << " removido com sucesso" << endl;
  } else {
      cout << "ERRO: jogador inexistente" << endl;
  }
  
}

void Jogadores::atualizaEstatisticas(char jogoEscolhido,
                                     vector<Jogadores> &jogadoresVector) {

  vector<Jogadores>::iterator it;
  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
    if ((*it).Apelido == this->Apelido) {
      if (jogoEscolhido == 'R') {
        if (this->victory) {
          (*it).reversiWins++;
          break;
        } else {
          (*it).reversiDefeats++;
          break;
        }
      }
      if (jogoEscolhido == 'L') {
        if (this->victory) {
          (*it).lig4Wins++;
          break;
        } else {
          (*it).lig4Defeats++;
          break;
        }
      }
      if (jogoEscolhido == 'T') {
        if (this->victory) {
          (*it).tictactoeWins++;
          break;
        } else {
          (*it).tictactoeDefeats++;
          break;
        }
      } //falta os outros dois jogos
    }
  }
  this->reescreveArquivo(jogadoresVector);
}

void Jogadores::showRanking(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector) {
  
  auto ordenacaoDecrescente = [jogoEscolhido](const Jogadores &x, const Jogadores &y) {
  
    switch (jogoEscolhido) {
      case 'R':
        return (x.reversiWins > y.reversiWins);
        break;
      case 'L':
        return (x.lig4Wins > y.lig4Wins);
        break;
      case 'T':
        return (x.tictactoeWins > y.tictactoeWins);
        break;
      //falta o Campo Minado
      default:
        return false;
    }
  };
  
      sort(jogadoresVector.begin(), jogadoresVector.end(), ordenacaoDecrescente);

    cout << "\n--------\nRANKING DO JOGO\n--------\n" << endl;
  
    for (const auto &jogador : jogadoresVector) {
      
    switch(jogoEscolhido) {    
      case 'R':
        cout << jogador.Apelido << ", " << jogador.Nome << ", " << jogador.reversiWins << " vitória(s)" << endl;
      break;

      case 'L':
        cout << jogador.Apelido << ", " << jogador.Nome << ", " << jogador.lig4Wins << " vitória(s)" << endl;
      break;

      case 'T':
        cout << jogador.Apelido << ", " << jogador.Nome << ", " << jogador.tictactoeWins << " vitória(s)" << endl;
      break;

      //falta o campo minado

      default:
        cout << "ERRO: opção inválida" << endl;
    }
  }
  cout << "\n" << endl;
}

bool Jogadores::ordenacaoDecrescente(const Jogadores &x, const Jogadores &y, const char &ordenacao) {
  if (ordenacao == 'A') { //ordenação por apelido
    return (x.Apelido < y.Apelido);
  } else if (ordenacao == 'N') { //ordenação por nome
    return (x.Nome < y.Nome);
  }
  return false; //exceção aqui?
}

void Jogadores::showEstatisticas(vector<Jogadores> &jogadoresVector, const char &ordenacao, char &ordem) {
  
  sort(jogadoresVector.begin(), jogadoresVector.end(), [ordenacao, ordem](const Jogadores &x, const Jogadores &y) {
      if (ordem == 'A') {
          return x.Apelido < y.Apelido;
      } else if (ordem == 'N') {
          return x.Nome < y.Nome;
      }
      return false; 
  });
  
  for (const auto &jogador : jogadoresVector) {
    cout << jogador.Apelido << " " << jogador.Nome << endl;
    cout << "REVERSI - V: " << jogador.reversiWins << " D: " << jogador.reversiDefeats << endl;
    cout << "LIG 4 - V: " << jogador.lig4Wins << " D: " << jogador.lig4Defeats << endl;
    cout << "TIC TAC TOE - V: " << jogador.tictactoeWins << " D: " << jogador.tictactoeDefeats << endl;
    cout << "\n" << endl;
    }
}

void Jogadores::loadJogadores(vector<Jogadores> &jogadoresVector) {
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
        jogador.reversiWins = stoi(aux, nullptr, 10);
        aux = "";
        i += 2;

        for (; i < line.size(); i++) {
          if (line[i] != ',') {
            aux = aux + line[i];
          } else {
            break;
          }
        }
        jogador.reversiDefeats = stoi(aux, nullptr, 10);
        aux = "";
        i += 2;

        for (; i < line.size(); i++) {
          if (line[i] != ',') {
            aux = aux + line[i];
          } else {
            break;
          }
        }
        jogador.lig4Wins = stoi(aux, nullptr, 10);
        aux = "";
        i += 2;

        for (; i < line.size(); i++) {
          if (line[i] != ',') {
            aux = aux + line[i];
          } else {
            break;
          }
        }
        jogador.lig4Defeats = stoi(aux, nullptr, 10);
        aux = "";
        i += 2;

        for (; i < line.size(); i++) {
          if (line[i] != ',') {
            aux = aux + line[i];
          } else {
            break;
          }
        }
        jogador.tictactoeWins = stoi(aux, nullptr, 10);
        aux = "";
        i += 2;

        for (; i < line.size(); i++) {
          if (line[i] != '\n') {
            aux = aux + line[i];
          } else {
            break;
          }
        }
        jogador.tictactoeDefeats = stoi(aux, nullptr, 10);

        jogadoresVector.push_back(jogador);
      }
    } else {
      cout << "ERRO: não foi possível abrir o arquivo Jogadores.txt" << endl;
      return;
    }

    in.close();
}

void Jogadores::cadastrarJogadores(Jogadores &Jogador, vector<Jogadores> &jogadoresVector) {
  cout << "Digite apelido e nome desejados: " << endl;
  
  string apelido, nome;
    
  cin >> apelido >> nome;
  
  cout << endl;

    Jogadores aux;

    if (aux.pesquisaJogador(apelido)) { // se jogador já existir
        cout << "ERRO: jogador repetido" << endl;
        return;
    } else {
        // Se o jogador não existir, cria um novo 
        Jogadores novoJogador(apelido, nome);
        if (novoJogador.Apelido != "") { 
            jogadoresVector.push_back(novoJogador);
            Jogador = novoJogador;
            cout << "Jogador " << apelido << " cadastrado com sucesso" << endl;
        }
    }
  }