#include "Jogadores.hpp"
#include "Tabuleiro.hpp"
#include "TicTacToe.hpp"
#include "lig4.hpp"
#include "Reversi.hpp"
#include "CampoMinado.hpp"
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

void antiUsuario(int &a);
void showEstatisticas();
void loadJogadores(vector<Jogadores> &jogadoresVector);
void cadastrarJogadores(Jogadores &Jogador, vector<Jogadores> &jogadoresVector);
void showRanking (const int &gameMode, vector<Jogadores> &jogadoresVector);

int main() {

  vector<Jogadores> jogadoresVector;

  loadJogadores(jogadoresVector);

  bool opcaoVoltar = false;

  do {
    char opcaoMenu = '0';
    cout << "\n--------\nMENU PRINCIPAL\n--------\n\nOlá! Vamos jogar? \n\nJogar (1) \nConsultar estatísticas dos jogadores (2)"
         << endl;

    cin >> opcaoMenu;

    while (1) {
      if (opcaoMenu != '1' && opcaoMenu != '2') {
        cout << "\nOpção inválida! Tente novamente.\n" << endl;
        cin >> opcaoMenu;
      } else {
        break;
      }
    }

    if (opcaoMenu == '1') {
      break;
    } else if (opcaoMenu == '2') {

      cout << "\n--------\nCONSULTAR ESTATÍSTICAS\n-------- \n" << endl;
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

  cout << "\n--------\nJOGADORES\n--------\n" << endl;

  Jogadores Jogador1, Jogador2;
  cadastrarJogadores(Jogador1, jogadoresVector);
  cadastrarJogadores(Jogador2, jogadoresVector);

  cout << "Qual jogo gostariam de jogar? \n\nReversi (1) \nLig4 (2) \nTicTacToe (3) \nCampo Minado (4)?\n" << endl;

  int gameMode;
  antiUsuario(gameMode);

  //jogo Reversi
  if (gameMode == 1) {
    cout << "\nReversi foi escolhido." << endl;

    Reversi r;

    r.menuJogo(gameMode);
    r.criaTabuleiro();
    r.inicializarJogo();
    r.imprimeTabuleiro();

  int jogadorAtual = 0;

  do {
    char z = ' ';
    if (jogadorAtual % 2 == 0) {
      z = 'X';
      cout << "\nA vez agora é de " << Jogador1.Apelido << ":\n" << endl;
    }
    if (jogadorAtual % 2 != 0) {
      z = 'O';
      cout << "\nA vez agora é de " << Jogador2.Apelido << ":\n" << endl;
    }

    r.mostrarLocaisJogada(z);

    int x, y;

    antiUsuario(x);
    antiUsuario(y);

    if (r.ehJogadaValida(x, y, z)) //se a jogada for possivel
      {
        r.validaJogada(x, y, z);
        r.imprimeTabuleiro();             
        jogadorAtual++;                     
      }
      else
      {
        cout << "ERRO: jogada inválida" << endl;
        continue;
      }

    } while (!r.verificarFimDeJogo()); //verifica se o jogo acabou

    //r.confereGanhador();

    if(r.confereGanhador() == 1) {
      cout << Jogador1.Apelido << " ganhou!" << endl;
      Jogador1.victory = true;

      Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
      Jogador2.atualizaEstatisticas(gameMode, jogadoresVector);

    } else if (r.confereGanhador() == 2) {
      cout << Jogador2.Apelido << " ganhou!" << endl;
    Jogador2.victory = true;
    
    Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
    Jogador2.atualizaEstatisticas(gameMode, jogadoresVector);
      
    } else if (r.confereGanhador() == 3) {
        cout << "Empate!" << endl;
    }

    //fazer o if
    //Jogador1.showRanking(gameMode, jogadoresVector);
    
    r.liberaMemoria();
  }
  
  //jogo lig4
  if (gameMode == 2) {
    cout << "\nLig4 foi escolhido." << endl;

    int x = 0, y = 0;
    string aux;
    lig4 l;

    l.menuJogo(gameMode);
    l.criaTabuleiro();
    l.imprimeTabuleiro();

    int jogadorAtual = 0;

    while (1) {

      char z = ' ';
      if (jogadorAtual % 2 == 0) {
        z = 'X';
        cout << "\nA vez agora é de " << Jogador1.Apelido << ":\n" << Jogador1.Apelido << endl;
      }
      if (jogadorAtual % 2 != 0) {
        z = 'O';
        cout << "\nA vez agora é de " << Jogador2.Apelido << ":\n" << Jogador2.Apelido << endl;
      }

      antiUsuario(y);

      l.validaJogada(x, y, z);

      l.imprimeTabuleiro();

      if (l.confereGanhador() == 1) {
        cout << Jogador1.Apelido << " ganhou!" << endl;
        Jogador1.victory = true;
        Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
        Jogador2.atualizaEstatisticas(gameMode, jogadoresVector);
        break;
      }
      if (l.confereGanhador() == 2) {
        cout << Jogador2.Apelido << " ganhou!" << endl;
        Jogador2.victory = true;
        Jogador1.atualizaEstatisticas(gameMode, jogadoresVector);
        Jogador2.atualizaEstatisticas(gameMode, jogadoresVector);
        break;
      }
      if (l.confereGanhador() == 3) {
        cout << "Empate!" << endl;
        break;
      }
      jogadorAtual++;
    }
    l.liberaMemoria();
  }

  //jogo tictactoe
  if (gameMode == 3) {
    cout << "\nTicTacToe foi escolhido.\n" << endl;

    int x = 0, y = 0;
    TicTacToe t;

    //fazer o if
    //Jogador1.showRanking(gameMode, jogadoresVector);

    t.menuJogo(gameMode);
    t.criaTabuleiro();
    t.imprimeTabuleiro();

    int jogadorAtual = 0;

    while (1) {

      char z = ' ';
      if (jogadorAtual % 2 == 0) {
        z = 'X';
        cout << "\nA vez agora é de " << Jogador1.Apelido << ":\n" << Jogador1.Apelido << endl;
      }
      if (jogadorAtual % 2 != 0) {
        z = 'O';
        cout << "\nA vez agora é de " << Jogador2.Apelido << ":\n" << Jogador2.Apelido << endl;
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

    //fazer o if
    //Jogador1.showRanking(gameMode, jogadoresVector);
    
    t.liberaMemoria();
  }

  //jogo campo minado
  if (gameMode == 4) {
    cout << "\nCampo Minado foi escolhido.\n" << endl;

  //menuJogo(gameMode);
  }

  return 0;
}

void antiUsuario(int &a) { // confere se as entradas fornecidas pelo usuário não quebram o código
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
    cout << "ERRO: não foi possível abrir o arquivo Jogadores.txt" << endl;
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

void cadastrarJogadores(Jogadores &Jogador, vector<Jogadores> &jogadoresVector) {
  while (1) {
    cout << "Você deseja "
            "entrar em uma conta (1)"
            " ou "
            "criar uma conta (2)"
            "?";
    cout << endl;
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
      cout << "\nInsira seu nickname: ";
      cin >> str;
      cout << endl;
      if (aux.pesquisaJogador(str)) {
        aux.signIn(str, jogadoresVector);
        Jogador = aux;
        break;
      } else {
        cout << "\nEsse jogador não existe. Tente novamente.\n" << endl;
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