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
#include <sstream>

using namespace std;

/* 
void to_lower(string &s) {
  int len = s.size();
  for (int i = 0; i < len; i++) {
  s[i] = tolower(s[i]);
}
} 
*/

void antiUsuario(int &a);
//void showEstatisticas();
//void loadJogadores(vector<Jogadores> &jogadoresVector);
//void cadastrarJogadores(Jogadores &Jogador, vector<Jogadores> &jogadoresVector);
//void cadastrarJogadores(Jogadores &Jogador, vector<Jogadores> &jogadoresVector);
//void showRanking (const int &jogoEscolhido, vector<Jogadores> &jogadoresVector);
void menuFimDeJogo(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector, Jogadores *pJogador1);

int main() {

  vector<Jogadores> jogadoresVector;

  Jogadores Jogador1, Jogador2;

  //ponteiros auxiliares
  Jogadores *pJogador1 = &Jogador1;
  //Jogadores *pJogador2 = &Jogador2; //pra parar de dar esse warning coisa chata vei kkkkk
  
  pJogador1 -> loadJogadores(jogadoresVector);
  
  //bool opcaoVoltar = false;

  bool continuarJogando = true;
  
  //menu principal

  cout << "\n--------\nMENU PRINCIPAL\n--------\n\nOlá! Digite o comando desejado para iniciar o programa\n\n"
     << "CJ - Cadastrar jogadores\n"
     << "RJ - Remover jogador\n"
     << "LJ - Listar jogadores por apelido ou nome\n"
     << "EP - Executar partida\n"
     << "FN - Finalizar sistema" << endl;
  
string entrada;

  while (continuarJogando) {
    getline(cin, entrada); //recebe a entrada inteira

    stringstream ss(entrada); //divide a entrada
    string comando;
    ss >> comando; //extração do primeiro item da entrada
      
      if (comando == "CJ") {
        string apelido, nome;
        ss >> apelido >> nome;
    
        pJogador1 -> cadastrarJogadores(Jogador1, jogadoresVector);
        //pJogador2 -> cadastrarJogadores(Jogador2, jogadoresVector);
          
      } else if (comando == "RJ") {
        ///cout << "Digite o apelido que deseja remover" << endl;
        string apelido;
        cin >> apelido;
        
        pJogador1 -> removeJogador(jogadoresVector, apelido); //tem que passar o apelido aqui
      
      } else if (comando == "LJ") {
        char ordenacao;
        ss >> ordenacao;
        cout << "Digite 'A' se quer ordernar a lista de jogador por apelido ou 'N' para ordenar por nome" << endl;  
        char ordem;
        cin >> ordem;
        
        pJogador1 -> showEstatisticas(jogadoresVector, ordenacao, ordem);
        
      } else if (comando == "EP") {
        char jogoEscolhido;
        string apelidoJogador1, apelidoJogador2;
        
        ss >> jogoEscolhido >> apelidoJogador1 >> apelidoJogador2;

        bool encontrouJogador1 = Jogador1.logar(apelidoJogador1, jogadoresVector);
        bool encontrouJogador2 = Jogador2.logar(apelidoJogador2, jogadoresVector);

        if (!(encontrouJogador1 && encontrouJogador2)) {
          cout << "ERRO: dados incorretos" << endl;
        }

        while (continuarJogando) {
          
        //jogo reversi
          if((jogoEscolhido == 'R')) {
            cout << "\nReversi foi escolhido." << endl;

            Reversi r;
            
            r.showRegras(jogoEscolhido);
            r.criaTabuleiro();
            r.inicializarJogo();
            r.imprimeTabuleiro();

            int jogadorAtual = 0;

            do {
              char z = ' ';
              if (jogadorAtual % 2 == 0) {
                z = 'X';
                cout << "\nTurno de jogador " << Jogador1.Apelido << ":\n" << endl;
              }
              if (jogadorAtual % 2 != 0) {
                z = 'O';
                cout << "\nTurno de jogador " << Jogador2.Apelido << ":\n" << endl;
              }

              r.mostrarLocaisJogada(z);

              int x, y;

              antiUsuario(x);
              antiUsuario(y);

              if (r.ehJogadaValida(x, y, z)) {
                  r.validaJogada(x, y, z);
                  r.imprimeTabuleiro();             
                  jogadorAtual++;                     
                } else {
                  cout << "ERRO: jogada inválida" << endl;
                  continue;
                }
            } while (!r.verificarFimDeJogo());

            if(r.confereGanhador() == 1) {
              cout << Jogador1.Apelido << " ganhou!" << endl;
              Jogador1.victory = true;

              Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
              Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);

            } else if (r.confereGanhador() == 2) {
              cout << Jogador2.Apelido << " ganhou!" << endl;
              Jogador2.victory = true;

              Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
              Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);

            } else if (r.confereGanhador() == 3) {
              cout << "Empate!" << endl;
            }

            r.liberaMemoria();
            menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);

        //jogo lig4
        } else if ((jogoEscolhido == 'L')) {
        cout << "\nLig4 foi escolhido." << endl;

        int x = 0, y = 0;
        string aux;
        
        lig4 l;

        l.showRegras(jogoEscolhido);
        l.criaTabuleiro();
        l.imprimeTabuleiro();
      
        int jogadorAtual = 0;
      
        while (1) {
          char z = ' ';
          if (jogadorAtual % 2 == 0) {
            z = 'X';
            cout << "\nTurno de jogador " << Jogador1.Apelido << ":\n" << endl;
          }
          if (jogadorAtual % 2 != 0) {
            z = 'O';
            cout << "\nTurno de jogador " << Jogador2.Apelido << ":\n" << endl;
          }
      
          antiUsuario(y);
      
          l.validaJogada(x, y, z);
      
          l.imprimeTabuleiro();
      
          if (l.confereGanhador() == 1) {
            cout << Jogador1.Apelido << " ganhou!" << endl;
            Jogador1.victory = true;
            Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            break;
          }
          
          if (l.confereGanhador() == 2) {
            cout << Jogador2.Apelido << " ganhou!" << endl;
            Jogador2.victory = true;
            Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            break;
          }
          
          if (l.confereGanhador() == 3) {
            cout << "Empate!" << endl;
            break;
          }
          jogadorAtual++;
        }
        
        l.liberaMemoria();
        menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);

      //jogo tic tac toe
      } else if ((jogoEscolhido == 'T')) {
          cout << "\nTicTacToe foi escolhido." << endl;

          int x = 0, y = 0;
          TicTacToe t;
    
    
          t.showRegras(jogoEscolhido);
          t.criaTabuleiro();
          t.imprimeTabuleiro();
    
          int jogadorAtual = 0;
    
          while (1) {
    
            char z = ' ';
            if (jogadorAtual % 2 == 0) {
              z = 'X';
              cout << "\nTurno de jogador " << Jogador1.Apelido << ":\n" << endl;
            }
            if (jogadorAtual % 2 != 0) {
              z = 'O';
              cout << "\nTurno de jogador " << Jogador2.Apelido << ":\n" << endl;
            }
    
            antiUsuario(x);
            antiUsuario(y);
    
            t.validaJogada(x, y, z);
    
            t.imprimeTabuleiro();
    
            if (t.confereGanhador() == 1) {
              cout << Jogador1.Apelido << " ganhou!" << endl;
              Jogador1.victory = true;
              Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
              Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
              break;
            }
            if (t.confereGanhador() == 2) {
              cout << Jogador2.Apelido << " ganhou!" << endl;
              Jogador2.victory = true;
              Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
              Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
              break;
            }
            if (t.confereGanhador() == 3) {
              cout << "Não há vencedores!" << endl;
              break;
            }
            jogadorAtual++;
          }
    
          t.liberaMemoria();
          menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);

        //jogo campo minado
        } else if ((jogoEscolhido == 'C')) {
        
        menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);
        
        } else if (comando == "FS") {
        continuarJogando = false;
        }
      }
  }
  }

  return 0;
}

  
  /*
  
  do {
    char opcaoMenu = '0';
    cout << "\n--------\nMENU PRINCIPAL\n--------\n\nOlá! Vamos jogar? \n\nJogar (1) \nConsultar estatísticas dos jogadores (2)"
         << endl;

    cin >> opcaoMenu;

    while (1) {
      if (opcaoMenu != '1' && opcaoMenu != '2') {
        cout << "\nERRO: opção inválida! Tente novamente.\n" << endl;
        cin >> opcaoMenu;
      } else {
        break;
      }
    }

    if (opcaoMenu == '1') {
      break;
    } else if (opcaoMenu == '2') {

      cout << "\n--------\nCONSULTAR ESTATÍSTICAS\n-------- \n" << endl;
      pJogador1 -> showEstatisticas(jogadoresVector);
      
      cout << "Para voltar ao menu principal, tecle ENTER." << endl;
      cin.ignore();
      cin.get();
      opcaoVoltar = true;

    } else {
      cout << "\nERRO: opção inválida! Tecle ENTER para voltar ao menu principal." << endl;
      cin.ignore();
      cin.get();
      opcaoVoltar = true;
    }
  } while (opcaoVoltar);

  cout << "\n--------\nJOGADORES\n--------\n" << endl;


  cout << "Para cadastrar jogadores, digite CJ: " << endl;
  string comando;
  cin >> comando;
  if(comando == "CJ"){
    cadastrarJogadores(Jogador1, jogadoresVector);
  }

  //cadastrarJogadores(Jogador1, jogadoresVector);
  // cadastrarJogadores(Jogador2, jogadoresVector);

  cout << "Qual jogo gostariam de jogar? \n\nReversi (1) \nLig4 (2) \nTicTacToe (3) \nCampo Minado (4)?\n" << endl;

  int jogoEscolhido;
  antiUsuario(jogoEscolhido);

  //jogo Reversi
  if (jogoEscolhido == 1) {
    cout << "\nReversi foi escolhido." << endl;

    Reversi r;

    r.showRegras(jogoEscolhido);
    r.criaTabuleiro();
    r.inicializarJogo();
    r.imprimeTabuleiro();

  int jogadorAtual = 0;

  do {
    char z = ' ';
    if (jogadorAtual % 2 == 0) {
      z = 'X';
      cout << "\nTurno de jogador " << Jogador1.Apelido << ":\n" << endl;
    }
    if (jogadorAtual % 2 != 0) {
      z = 'O';
      cout << "\nTurno de jogador " << Jogador2.Apelido << ":\n" << endl;
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

      Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
      Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);

    } else if (r.confereGanhador() == 2) {
      cout << Jogador2.Apelido << " ganhou!" << endl;
    Jogador2.victory = true;
    
    Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
    Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
      
    } else if (r.confereGanhador() == 3) {
        cout << "Empate!" << endl;
    }

    //fazer o if
    //Jogador1.showRanking(jogoEscolhido, jogadoresVector);
    
    r.liberaMemoria();
  }
  
  //jogo lig4
  if (jogoEscolhido == 2) {
    cout << "\nLig4 foi escolhido." << endl;

    int x = 0, y = 0;
    string aux;
    lig4 l;

    l.showRegras(jogoEscolhido);
    l.criaTabuleiro();
    l.imprimeTabuleiro();

    int jogadorAtual = 0;

    while (1) {

      char z = ' ';
      if (jogadorAtual % 2 == 0) {
        z = 'X';
        cout << "\nTurno de jogador " << Jogador1.Apelido << ":\n" << endl;
      }
      if (jogadorAtual % 2 != 0) {
        z = 'O';
        cout << "\nTurno de jogador " << Jogador2.Apelido << ":\n" << endl;
      }

      antiUsuario(y);

      l.validaJogada(x, y, z);

      l.imprimeTabuleiro();

      if (l.confereGanhador() == 1) {
        cout << Jogador1.Apelido << " ganhou!" << endl;
        Jogador1.victory = true;
        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        break;
      }
      if (l.confereGanhador() == 2) {
        cout << Jogador2.Apelido << " ganhou!" << endl;
        Jogador2.victory = true;
        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
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
  opcaoVoltar = false;
  
  //while (!(opcaoVoltar)) {
    if (jogoEscolhido == 3) {
      cout << "\nTicTacToe foi escolhido." << endl;

    int x = 0, y = 0;
    TicTacToe t;


    t.showRegras(jogoEscolhido);
    t.criaTabuleiro();
    t.imprimeTabuleiro();

    int jogadorAtual = 0;

    while (1) {

      char z = ' ';
      if (jogadorAtual % 2 == 0) {
        z = 'X';
        cout << "\nTurno de jogador " << Jogador1.Apelido << ":\n" << endl;
      }
      if (jogadorAtual % 2 != 0) {
        z = 'O';
        cout << "\nTurno de jogador " << Jogador2.Apelido << ":\n" << endl;
      }

      antiUsuario(x);
      antiUsuario(y);

      t.validaJogada(x, y, z);

      t.imprimeTabuleiro();

      if (t.confereGanhador() == 1) {
        cout << Jogador1.Apelido << " ganhou!" << endl;
        Jogador1.victory = true;
        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        break;
      }
      if (t.confereGanhador() == 2) {
        cout << Jogador2.Apelido << " ganhou!" << endl;
        Jogador2.victory = true;
        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        break;
      }
      if (t.confereGanhador() == 3) {
        cout << "Não há vencedores!" << endl;
        break;
      }
      jogadorAtual++;
    }

    t.liberaMemoria();
    
    cout << "\nFIM DE JOGO! \n\nVisualizar ranking (1) \nJogar novamente (2) \nEncerrar o programa (3)" << endl;

    char opcaoMenu;
      
    cin >> opcaoMenu;

    if (opcaoMenu == '1') {
      pJogador1 -> showRanking(jogoEscolhido, jogadoresVector);
    } else if (opcaoMenu == '2') {
      opcaoVoltar = false;
    } else if (opcaoMenu == '3') {
      opcaoVoltar = true;
    } else {
      cout << "ERRO: opção inválida!" << endl;
      //terminar aqui
    }
  }
  //}


  //jogo campo minado
  if (jogoEscolhido == 4) {
    cout << "\nCampo Minado foi escolhido.\n" << endl;

  //showRegras(jogoEscolhido);
  }

  return 0;
}
  */

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


/*
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
*/


void cadastrarJogadores(Jogadores &Jogador, vector<Jogadores> &jogadoresVector) {
  string apelido, nome;
  cin >> apelido >> nome;
  cout << endl;

  Jogadores aux;

  if (aux.pesquisaJogador(apelido)) { //se jogador já existir
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

void menuFimDeJogo(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector, Jogadores *pJogador1) {
  string opcaoMenu;
  
  cout << "\nFIM DE JOGO! \n\nVR - Visualizar ranking\nJN - Jogar novamente" << endl;

  cin >> opcaoMenu;

  if (opcaoMenu == "VR") {
    pJogador1 -> showRanking(jogoEscolhido, jogadoresVector);
    //tá voltando para o looping, adicionar aqui opções jogar novamente (só imprimir e dar um return, pq já tá voltando automático) ou encerrar programa teclando enter
} else if (opcaoMenu == "JN") {
    return; //volta fluxo programa direto onde estava
}
}
  
/*void cadastrarJogadores(Jogadores &Jogador, vector<Jogadores> &jogadoresVector) {
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
        cout << "\nERRO: dados incorretos\n" << endl;
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
}*/