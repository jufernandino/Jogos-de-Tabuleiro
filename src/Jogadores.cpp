#include "Jogadores.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Jogadores::Jogadores() {
  this->Apelido = "";
  this->Nome = "";
  this->reversiWins = 0;
  this->reversiDefeats = 0;
  this->reversiEmpates = 0;
  this->lig4Wins = 0;
  this->lig4Defeats = 0;
  this->lig4Empates = 0;
  this->tictactoeWins = 0;
  this->tictactoeDefeats = 0;
  this->tictactoeEmpates = 0;
  this->victory = false;
  this->empate = false;
}

Jogadores::Jogadores(string apelido, string nome) {
  this->Apelido = apelido;
  this->Nome = nome;
  this->reversiWins = 0;
  this->reversiDefeats = 0;
  this->reversiEmpates = 0;
  this->lig4Wins = 0;
  this->lig4Defeats = 0;
  this->lig4Empates = 0;
  this->tictactoeWins = 0;
  this->tictactoeDefeats = 0;
  this->tictactoeEmpates = 0;
  this->victory = false;
  this->empate = false;

  ofstream out("Jogadores.txt", fstream::app);
  if (out.is_open()) {
    out << '\n'
        << this->Apelido << ", " << this->Nome << ", " << this->reversiWins
        << ", " << this->reversiDefeats << ", " << this->reversiEmpates << ", "
        << this->lig4Wins << ", " << this->lig4Defeats << ", "
        << this->lig4Empates << ", " << this->tictactoeWins << ", "
        << this->tictactoeDefeats << ", " << this->tictactoeEmpates;
    out.close();
  } else {
    cout << "ERRO: não foi possível abrir o arquivo Jogadores.txt" << endl;
  }
}

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
    cout << "ERRO: não foi possível abrir o arquivo Jogadores.txt" << endl;
    return 0;
  }

  in.close();
  return 0;
}

bool Jogadores::logar(string Apelido, vector<Jogadores> &jogadoresVector) {

  vector<Jogadores>::iterator it;
  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); it++) {
    if ((*it).Apelido == Apelido) {
      this->Apelido = (*it).Apelido;
      this->Nome = (*it).Nome;
      this->reversiWins = (*it).reversiWins;
      this->reversiDefeats = (*it).reversiDefeats;
      this->reversiEmpates = (*it).reversiEmpates;
      this->lig4Wins = (*it).lig4Wins;
      this->lig4Defeats = (*it).lig4Defeats;
      this->lig4Empates = (*it).lig4Empates;
      this->tictactoeWins = (*it).tictactoeWins;
      this->tictactoeDefeats = (*it).tictactoeDefeats;
      this->tictactoeEmpates = (*it).tictactoeEmpates;
      return true;
    }
  }
  return false;
}

void Jogadores::reescreveArquivo(vector<Jogadores> &jogadoresVector) {
  ofstream out("Jogadores.txt", ios::out | ios::trunc);  // Abre o arquivo apaga o conteúdo anterior

  if (!out.is_open()) {
      cout << "ERRO: não foi possível abrir o arquivo Jogadores.txt" << endl;
      return;
  }

  // Reescreve o arquivo com o conteúdo atualizado do vetor
  for (const auto& jogador : jogadoresVector) {
      out << jogador.Apelido << ", " << jogador.Nome << ", " 
          << jogador.reversiWins << ", " << jogador.reversiDefeats << ", " 
          << jogador.reversiEmpates << ", " << jogador.lig4Wins << ", " 
          << jogador.lig4Defeats << ", " << jogador.lig4Empates << ", " 
          << jogador.tictactoeWins << ", " << jogador.tictactoeDefeats << ", " 
          << jogador.tictactoeEmpates << '\n';
  }

  out.close();  
}

void Jogadores::carregarJogadores(vector<Jogadores> &jogadoresVector) {
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
      jogador.reversiEmpates = stoi(aux, nullptr, 10);
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
      jogador.lig4Empates = stoi(aux, nullptr, 10);
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
        if (line[i] != ',') {
          aux = aux + line[i];
        } else {
          break;
        }
      }
      jogador.tictactoeDefeats = stoi(aux, nullptr, 10);
      aux = "";
      i += 2;

      for (; i < line.size(); i++) {
        if (line[i] != '\n') {
          aux = aux + line[i];
        } else {
          break;
        }
      }
      jogador.tictactoeEmpates = stoi(aux, nullptr, 10);

      jogadoresVector.push_back(jogador);
    }
  } else {
    cout << "ERRO: não foi possível abrir o arquivo Jogadores.txt" << endl;
    return;
  }

  in.close();
}

