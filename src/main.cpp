/**
 * @file main.cpp
 * @brief Programa de gerenciamento de jogos e jogadores.
 *
 * Este programa permite cadastrar, listar e remover jogadores, além de executar
 * partidas de diferentes jogos (Reversi, Lig4, TicTacToe, Campo Minado e Jogo
 * da Memória).
 */

#include "CampoMinado.hpp"
#include "Jogadores.hpp"
#include "Memoria.hpp"
#include "Reversi.hpp"
#include "Tabuleiro.hpp"
#include "TicTacToe.hpp"
#include "lig4.hpp"
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Função que verifica e corrige entradas inválidas do usuário.
 *
 * @param a Referência para o inteiro a ser preenchido com a entrada válida.
 */
void antiUsuario(int &a);

/**
 * @brief Exibe o menu final após o término de um jogo.
 *
 * @param jogoEscolhido Caracter que identifica o jogo escolhido.
 * @param jogadoresVector Vetor contendo os jogadores cadastrados.
 * @param pJogador1 Ponteiro para o primeiro jogador.
 */
void menuFimDeJogo(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector);

/**
 * @brief Pergunta ao usuário se deseja voltar ao menu principal ou encerrar o
 * programa.
 */
void voltarMenuPrincipal();

/**
 * @class badInputs
 * @brief Classe de exceção para entradas inválidas do usuário.
 */
class badInputs : public exception
{
public:
  string _input;

  /**
   * @brief Construtor da classe badInputs.
   *
   * @param input String que contém a entrada inválida.
   */

  badInputs(string input) : _input(input) {}

  /**
   * @brief Retorna uma mensagem de erro.
   *
   * @return Mensagem de erro.
   */
  virtual const char *what() const throw() { return "ERRO: entrada inválida"; }
};

/**
 * @brief Função principal do programa.
 *
 * Esta função exibe o menu principal e gerencia as opções de cadastro, remoção,
 * listagem de jogadores e execução de partidas.
 *
 * @return Retorna 0 se o programa for encerrado corretamente.
 */
