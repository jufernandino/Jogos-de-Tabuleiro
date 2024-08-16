#include "Jogadores.hpp"
#include "Tabuleiro.hpp"
#include "TicTacToe.hpp"
#include "lig4.hpp"
#include "Reversi.hpp"
#include "CampoMinado.hpp"
#include "Memoria.hpp"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

void antiUsuario(int &a);
void menuFimDeJogo(const char &jogoEscolhido,
                   vector<Jogadores> &jogadoresVector, Jogadores *pJogador1);
void voltarMenuPrincipal();

class badInputs : public exception
{
public:
  string _input;

  badInputs(string input) : _input(input) {}

  virtual const char *what() const throw() { return "ERRO: comando inválido"; }
};

int main()
{

  vector<Jogadores> jogadoresVector;

  Jogadores Jogador1, Jogador2;

  // ponteiros auxiliares
  Jogadores *pJogador1 = &Jogador1;
  // Jogadores *pJogador2 = &Jogador2;

  pJogador1->carregarJogadores(jogadoresVector);

  bool continuarJogando = true;

  // menu principal
  while (continuarJogando)
  {
    cout << "\n--------\nMENU PRINCIPAL\n--------\n\nOlá! Digite o comando "
            "desejado para iniciar o programa:\n\n"
         << "CJ - Cadastrar jogadores\n"
         << "RJ - Remover jogador\n"
         << "LJ - Listar jogadores por (A) apelido ou (N) nome\n"
         << "EP - Executar partida\n"
         << "FS - Finalizar sistema" << endl;

    string entrada;
    getline(cin, entrada);
    stringstream ss(entrada);
    char jogoEscolhido;
    string comando;

    try
    {
      comando = "";
      ss >> comando;
      // while ((getchar()) != '\n')
      // cout << "passei do cin" << endl;
      if (comando.length() != 2)
      {
        throw badInputs(comando);
      }
      else if (isdigit(comando[0]) || isdigit(comando[1]))
      {
        // throw no(comando);
        // } else {
        //  cout << "entrei no else" << endl;
        //  break;
      }
    }
    catch (badInputs &e)
    {
      // cout << "entrei no catch" << endl;
      cout << e.what() << endl;
    }
    catch (exception &e)
    {
      cout << e.what() << endl;
    }

    if (comando == "CJ" || comando == "cj")
    {
      string apelido, nome;

      try
      {
        ss >> apelido >> nome;

        for (long unsigned int i = 0; i < nome.length(); i++)
        {
          if (isdigit(nome[i]))
          {
            throw badInputs(nome);
          }
        }

        if (apelido.empty())
        {
          throw badInputs(apelido);
        }
        else if (nome.empty())
        {
          throw badInputs(nome);
        }
      }
      catch (badInputs &e)
      {
        cout << e.what() << endl;
        continue;
      }
      catch (exception &e)
      {
        cout << e.what() << endl;
        continue;
      }

      // if (apelido.empty() || nome.empty()) {
      //   cout << "\nERRO: dados incorretos" << endl; // comando inválido
      //   cout << "Tente novamente!" << endl;
      //   continue;
      // }

      pJogador1->cadastrarJogadores(apelido, nome, Jogador1, jogadoresVector);
      voltarMenuPrincipal();
      continue; // coloquei continue nos comandos
    }
    else if (comando == "RJ" || comando == "rj")
    {
      string apelido;

      try
      {
        ss >> apelido;

        /*for (int i = 0; i < apelido.length(); i++) {
          if (isdigit(apelido[i])) {
            throw badInputs(apelido);
          }
        }*/

        for (long unsigned int i = 0; i < apelido.length(); i++)
        {
          if (isblank(apelido[i]))
          {
            throw badInputs(apelido);
          }
        }

        if (apelido.empty())
        {
          throw badInputs(apelido);
          //} else {
          // break;
        }

        pJogador1->removeJogador(jogadoresVector, apelido);
      }
      catch (badInputs &e)
      {
        cout << e.what() << endl;
        return 1;
      }
      catch (exception &e)
      {
        cout << e.what() << endl;
        return 1;
      }

      // if (apelido.empty()) {
      //   cout << "\nERRO: comando inválido" << endl;
      //   continue;
      // }

      voltarMenuPrincipal();
      continue;
    }
    else if (comando == "LJ" || comando == "lj")
    {
      string ordenacao = "\0"; // string nula

      // pode ser uma exceção
      // isblank para detectar se o char é \t ou ' '
      // if (ordenacao == '\0') {
      //   cout << "\nERRO: comando inválido" << endl;
      //   continue;
      // }

      try
      {
        ss >> ordenacao;
        if (ordenacao == "\0")
        {
          throw badInputs(ordenacao);
        }
        else if (isblank(ordenacao[0]))
        {
          throw badInputs(ordenacao);
        }
        else if (isdigit(ordenacao[0]))
        {
          throw badInputs(ordenacao);
        }
        else if (ordenacao.length() != 1)
        {
          throw badInputs(ordenacao);
          //} else {
          // break;
        }
      }
      catch (badInputs &e)
      {
        cout << e.what() << endl;
      }
      catch (exception &e)
      {
        cout << e.what() << endl;
      }

      pJogador1->mostrarEstatisticas(jogadoresVector, ordenacao);
      voltarMenuPrincipal();
    }
    else if (comando == "EP" || comando == "ep")
    {
      string aux;
      string apelidoJogador1, apelidoJogador2;

      try
      {
        ss >> jogoEscolhido >> apelidoJogador1;

        aux = toupper(jogoEscolhido);

        for (long unsigned int i = 0; i < aux.length(); i++)
        {
          if (isdigit(aux[i]) || isblank(aux[i]))
          {
            throw badInputs(aux);
          }
        }

        for (long unsigned int i = 0; i < apelidoJogador1.length(); i++)
        {
          if (isdigit(apelidoJogador1[i]) || isblank(apelidoJogador1[i]))
          {
            throw badInputs(apelidoJogador1);
          }
        }

        if (apelidoJogador1.empty())
        {
          throw badInputs(apelidoJogador1);
        }

        bool encontrouJogador1 = Jogador1.logar(apelidoJogador1, jogadoresVector);

        if (!(encontrouJogador1))
        {
          cout << "\nERRO: dados incorretos" << endl;
          cout << "Tente novamente!" << endl;
          continue;
        }

        if (jogoEscolhido != 'C' || jogoEscolhido != 'c')
        {
          ss >> apelidoJogador2;

          for (long unsigned int i = 0; i < apelidoJogador2.length(); i++)
          {
            if (isdigit(apelidoJogador2[i]) || isblank(apelidoJogador2[i]))
            {
              throw badInputs(apelidoJogador2);
            }
          }

          if (aux.length() != 1)
          {
            throw badInputs(aux);
          }
          else
          {
            jogoEscolhido = aux[0];
          }

          if (apelidoJogador2.empty())
          {
            throw badInputs(apelidoJogador2);
          }

          bool encontrouJogador2 = Jogador2.logar(apelidoJogador2, jogadoresVector);

          if (!(encontrouJogador2))
          {
            cout << "\nERRO: dados incorretos" << endl;
            cout << "Tente novamente!" << endl;
            continue;
          }
        }
      }
      catch (badInputs &e)
      {
        cout << e.what() << endl;
      }
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
        cout << "\nTurno de jogador "
             << (jogadorAtual % 2 == 0 ? Jogador1.Apelido : Jogador2.Apelido)
             << ":\n"
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
        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
      }
      else if (ganhador == 2)
      {
        cout << Jogador2.Apelido << " ganhou!" << endl;
        Jogador2.victory = true;
        Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
      }
      else if (ganhador == 3)
      {
        cout << "Empate!" << endl;
        Jogador1.empate = true;
        Jogador2.empate = true;

        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
      }

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
        cout << "\nTurno de jogador "
             << (jogadorAtual % 2 == 0 ? Jogador1.Apelido : Jogador2.Apelido)
             << ":\n"
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

          Jogador1.empate = true;
          Jogador2.empate = true;

          Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
          Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
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
        cout << "\nTurno de jogador "
             << (jogadorAtual % 2 == 0 ? Jogador1.Apelido : Jogador2.Apelido)
             << ":\n"
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
          Jogador1.empate = true;
          Jogador2.empate = true;

          Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
          Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
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

      CampoMinado c;

      if (c.jogarCampoMinado() == 1)
      {
        Jogador1.victory = true;
      }
      
      Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
      c.liberaMemoria();
      menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);
    }

    // Jogo da Memoria
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
        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
      }
      else if (ganhador == 2)
      {
        cout << Jogador2.Apelido << " ganhou!" << endl;
        Jogador2.victory = true;
        Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
      }
      else if (ganhador == 3)
      {
        cout << "Empate!" << endl;
        Jogador1.empate = true;
        Jogador2.empate = true;

        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        Jogador2.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
      }

      m.liberaMemoria();
      menuFimDeJogo(jogoEscolhido, jogadoresVector, pJogador1);
    }
    else if (comando == "FS" || comando == "fs")
    {
      continuarJogando = false;
    }
  }

  return 0;
}