void Jogadores::removeJogador(vector<Jogadores> &jogadoresVector, string &Apelido) {

  vector<Jogadores>::iterator it;
  bool jogadorEncontrado = false;

  // Procura pelo jogador no vetor
  for (it = jogadoresVector.begin(); it != jogadoresVector.end(); ++it) {
      if (it->Apelido == Apelido) {
          jogadoresVector.erase(it);  // Remove o jogador do vetor
          jogadorEncontrado = true;
          break;
      }
  }

  // Se o jogador foi encontrado e removido do vetor, reescreva o arquivo
  if (jogadorEncontrado) {
      ofstream outFile("Jogadores.txt", ios::out | ios::trunc);  // Abre o arquivo e exclui o conteúdo anterior

      if (!outFile.is_open()) {
          cout << "ERRO: não foi possível abrir o arquivo Jogadores.txt" << endl;
          return;
      }

      // Reescreve o arquivo com o conteúdo atualizado do vetor
      for (const auto& jogador : jogadoresVector) {
          outFile << jogador.Apelido << ", " << jogador.Nome << ", " 
                  << jogador.reversiWins << ", " << jogador.reversiDefeats << ", " 
                  << jogador.reversiEmpates << ", " << jogador.lig4Wins << ", " 
                  << jogador.lig4Defeats << ", " << jogador.lig4Empates << ", " 
                  << jogador.tictactoeWins << ", " << jogador.tictactoeDefeats << ", " 
                  << jogador.tictactoeEmpates << '\n';
      }

      outFile.close(); 

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
        } else if (!this->victory) {
          (*it).reversiDefeats++;
        } else if (this->empate) {
          (*it).reversiEmpates++;
        }
        break;
      } else if (jogoEscolhido == 'L') {
        if (this->victory) {
          (*it).lig4Wins++;
        } else if (!this->victory) {
          (*it).lig4Defeats++;
        } else if (this->empate) {
          (*it).lig4Empates++;
        }
        break;
      } else if (jogoEscolhido == 'T') {
        if (this->victory) {
          (*it).tictactoeWins++;
        } else if (!this->victory) {
          (*it).tictactoeDefeats++;
        } else if (this->empate) {
          (*it).tictactoeEmpates++;
        }
        break;
      }
    }
  }
  this->reescreveArquivo(jogadoresVector);
}

// método para mostrar o raking de cada jogo, de acordo com o número de vitórias
void Jogadores::mostrarRanking(const char &jogoEscolhido,
                               vector<Jogadores> jogadoresVector) {

  auto ordenacaoVitorias = [jogoEscolhido](const Jogadores &x,
                                           const Jogadores &y) {
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
    // falta o Campo Minado
    default:
      return false;
    }
  };

  sort(jogadoresVector.begin(), jogadoresVector.end(), ordenacaoVitorias);

  cout << "\n--------\nRANKING DO JOGO\n--------\n" << endl;

  for (const auto &jogador : jogadoresVector) {

    switch (jogoEscolhido) {
    case 'R':
      cout << jogador.Apelido << ", " << jogador.Nome << ", "
           << jogador.reversiWins << " vitória(s)" << endl;
      break;

    case 'L':
      cout << jogador.Apelido << ", " << jogador.Nome << ", "
           << jogador.lig4Wins << " vitória(s)" << endl;
      break;

    case 'T':
      cout << jogador.Apelido << ", " << jogador.Nome << ", "
           << jogador.tictactoeWins << " vitória(s)" << endl;
      break;

      // falta o campo minado

    default:
      cout << "ERRO: opção inválida" << endl;
    }
  }
  cout << "\n" << endl;
}

void Jogadores::mostrarEstatisticas(vector<Jogadores> jogadoresVector,
                                    const string &ordenacao) {

  int tamanho = jogadoresVector.size();

  // selection sort
  if (ordenacao == "A" || ordenacao == "a") { // ordenação por apelido
    for (int i = 0; i < tamanho - 1; ++i) {
      int menorElemento = i;
      for (int j = i + 1; j < tamanho; ++j) {
        if (jogadoresVector[j].Apelido <
            jogadoresVector[menorElemento].Apelido) {
          menorElemento = j;
        }
      }
      swap(jogadoresVector[i], jogadoresVector[menorElemento]);
    }
  } else if (ordenacao == "N" || ordenacao == "n") { // ordenação por nome
    for (int i = 0; i < tamanho - 1; ++i) {
      int menorElemento = i;
      for (int j = i + 1; j < tamanho; ++j) {
        if (jogadoresVector[j].Nome < jogadoresVector[menorElemento].Nome) {
          menorElemento = j;
        }
      }
      swap(jogadoresVector[i], jogadoresVector[menorElemento]);
    }
  }
  for (const auto &jogador : jogadoresVector) {
    cout << "\n";
    cout << jogador.Apelido << " " << jogador.Nome << endl;
    cout << "REVERSI - V: " << jogador.reversiWins
         << " D: " << jogador.reversiDefeats << " E: " << jogador.reversiEmpates
         << endl;
    cout << "LIG 4 - V: " << jogador.lig4Wins << " D: " << jogador.lig4Defeats
         << " E: " << jogador.lig4Empates << endl;
    cout << "TIC TAC TOE - V: " << jogador.tictactoeWins
         << " D: " << jogador.tictactoeDefeats
         << " E: " << jogador.tictactoeEmpates << endl;
  }
}


void Jogadores::cadastrarJogadores(string apelido, string nome,
                                   Jogadores &Jogador,
                                   vector<Jogadores> &jogadoresVector) {

  Jogadores aux;

  if (aux.pesquisaJogador(apelido)) { // se jogador já existir
    cout << "ERRO: jogador repetido" << endl;
    return;
  } else {
    Jogadores novoJogador(apelido, nome);
    if (novoJogador.Apelido != "") {
      jogadoresVector.push_back(novoJogador);
      Jogador = novoJogador;
      cout << "\nJogador " << novoJogador.Apelido << " cadastrado com sucesso"
           << endl;
    }
  }
}