int main()
{

  vector<Jogadores> jogadoresVector;

  Jogadores::carregarJogadores(jogadoresVector);

  Jogadores Jogador1, Jogador2;

  
  while (1) {
  {
    }
    cout << "\n--------\nMENU PRINCIPAL\n--------\n\nOlá! Digite o comando "
            "desejado para iniciar o programa:\n\n"
         << "CJ - Cadastrar jogadores no formato <apelido> <Nome> (apelido em minúscula)\n"
         << "RJ - Remover jogador\n"
         << "LJ - Listar jogadores por (A) apelido ou (N) nome\n"
         << "EP - Executar partida\n"
         << "FS - Finalizar sistema" << endl;

    string input;
    getline(cin, input, '\n');
    stringstream line(input);

    string Comando;
    string Modo;
    string Apelido;
    string Nome;
    char jogoEscolhido;
    string apelidoJogador1, apelidoJogador2;

    try
    {
      getline(line, Comando, ' ');
      for (char &c : Comando)
      {
        c = toupper(c);
      }

      if (Comando.length() != 2)
      {
        throw badInputs(Comando);
      }

      for (long unsigned int i = 0; i < Comando.length(); i++)
      {
        if (isdigit(Comando[i]) || !isalpha(Comando[i]) ||
            isblank(Comando[i]))
        {
          throw badInputs(Comando);
        }
      }
    }
    catch (badInputs &e)
    {
      cout << e.what() << endl;
      continue;
    }

    if (Comando[0] == 'C' && Comando[1] == 'J')
    {

      try
      {
        getline(line, Apelido, ' ');
        for (char &a : Apelido)
        {
          a = tolower(a);
        }
        if (Apelido.empty())
        {
          throw badInputs(Apelido);
        }
        getline(line, Nome, '\n');
        if (Nome.empty())
        {
          throw badInputs(Nome);
        }
      }
      catch (badInputs &e)
      {
        cout << e.what() << endl;
        continue;
      }

      Jogadores jogadorAuxiliar;

      Jogadores::cadastrarJogadores(Apelido, Nome, jogadorAuxiliar, jogadoresVector);
    }

    if (Comando[0] == 'R' && Comando[1] == 'J')
    {

      try
      {
        getline(line, Apelido, ' ');
        for (char &a : Apelido)
        {
          a = tolower(a);
        }
        if (Apelido.empty())
        {
          throw badInputs(Apelido);
        }
      }
      catch (badInputs &e)
      {
        cout << e.what() << endl;
        continue;
      }

      if (Jogadores::pesquisaJogador(Apelido))
      {
        Jogadores::removeJogador(jogadoresVector, Apelido);
      }
      else
      {
        cout << "ERRO: jogador não encontrado" << endl;
      }

      voltarMenuPrincipal();
    }

    if (Comando[0] == 'L' && Comando[1] == 'J')
    {

      try
      {
        getline(line, Modo, '\n');
        if (Modo.empty())
        {
          throw badInputs(Modo);
        }
      }
      catch (badInputs &e)
      {
        cout << e.what() << endl;
        continue;
      }

      Jogadores::mostrarEstatisticas(jogadoresVector, Modo);
      voltarMenuPrincipal();
    }

    if (Comando[0] == 'E' && Comando[1] == 'P')
    {
      string aux;
      try
      {
        getline(line, aux, ' ');
        for (char &c : aux)
        {
          c = toupper(c);
        }
        if (aux.empty())
        {
          throw badInputs(Apelido);
        }
        else if (aux.length() != 1)
        {
          throw badInputs(Apelido);
        }
        else if (isdigit(aux[0]) || !isalpha(aux[0]))
        {
          throw badInputs(Apelido);
        }

        getline(line, apelidoJogador1, ' ');
        for (char &a : apelidoJogador1)
        {
          a = tolower(a);
        }
        if (apelidoJogador1.empty())
        {
          throw badInputs(Apelido);
        }

        getline(line, apelidoJogador2, ' ');
        for (char &a : apelidoJogador2)
        {
          a = tolower(a);
        }
        if (apelidoJogador2.empty() && aux[0] != 'C')
        {
          cout << "São necessários dois jogadores para jogar este jogo."
               << endl;
          throw badInputs(Apelido);
        }
        else if (!(apelidoJogador2.empty()) && aux[0] == 'C')
        {
          cout << "Este jogo só possui um jogador" << endl;
          throw badInputs(Apelido);
        }
      }
      catch (badInputs &e)
      {
        cout << e.what() << endl;
        continue;
      }

      jogoEscolhido = toupper(aux[0]);

      if (!Jogadores::pesquisaJogador(apelidoJogador1))
      {
        cout << "ERRO: primeiro jogador não encontrado" << endl;
        continue;
      }
      else
      {
        Jogador1.logIn(apelidoJogador1, jogadoresVector);
        cout << Jogador1.Apelido << " fez log in!" << endl;
      }

      if (jogoEscolhido != 'C' &&
          !Jogadores::pesquisaJogador(apelidoJogador2))
      {
        cout << "ERRO: segundo jogador não encontrado" << endl;
        continue;
      }
      else if (!apelidoJogador2.empty())
      {
        Jogador2.logIn(apelidoJogador2, jogadoresVector);
        cout << Jogador2.Apelido << " fez log in!" << endl;
      }

      if (jogoEscolhido == 'R')
      {
        cout << "\nReversi foi escolhido!" << endl;
        Reversi r;
        r.mostrarRegras(jogoEscolhido);
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
        }

        r.liberaMemoria();
        menuFimDeJogo(jogoEscolhido, jogadoresVector);
      }
      else if (jogoEscolhido == 'L')
      {
        cout << "\nLig4 foi escolhido." << endl;
        lig4 l;
        l.mostrarRegras(jogoEscolhido);
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
            break;
          }
          jogadorAtual++;
        }

        l.liberaMemoria();
        menuFimDeJogo(jogoEscolhido, jogadoresVector);
      }
      else if (jogoEscolhido == 'T')
      {
        cout << "\nTicTacToe foi escolhido!" << endl;
        TicTacToe t;
        t.mostrarRegras(jogoEscolhido);
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
            break;
          }
          jogadorAtual++;
        }

        t.liberaMemoria();
        menuFimDeJogo(jogoEscolhido, jogadoresVector);
      }
      else if (jogoEscolhido == 'C')
      {
        cout << "\nCampo Minado foi escolhido!" << endl;
        CampoMinado c;
        c.mostrarRegras(jogoEscolhido);
        c.imprimirTabuleiro();
        bool ganhou_campo_minado = false;

        while (1)
        {
          cout << "Escreva as coordenadas no formato:\nlinha\ncoluna\n" << endl;

          int chute_linha, chute_coluna;
          antiUsuario(chute_linha);
          antiUsuario(chute_coluna);

          if (!c.validaJogadaCampoMinado(chute_linha, chute_coluna))
          {
            cout << "ERRO: jogada inválida" << endl;
          }

          if (c.escolheuBomba(chute_linha, chute_coluna))
          {
            cout << "BOOM! Você perdeu!" << endl;
            break;
          }

          if (c.confereGanhador())
          {
            cout << "Parabéns! Você ganhou!" << endl;
            ganhou_campo_minado = true;
            break;
          }

          c.minasAdj(chute_linha, chute_coluna);
          c.revelaCelula(chute_linha, chute_coluna);
          c.imprimirTabuleiro();
        }

        if (ganhou_campo_minado)
        {
          Jogador1.victory = true;
        }

        Jogador1.atualizaEstatisticas(jogoEscolhido, jogadoresVector);
        c.liberaMemoria();
        menuFimDeJogo(jogoEscolhido, jogadoresVector);
      }
      else if (jogoEscolhido == 'M')
      {
        cout << "\nJogo da Memória foi escolhido!" << endl;
        Memoria m;
        m.mostrarRegras(jogoEscolhido);
        m.imprimirTabuleiro();

        int jogadorAtual = 0;
        do
        {
          char z = (jogadorAtual % 2 == 0) ? '1' : '2';
          cout << "\nTurno de jogador "
               << (jogadorAtual % 2 == 0 ? Jogador1.Apelido : Jogador2.Apelido)
               << ":\n"
               << endl;
          cout << "Escolha as coordenadas para duas posições" << endl;
          int x, y, x2, y2;
          antiUsuario(x);
          antiUsuario(y);
          antiUsuario(x2);
          antiUsuario(y2);

          if (m.ehJogadaValida(x, y, x2, y2, z))
          {
            m.validaJogada(x, y, x2, y2, z);
            m.imprimirTabuleiro();
            if (m.formamPares(x, y, x2, y2, z) == true)
            {
              m.validaPares(x, y, x2, y2, z);
            }
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
        }

        m.liberaMemoria();
        menuFimDeJogo(jogoEscolhido, jogadoresVector);
      }
      else
      {
        cout << "ERRO: jogo não encontrado" << endl;
      }
    }
    if (Comando[0] == 'F' && Comando[1] == 'S')
    {
      cout << "Sistema finalizado." << endl;
      return 0;
    }

    if (Comando != "CJ" && Comando != "LI" && Comando != "RJ" &&
        Comando != "LJ" && Comando != "EP" && Comando != "FS")
    {
      cout << "O comando digitado não corresponde a nenhuma opção válida. "
              "Tente novamente."
           << endl;
    }
  }

  return 0;
}

