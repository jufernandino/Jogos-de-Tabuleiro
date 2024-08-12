#include "Jogadores.hpp"
#include "Tabuleiro.hpp"
#include "TicTacToe.hpp"
#include "lig4.hpp"
#include "Reversi.hpp"
#include "CampoMinado.hpp"
#include "Memoria.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void antiUsuario(int &a);
void menuFimDeJogo(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector, Jogadores *pJogador1);
void voltarMenuPrincipal();

int main()
{

  vector<Jogadores> jogadoresVector;

  Jogadores Jogador1, Jogador2;

  // ponteiros auxiliares
  Jogadores *pJogador1 = &Jogador1;
  // Jogadores *pJogador2 = &Jogador2;

  pJogador1->carregarJogadores(jogadoresVector);

  bool continuarJogando = true;

  string entrada;

  // menu principal
  while (continuarJogando)
  {
    cout << "\n--------\nMENU PRINCIPAL\n--------\n\nOlá! Digite o comando desejado para iniciar o programa:\n\n"
         << "CJ - Cadastrar jogadores\n"
         << "RJ - Remover jogador\n"
         << "LJ - Listar jogadores por (A) apelido ou (N) nome\n"
         << "EP - Executar partida\n"
         << "FS - Finalizar sistema" << endl;

    getline(cin, entrada);
    stringstream ss(entrada);
    string comando;
    ss >> comando;

    if (comando == "CJ")
    {
      string apelido, nome;
      ss >> apelido >> nome;

      // pode ser uma exceção
      if (apelido.empty() || nome.empty())
      {
        cout << "\nERRO: comando inválido" << endl;
        cout << "Tente novamente!" << endl;
        continue;
      }

      pJogador1->cadastrarJogadores(apelido, nome, Jogador1, jogadoresVector);
      voltarMenuPrincipal();
    }
    else if (comando == "RJ")
    {
      string apelido;
      ss >> apelido;

      // pode ser uma exceção
      if (apelido.empty())
      {
        cout << "\nERRO: comando inválido" << endl;
        continue;
      }

      pJogador1->removeJogador(jogadoresVector, apelido);
      voltarMenuPrincipal();
    }
    else if (comando == "LJ")
    {
      char ordenacao = '\0'; // char nulo
      ss >> ordenacao;

      // pode ser uma exceção
      // isblank para detectar se o char é \t ou ' '
      if (ordenacao == '\0')
      {
        cout << "\nERRO: comando inválido" << endl;
        continue;
      }

      pJogador1->mostrarEstatisticas(jogadoresVector, ordenacao);
      voltarMenuPrincipal();
    }
    else if (comando == "EP")
    {
      char jogoEscolhido;
      string apelidoJogador1, apelidoJogador2;

      ss >> jogoEscolhido >> apelidoJogador1 >> apelidoJogador2;

      bool encontrouJogador1 = Jogador1.logar(apelidoJogador1, jogadoresVector);
      bool encontrouJogador2 = Jogador2.logar(apelidoJogador2, jogadoresVector);

      // pode ser uma exceção
      if (apelidoJogador1.empty() || apelidoJogador2.empty())
      {
        cout << "\nERRO: comando inválido" << endl;
        cout << "Tente novamente!" << endl;
        continue;
      }

      // pode ser uma exceção
      if (!(encontrouJogador1 && encontrouJogador2))
      {
        cout << "\nERRO: dados incorretos" << endl;
        cout << "Tente novamente!" << endl;
        continue;
      }

      // reversi
      if (jogoEscolhido == 'R')
      {
        cout << "\nReversi foi escolhido." << endl;
        Reversi r;
        r.mostrarRegras(jogoEscolhido);
        r.criaTabuleiro();
        r.inicializarJogo();
        r.imprimirTabuleiro();

        int jogadorAtual = 0;
        do
        {
          char z = (jogadorAtual % 2 == 0) ? 'X' : 'O';
          cout << "\nTurno de jogador " << (jogadorAtual % 2 == 0 ? Jogador1.Apelido : Jogador2.Apelido) << ":\n"
               << endl;
          if (r.existeMovimentoPossivel(z) == true)
          {
            r.mostrarLocaisJogada(z);
            int x, y;
            antiUsuario(x);
            antiUsuario(y);

            if (r.ehJogadaValida(x, y, z))
            {
              r.validaJogada(x, y, z);
              r.imprimirTabuleiro();
              jogadorAtual++;
            }
            else
            {
              cout << "ERRO: jogada inválida" << endl;
              continue;
            }
          }
          else if (r.existeMovimentoPossivel(z) == false)
          {
            cout << "Não existem jogadas possíveis no momento" << endl;
            cout << "Pulando turno para próximo jogador" << endl;
            jogadorAtual++;
          }
        } while (!r.verificarFimDeJogo());

        int ganhador = r.confereGanhador();
        if (ganhador == 1)
        {
          cout << Jogador1.Apelido << " ganhou!" << endl;
          Jogador1.victory = true;
        }
        else if (ganhador == 2)
        {
          cout << Jogador2.Apelido << " ganhou!" << endl;
          Jogador2.victory = true;
        }
        else if (ganhador == 3)
        {
          cout << "Empate!" << endl;
        }

        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        r.liberaMemoria();
        menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);

        // lig4
      }
      else if (jogoEscolhido == 'L')
      {
        cout << "\nLig4 foi escolhido." << endl;
        lig4 l;
        l.mostrarRegras(jogoEscolhido);
        l.criaTabuleiro();
        l.imprimirTabuleiro();

        int jogadorAtual = 0;
        while (true)
        {
          char z = (jogadorAtual % 2 == 0) ? 'X' : 'O';
          cout << "\nTurno de jogador " << (jogadorAtual % 2 == 0 ? Jogador1.Apelido : Jogador2.Apelido) << ":\n"
               << endl;

          int y;
          antiUsuario(y);

          l.validaJogada(0, y, z);
          l.imprimirTabuleiro();

          int ganhador = l.confereGanhador();
          if (ganhador == 1)
          {
            cout << Jogador1.Apelido << " ganhou!" << endl;
            Jogador1.victory = true;
            Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            break;
          }
          else if (ganhador == 2)
          {
            cout << Jogador2.Apelido << " ganhou!" << endl;
            Jogador2.victory = true;
            Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            break;
          }
          else if (ganhador == 3)
          {
            cout << "Empate!" << endl;
            break;
          }
          jogadorAtual++;
        }

        l.liberaMemoria();
        menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);

        // tictactoe
      }
      else if (jogoEscolhido == 'T')
      {
        cout << "\nTicTacToe foi escolhido." << endl;
        TicTacToe t;
        t.mostrarRegras(jogoEscolhido);
        t.criaTabuleiro();
        t.imprimirTabuleiro();

        int jogadorAtual = 0;
        while (true)
        {
          char z = (jogadorAtual % 2 == 0) ? 'X' : 'O';
          cout << "\nTurno de jogador " << (jogadorAtual % 2 == 0 ? Jogador1.Apelido : Jogador2.Apelido) << ":\n"
               << endl;

          int x, y;
          antiUsuario(x);
          antiUsuario(y);

          t.validaJogada(x, y, z);
          t.imprimirTabuleiro();

          int ganhador = t.confereGanhador();
          if (ganhador == 1)
          {
            cout << Jogador1.Apelido << " ganhou!" << endl;
            Jogador1.victory = true;
            Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            break;
          }
          else if (ganhador == 2)
          {
            cout << Jogador2.Apelido << " ganhou!" << endl;
            Jogador2.victory = true;
            Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
            break;
          }
          else if (ganhador == 3)
          {
            cout << "Não há vencedores! Deu velha!" << endl;
            break;
          }
          jogadorAtual++;
        }

        t.liberaMemoria();
        menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);

        // campo minado
      }
      else if (jogoEscolhido == 'C')
      {
        cout << "\nCampo Minado foi escolhido." << endl;

        menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);
        // memoria
      }
      else if (jogoEscolhido == 'M')
      {
        cout << "\nJogo da Memória foi escolhido." << endl;
        Memoria m;
        m.mostrarRegras(jogoEscolhido);
        m.criaTabuleiro();
        m.imprimirTabuleiro();

        int jogadorAtual = 0;
        do
        {
          char z = (jogadorAtual % 2 == 0) ? '1' : '2';
          cout << "\nTurno de jogador " << (jogadorAtual % 2 == 0 ? Jogador1.Apelido : Jogador2.Apelido) << ":\n"
               << endl;
          cout << "Escolha as coordenadas para duas posições" << endl;
          int x, y, x2, y2;
          antiUsuario(x);
          antiUsuario(y);
          antiUsuario(x2);
          antiUsuario(y2);

          if (m.ehJogadaValida(x, y, x2, y2, z))
          {
            // 1º) mostra os simbolos das duas posições escolhidas
            m.validaJogada(x, y, x2, y2, z);
            m.imprimirTabuleiro();
            // 2º) se o jogador encontrar os pares, os pares são validados ele joga novamente
            if (m.formamPares(x, y, x2, y2, z) == true)
            {
              m.validaPares(x, y, x2, y2, z);
            } // 3º) se o jogador não encontrar os pares, limpa o tabuleiro e é a vez do próximo jogador
            else if (m.formamPares(x, y, x2, y2, z) == false)
            {
              m.validaPares(x, y, x2, y2, z);
              m.imprimirTabuleiro();
              jogadorAtual++;
            }
          }
          else
          {
            cout << "ERRO: jogada inválida" << endl;
            continue;
          }

        } while (!m.verificarFimDeJogo());

        int ganhador = m.confereGanhador();
        if (ganhador == 1)
        {
          cout << Jogador1.Apelido << " ganhou!" << endl;
          Jogador1.victory = true;
        }
        else if (ganhador == 2)
        {
          cout << Jogador2.Apelido << " ganhou!" << endl;
          Jogador2.victory = true;
        }
        else if (ganhador == 3)
        {
          cout << "Empate!" << endl;
        }

        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        m.liberaMemoria();
        menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);
      }
    }
    else if (comando == "FS")
    {
      continuarJogando = false;
    }
  }
  return 0;
}

