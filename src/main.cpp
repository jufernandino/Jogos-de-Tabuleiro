#include "Jogadores.hpp"
#include "Tabuleiro.hpp"
#include "TicTacToe.hpp"
#include "lig4.hpp"
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

void showRegras(const int &gameMode) {
  ifstream arquivo("Regras.txt");
  
  if (!arquivo.is_open()) {
    cout << "Erro ao tentar abrir o arquivo!" << endl;
    return;
  }

  string linha, regras;
  bool continuar = false;
  string aux = "(" + to_string(gameMode) + ")";

  while (getline(arquivo, linha)) {
    if (linha == aux) {
      continuar = true;
      continue;
  }
    
    if (continuar && !linha.empty()) {
      regras += linha + "\n";
    } else {
      break;
    }
  }

  arquivo.close();

  if (!regras.empty()) {
    cout << "\n" << regras << endl;
}
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

  Jogadores Jogador1, Jogador2;

  bool opcaoVoltar = false;

  do {
    char opcaoMenu = '0';
    cout << "MENU PRINCIPAL \nOlá! Vamos jogar? \n\nJogar (1) \nConsultar "
            "estatísticas dos jogadores (2)"
         << endl;

    cin >> opcaoMenu;

    if (opcaoMenu == '1') {
      break;
    } else if (opcaoMenu == '2') {

      cout << "CONSULTAR ESTATÍSTICAS\n" << endl;
      showJogadores();
      cout << "\nPara voltar ao menu principal, tecle ENTER." << endl;
      cin.ignore();
      cin.get();
      opcaoVoltar = true;

    } else {
      cout << "\nOpção inválida. \nTecle ENTER para voltar ao menu principal."
           << endl;
      cin.ignore();
      cin.get();
      opcaoVoltar = true;
    }
  } while (opcaoVoltar);

  //cout << "\nJOGAR" << endl;

  while (1) {
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
  
  //int lerRegras = 0;

  do {

  cout << "\nQual jogo gostariam de jogar? \nReversi (1) \nLig4 (2) \nTicTacToe (3) \nCampo Minado (4)"
       << endl;

  cin >> gameMode;

  bool opcaoSair = false;

  if (gameMode == 1) {
    cout << "\nReversi foi escolhido." << endl;
    
/* do {
        cout << "\nLer regras do jogo (1) \nJogar (2)" << endl;
          
        cin >> lerRegras;

        if (lerRegras == 1) {
          showRegras(gameMode);
          opcaoSair = true;
          
        } else if (lerRegras == 2) {
          cout << "\nVamos começar." << endl;
          break;
        }
      } while (!(opcaoSair));

    cout << "teste 1" << endl;
  } */
  }

  if (gameMode == 2) {
    cout << "\nLig4 foi escolhido." << endl;

    int x, y;
    lig4 l;

    l.criaTabuleiro();
    l.imprimeTabuleiro();

    int jogadorAtual = 0;

    while (1) {
      cin >> x;
      cin >> y;

      char z = ' ';
      if (jogadorAtual % 2 == 0) {
        z = 'X';
      }
      if (jogadorAtual % 2 != 0) {
        z = 'O';
      }

      l.validaJogada(x, y, z);
      l.imprimeTabuleiro();
      int resultado = l.confereGanhador();
      if (resultado == 1) {
        cout << Jogador1.Apelido << " ganhou!" << endl;
        Jogador1.victory = true;
        Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
        Jogador2.atualizaEstatisticas(gameMode, jogadoresVector);
        break;
      }
      if (resultado == 2) {
        cout << Jogador2.Apelido << " ganhou!" << endl;
        Jogador2.victory = true;
        Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
        Jogador2.atualizaEstatisticas(gameMode, jogadoresVector);
        break;
      }
      if (resultado == 3) {
        cout << "Não há vencedores!" << endl;
        break;
      }
      jogadorAtual++;
    }
    l.liberaMemoria();
  }

  if (gameMode == 3) {
    cout << "\nTicTacToe foi escolhido." << endl;

    int x, y;
    TicTacToe t;

    t.criaTabuleiro();
    t.imprimeTabuleiro();

    int jogadorAtual = 0;

    while (1) {
      cin >> x;
      cin >> y;

      char z = ' ';
      if (jogadorAtual % 2 == 0) {
        z = 'X';
      }
      if (jogadorAtual % 2 != 0) {
        z = 'O';
      }

      t.validaJogada(x, y, z);
      t.imprimeTabuleiro();

      if (t.confereGanhador() == 1) {
        cout << Jogador1.Apelido << " ganhou!" << endl;
        Jogador1.victory = true;
        Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
        Jogador2.atualizaEstatisticas(gameMode, jogadoresVector);
        break;
      }
      if (t.confereGanhador() == 2) {
        cout << Jogador2.Apelido << " ganhou!" << endl;
        Jogador2.victory = true;
        Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
        Jogador2.atualizaEstatisticas(gameMode, jogadoresVector);
        break;
      }
      if (t.confereGanhador() == 3) {
        cout << "Não há vencedores!" << endl;
        break;
      }
      jogadorAtual++;
    }
    t.liberaMemoria();
  }

  if (gameMode == 4) {
    cout << "\nCampo Minado foi escolhido." << endl;
  }
    
  } while (gameMode == 0);
  
  return 0;
}