void antiUsuario(int &a)
{
  string aux = "";

  while (1)
  {
    cin >> aux;
    if (cin.peek() != '\n')
    {
      cout << "ERRO: formato incorreto" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

void menuFimDeJogo(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector)
{

  cout << "\nFIM DE JOGO! \n\nVR - Visualizar ranking"
       << endl;

  while (1)
  {

    string aux;
    string resposta;

    while (1)
    {
      try
      {
        cin >> aux;
        if (aux.length() != 2)
        {
          throw badInputs(aux);
        }

        for (long unsigned int i = 0; i < aux.length(); i++)
        {
          if (isdigit(aux[i]) || !isalpha(aux[i]) || isblank(aux[i]))
          {
            throw badInputs(aux);
          }
        }
      }
      catch (badInputs &e)
      {
        cout << e.what() << "; "
             << " " << endl;
        continue;
      }
      catch (exception &e)
      {
        cout << e.what() << endl;
        continue;
      }

      for (long unsigned int i = 0; i < aux.length(); i++)
      {
        resposta[i] = toupper(aux[i]);
      }

      if (resposta[0] == 'V' && resposta[1] == 'R')
      {
        Jogadores::mostrarRanking(jogoEscolhido, jogadoresVector);
      }
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

  while (1)
  {
    try
    {
      cin >> aux;

      for (long unsigned int i = 0; i < aux.length(); i++)
      {
        if (isdigit(aux[i]) || isblank(aux[i]) || !isalpha(aux[i]))
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
        if (resposta == 'S')
        {
          cin.ignore(std::numeric_limits<std::streamsize>::max(),
                     '\n');
          return;
        }
        else if (resposta == 'N')
        {
          exit(0);
        }
        else
        {
          cout << "Escolha (S) sim ou (N) não!" << endl;
          continue;
        }
      }
    }
    catch (badInputs &e)
    {
      cout << e.what() << "; "
           << "Escolha (S) sim ou (N) não!" << endl;
      continue;
    }
    catch (exception &e)
    {
      cout << e.what() << endl;
    }
  }
}