#include "Jogadores.hpp"
#include "Tabuleiro.hpp"
#include "TicTacToe.hpp"
#include "lig4.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// void clear_screen() {
// #ifdef __linux__
//   system("clear");
// #elif __windows__
//   system("cls");
// #else

// #endif
// }

/* bool verificaEntradaMenu (int digito) {
  return (isdigit(digito));
} */

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
    cout << "MENU PRINCIPAL \nOlá! Vamos jogar? :) \n\nJogar (1) \nConsultar "
            "estatísticas dos jogadores (2)"
         << endl;

    cin >> opcaoMenu;

    if (opcaoMenu == '1') {
      break;
    } else if (opcaoMenu == '2') {
      // clear_screen();
      cout << "CONSULTAR ESTATÍSTICAS\n" << endl;
      showJogadores();
      cout << "\nPara voltar ao menu principal, tecle ENTER." << endl;
      cin.ignore();
      cin.get();
      opcaoVoltar = true;
      // clear_screen();
    } else {
      cout << "\nOpção inválida. \nTecle ENTER para voltar ao menu principal."
           << endl;
      cin.ignore();
      cin.get();
      opcaoVoltar = true;
      // clear_screen();
    }
  } while (opcaoVoltar);

  // clear_screen();

  cout << "JOGAR" << endl;

  while (1) {
    cout << "\nPRIMEIRO JOGADOR:" << endl;
    cout << "\nVocê deseja "
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
      cout << "\nInsira seu nickname:" << endl;
      cin >> str;
      if (jogador.pesquisaJogador(str)) {
        jogador.signIn(str, jogadoresVector);
        Jogador1 = jogador;
        break;
      } else {
        cout << "\nEsse jogador não existe. Tente novamente." << endl;
        continue;
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

  // clear_screen();

  while (1) {
    cout << "SEGUNDO JOGADOR:" << endl;
    cout << "\nVocê deseja "
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
      cout << "\nInsira seu nickname:" << endl;
      cin >> str;
      if (str == Jogador1.Apelido) {
        cout << "\nEsse jogador já foi escolhido. Tente novamente.\n" << endl;
        continue;
      }
      if (jogador.pesquisaJogador(str) && str != Jogador1.Apelido) {
        jogador.signIn(str, jogadoresVector);
        Jogador2 = jogador;
        break;
      } else {
        cout << "\nEsse jogador não existe. Tente novamente.\n" << endl;
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

  do {
    cout << "ESCOLHER JOGO:" << endl;

    cout << "\nQual jogo gostariam de jogar? \n\nReversi (1) \nLig4 (2) "
            "\nTicTacToe (3)?"

         << endl;

    cin >> gameMode;

    if (gameMode == 1) {
      cout << "Reversi foi escolhido." << endl;
    }
    if (gameMode == 2) {
      cout << "Lig4 foi escolhido." << endl;
    }
    if (gameMode == 3) {
      cout << "Tic Tac Toe foi escolhido." << endl;
      int x, y;
      TicTacToe t;
      t.criaTabuleiro();
      int i = 0;
      while (1) {
        cin >> x;
        cin >> y;

        char z = ' ';
        if (i % 2 == 0) {
          z = 'X';
        }
        if (i % 2 != 0) {
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
        i++;
      }
      t.liberaMemoria();
    }

    // switch (gameMode) {
    // case 1:
    //   cout << "\nReversi foi escolhido." << endl;
    //   break;
    // case 2:
    //   cout << "\nLig4 foi escolhido." << endl;
    //   break;
    // case 3:
    //   cout << "\nTicTacToe foi escolhido." << endl;
    //   break;
    // default:
    //   gameMode = 0;
    //   cout << "\nOpção inválida. Tente novamente. \n" << endl;
    // }

  } while (gameMode == 0);

  // cout << "\nFim do programa." << endl;

  // falta a validação de quando um jogador ganha

  return 0;
}