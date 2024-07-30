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
    if (linha.find('(') != string::npos && linha.find(')') != string::npos) {
        if (continuar) {
            break;
        }
    }

    if (continuar) {
        regras += linha + "\n";
    }
    }

  arquivo.close();

  if (!regras.empty()) {
    cout << "\n-------- \nREGRAS DO JOGO\n-------- \n" << regras << endl;
    
    cout << "Vamos começar? Tecle ENTER para iniciar o jogo." << endl;

    cin.ignore();
    cin.get();

    cout << "\n--------\nJOGAR PARTIDA\n--------\n" << endl;
}
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
    char opcaoMenu = '0';
    cout << "\n--------\nMENU PRINCIPAL\n--------\n\nOlá! Vamos jogar? \n\nJogar (1) \nConsultar "
            "estatísticas dos jogadores (2)"
         << endl;

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

      cout << "\n--------\nCONSULTAR ESTATÍSTICAS\n-------- \n\n" << endl;
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

  cout << "\nQual jogo gostariam de jogar?, Reversi (1), Lig4 (2), TicTacToe "
          "(3) ou Campo Minado (4)?\n"
       << endl;

  int lerRegras = 0;
  bool opcaoContinuar = true;

  int gameMode;
  antiUsuario(gameMode);

  if (gameMode == 1) {
    cout << "\nReversi foi escolhido." << endl;
    
    do {
      cout << "Ler regras do jogo (1) \nJogar (2)" << endl;

      cin >> lerRegras;

      if (lerRegras == 2) {
        opcaoContinuar = false;
        cout << "\n--------\nJOGAR PARTIDA\n--------\n" << endl;
        break;
      } else if (lerRegras == 1) {
        opcaoContinuar = false;
        showRegras(gameMode);
        break;
      }
    } while (opcaoContinuar);

    Reversi r;

    r.criaTabuleiro();
    r.inicializarJogo(3, 3);
    r.inicializarJogo(4, 4);
    r.inicializarJogo(3, 4);
    r.inicializarJogo(4, 3);
    r.imprimeTabuleiro();

  do {
    int jogadorAtual = 0;
    char z = ' ';
    if (jogadorAtual % 2 == 0) {
      z = 'X';
      //cout << "\nA vez agora é de " << Jogador1.Apelido << ":\n" << endl;
    }
    if (jogadorAtual % 2 != 0) {
      z = 'O';
      //cout << "\nA vez agora é de " << Jogador2.Apelido << ":\n" << endl;
    }
    
    int x, y;

    antiUsuario(x);
    antiUsuario(y);
    
    r.validaJogada(x, y, z);
    r.imprimeTabuleiro();
    //confereGanhador
    //atualizaEstatisticas
    //showRanking
  } while (r.verificarFimDeJogo()); //do-while provisório, só para o programa rodar pelo menos 1 vez
  //acrescentar a liberaMemoria
  }
    

  if (gameMode == 2) {
    cout << "\nLig4 foi escolhido." << endl;

    do {
      cout << "Ler regras do jogo (1) \nJogar (2)" << endl;

      cin >> lerRegras;

      if (lerRegras == 2) {
        opcaoContinuar = false;
        cout << "\n--------\nJOGAR PARTIDA\n--------\n" << endl;
        break;
      } else if (lerRegras == 1) {
        opcaoContinuar = false;
        showRegras(gameMode);
        break;
      }
    } while (opcaoContinuar);

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
        //cout << "\nA vez agora é de " << Jogador1.Apelido << ":\n" << Jogador1.Apelido << " é o " << z << endl;
      }
      if (jogadorAtual % 2 != 0) {
        z = 'O';
        //cout << "\nA vez agora é de " << Jogador2.Apelido << ":\n" << Jogador2.Apelido << " é o " << z << endl;;
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

  if (gameMode == 3) {
    cout << "\nTicTacToe foi escolhido.\n" << endl;

    do {
      cout << "Ler regras do jogo (1) \nJogar (2)" << endl;

      cin >> lerRegras;

      if (lerRegras == 2) {
        opcaoContinuar = false;
        cout << "\n--------\nJOGAR PARTIDA\n--------\n" << endl;
        break;
      } else if (lerRegras == 1) {
        opcaoContinuar = false;
        showRegras(gameMode);
        break;
      }
    } while (opcaoContinuar);

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

  if (gameMode == 4) {
    cout << "\nCampo Minado foi escolhido.\n" << endl;

    do {
      cout << "Ler regras do jogo (1) \nJogar (2)" << endl;

      cin >> lerRegras;

      if (lerRegras == 2) {
        opcaoContinuar = false;
        cout << "\n--------\nJOGAR PARTIDA\n--------\n" << endl;
        break;
      } else if (lerRegras == 1) {
        opcaoContinuar = false;
        showRegras(gameMode);
        break;
      }
    } while (opcaoContinuar);
  }

  return 0;
}