// transformar em exceção
void antiUsuario(int &a)
{ // confere se as entradas fornecidas pelo usuário não quebram o código
  string aux = "";

  while (1)
  {
    cin >> aux;
    while ((getchar()) != '\n')

      if (aux.length() != 1)
      {
        cout << "ERRO: coordenadas inválidas" << endl;
        continue;
      }

    if (!isdigit(aux[0]))
    {
      cout << "ERRO: coordenadas inválidas" << endl;
      continue;
    }

    if (isdigit(aux[0]))
    {
      a = stoi(aux, nullptr, 10);
      break;
    }
  }
}

void menuFimDeJogo(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector, Jogadores *pJogador1)
{

  string opcaoMenu;

  while (1)
  {
    cout << "\nFIM DE JOGO! \n\nVR - Visualizar ranking\nJN - Jogar novamente" << endl;

    cin >> opcaoMenu;

    if (opcaoMenu == "VR")
    {
      pJogador1->mostrarRanking(jogoEscolhido, jogadoresVector);

      cout << "\nJN - Jogar novamente \nFS - Encerrar programa" << endl;
      cin >> opcaoMenu;

      if (opcaoMenu == "JN")
      {
        return;
      }
      else if (opcaoMenu == "FS")
      {
        exit(0);
      }
    }
    else if (opcaoMenu == "JN")
    {
      return;
    }
  }
}

void voltarMenuPrincipal()
{
  cout << "\nDeseja voltar ao menu principal?\nS- Sim\nN- Não, encerrar programa" << endl;
  char resposta;
  cin >> resposta;

  if (resposta == 'S')
  {
    return;
  }
  else if (resposta == 'N')
  {
    exit(0);
  }
}