// transformar em exceção, coordenadas de entradas precisam ser lidas em linha
// única e não cada uma de uma vez separadas

void antiUsuario(int &a)
{ // confere se as entradas fornecidas pelo usuário
  // não quebram o código
  string aux = "";

  while (1)
  {
    cin >> aux;
    while ((getchar()) != '\n')

      if (aux.length() != 1)
      {
        cout << "ERRO: formato incorreto" << endl;
        continue;
      }

    if (!isdigit(aux[0]))
    {
      cout << "ERRO: formato incorreto" << endl;
      continue;
    }

    if (isdigit(aux[0]))
    {
      a = stoi(aux, nullptr, 10);
      break;
    }
  }
}

void menuFimDeJogo(const char &jogoEscolhido,
                   vector<Jogadores> &jogadoresVector, Jogadores *pJogador1)
{

  string opcaoMenu;
  string aux;

  while (1)
  {
    cout << "\nFIM DE JOGO! \n\nVR - Visualizar ranking\nJN - Jogar novamente" << endl;

    try
    {
      cin >> aux;

      if (aux.length() != 2 || !isalpha(aux[0]) || !isalpha(aux[1]))
      {
        throw badInputs(aux);
      }

      opcaoMenu = toupper(aux[0]);

      if (opcaoMenu == "V")
      {
        if (aux[1] != 'R')
        {
          throw badInputs(aux);
        }
        pJogador1->mostrarRanking(jogoEscolhido, jogadoresVector);

        cout << "\nJN - Jogar novamente \nFS - Encerrar programa" << endl;
        cin >> aux;

        if (aux.length() != 2 || !isalpha(aux[0]) || !isalpha(aux[1]))
        {
          throw badInputs(aux);
        }

        opcaoMenu = toupper(aux[0]);

        if (opcaoMenu == "J")
        {
          if (aux[1] != 'N')
          {
            throw badInputs(aux);
          }
          return;
        }
        else if (opcaoMenu == "F")
        {
          if (aux[1] != 'S')
          {
            throw badInputs(aux);
          }
          exit(0);
        }
        else
        {
          throw badInputs(aux);
        }
      }
      else if (opcaoMenu == "J")
      {
        if (aux[1] != 'N')
        {
          throw badInputs(aux);
        }
        return;
      }
      else
      {
        throw badInputs(aux);
      }
    }
    catch (badInputs &e)
    {
      cout << e.what() << endl;
    }
    catch (exception &e)
    {
      cout << e.what() << endl;
    }
  }
}

void voltarMenuPrincipal()
{
  cout << "\nDeseja voltar ao menu principal?\nS- Sim\nN- Não, encerrar "
          "programa"
       << endl;

  string aux;
  char resposta;

  try
  {
    cin >> aux;

    for (long unsigned int i = 0; i < aux.length(); i++)
    {
      if (isdigit(aux[i]) || isblank(aux[i]))
      {
        throw badInputs(aux);
      }
    }

    if (aux.empty())
    {
      throw badInputs(aux);
    }

    if (aux.length() != 1)
    {
      throw badInputs(aux);
    }
    else
    {
      resposta = toupper(aux[0]);
    }
  }
  catch (badInputs &e)
  {
    cout << e.what() << endl;
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  if (resposta == 'S')
  {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // coloquei isso para limpar o buffer
    return;
  }
  else if (resposta == 'N')
  {
    exit(0);
  }
}