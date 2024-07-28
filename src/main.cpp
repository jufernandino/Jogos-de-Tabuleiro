#include "Jogadores.hpp"
#include "Tabuleiro.hpp"
#include "TicTacToe.hpp"
#include "lig4.hpp"
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// void to_lower(string &s) {
//   int len = s.size();
//   for (int i = 0; i < len; i++) {
//     s[i] = tolower(s[i]);
//   }
// }

void antiUsuario(int &a) { // confere se as entradas fornecidas pelo usuário não
                           // quebram o código
  string aux = "";

  while (1) {
    cin >> aux;
    while ((getchar()) != '\n')
      ;

    if (aux.length() != 1) {
      cout << "Opção inválida! Tente novamente." << endl;
      continue;
    }

    if (!isdigit(aux[0])) {
      cout << "Opção inválida! Tente novamente." << endl;
      continue;
    }

    if (isdigit(aux[0])) {
      a = stoi(aux, nullptr, 10);
      break;
      // if (a > 5 || a < 0) {
      //   cout << "Opção inválida! Tente novamente." << endl;
      //   continue;
      // } else {
      //   break;
      // }
    }
  }
}

void showEstatisticas() {

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

// void showRegras(const int &gameMode) {
//   ifstream arquivo("Regras.txt");

//   if (!arquivo.is_open()) {
//     cout << "Erro ao tentar abrir o arquivo!" << endl;
//     return;
//   }

//   string linha, regras;
//   bool continuar = false;
//   string aux = "(" + to_string(gameMode) + ")";

//   while (getline(arquivo, linha)) {
//     if (linha == aux) {
//       continuar = true;
//       continue;
//     }

//     if (continuar && !linha.empty()) {
//       regras += linha + "\n";
//     } else {
//       break;
//     }
//   }

//   arquivo.close();

//   if (!regras.empty()) {
//     cout << "\n" << regras << endl;
//   }
// }

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

void cadastrarJogadores(Jogadores &Jogador,
                        vector<Jogadores> &jogadoresVector) {
  while (1) {
    cout << "Você deseja "
            "sign in (1)"
            " ou "
            "sing up (2)"
            "?"
         << endl;
    int options;

    while (1) {
      antiUsuario(options);
      if (options != 1 && options != 2) {
        cout << "Opção inválida! Tente novamente." << endl;
      } else {
        break;
      }
    }

    if (options == 1) {
      Jogadores aux;
      string str;
      cout << "Insira seu nickname:" << endl;
      cin >> str;
      if (aux.pesquisaJogador(str)) {
        aux.signIn(str, jogadoresVector);
        Jogador = aux;
        break;
      } else {
        cout << "Esse jogador não existe. Tente novamente." << endl;
      }
    }

    if (options == 2) {
      string str;
      Jogadores aux(str);
      jogadoresVector.push_back(aux);
      Jogador = aux;
      break;
    }
  }
}

int main() {

  vector<Jogadores> jogadoresVector;

  loadJogadores(jogadoresVector);

  bool opcaoVoltar = false;

  do {
    cout << "MENU PRINCIPAL \nOlá! Vamos jogar? :) \n\nJogar (1) \nConsultar "
            "estatísticas dos jogadores (2)"
         << endl;

    char opcaoMenu = '0';
    cin >> opcaoMenu;

    while (1) {
      if (opcaoMenu != '1' && opcaoMenu != '2') {
        cout << "Opção inválida! Tente novamente." << endl;
        cin >> opcaoMenu;
      } else {
        break;
      }
    }

    if (opcaoMenu == '1') {
      break;
    } else if (opcaoMenu == '2') {

      cout << "CONSULTAR ESTATÍSTICAS\n" << endl;
      showEstatisticas();
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

  cout << "\nJOGAR" << endl;

  Jogadores Jogador1, Jogador2;
  cadastrarJogadores(Jogador1, jogadoresVector);
  cadastrarJogadores(Jogador2, jogadoresVector);

  cout << "\nQue jogo gostariam de jogar?, Reversi (1), Lig4 (2), TicTacToe "
          "(3) ou Campo Minado (4)?\n"
       << endl;

  // int lerRegras = 0;

  char gameMode;
  cin >> gameMode;

  while (1) {
    if (gameMode != '1' && gameMode != '2' && gameMode != '3' &&
        gameMode != '4') {
      cout << "Opção inválida! Tente novamente." << endl;
      cin >> gameMode;
    } else {
      break;
    }
  }

  if (gameMode == '1') {
    cout << "\nReversi foi escolhido." << endl;
    //   do {
    //     cout << "\nLer regras do jogo (1) \nJogar (2)" << endl;

    //     cin >> lerRegras;

    //     if (lerRegras == 1) {
    //       showRegras(gameMode);
    //       opcaoSair = true;

    //     } else if (lerRegras == 2) {
    //       cout << "\nVamos começar." << endl;
    //       break;
    //     }
    //   } while (!(opcaoSair));

    //   cout << "teste 1" << endl;
    // }
  }

  if (gameMode == '2') {
    cout << "\nLig4 foi escolhido." << endl;

    int x = 0, y = 0;
    string aux;
    lig4 l;

    l.criaTabuleiro();
    l.imprimeTabuleiro();

    int jogadorAtual = 0;

    while (1) {

      char z = ' ';
      if (jogadorAtual % 2 == 0) {
        z = 'X';
      }
      if (jogadorAtual % 2 != 0) {
        z = 'O';
      }

      antiUsuario(y);

      l.validaJogada(x, y, z);

      l.imprimeTabuleiro();

      if (l.confereGanhador()) {
        cout << Jogador1.Apelido << " ganhou!" << endl;
        Jogador1.victory = true;
        Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
        Jogador2.atualizaEstatisticas(gameMode, jogadoresVector);
        break;
      }
      if (l.confereGanhador()) {
        cout << Jogador2.Apelido << " ganhou!" << endl;
        Jogador2.victory = true;
        Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
        Jogador2.atualizaEstatisticas(gameMode, jogadoresVector);
        break;
      }
      if (l.confereGanhador()) {
        cout << "Não há vencedores!" << endl;
        break;
      }
      jogadorAtual++;
    }
    l.liberaMemoria();
  }

  if (gameMode == '3') {
    cout << "\nTicTacToe foi escolhido.\n" << endl;

    int x = 0, y = 0;
    TicTacToe t;

    t.criaTabuleiro();
    t.imprimeTabuleiro();

    int jogadorAtual = 0;

    while (1) {

      char z = ' ';
      if (jogadorAtual % 2 == 0) {
        z = 'X';
      }
      if (jogadorAtual % 2 != 0) {
        z = 'O';
      }

      antiUsuario(x);
      antiUsuario(y);

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

  if (gameMode == '4') {
    cout << "\nCampo Minado foi escolhido.\n" << endl;
  }

  return 0;
}