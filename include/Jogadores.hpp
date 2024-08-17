#ifndef Jogadores_H
#define Jogadores_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Jogadores
{
public:
    string Apelido;
    string Nome;
    int reversiWins;
    int reversiDefeats;
    int reversiEmpates;
    int lig4Wins;
    int lig4Defeats;
    int lig4Empates;
    int tictactoeWins;
    int tictactoeDefeats;
    int tictactoeEmpates;
    int campoMinadoWins;
    int campoMinadoDefeats;
    int memoriaWins;
    int memoriaDefeats;
    int memoriaEmpates;
    bool victory;
    bool empate;

    static int pesquisaJogador(string Apelido); // procura o jogador pelo seu apelido no arquivo

    Jogadores();

    Jogadores(string Apelido, string Nome);

    Jogadores logIn(string Apelido, vector<Jogadores> &jogadoresVector);

    static void reescreveArquivo(vector<Jogadores> &jogadoresVector);

    static void removeJogador(vector<Jogadores> &jogadoresVector, string &Apelido);

    void atualizaEstatisticas(char jogoEscolhido, vector<Jogadores> &jogadoresVector);

    static void mostrarRanking(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector);

    static void mostrarEstatisticas(vector<Jogadores> &jogadoresVector, const string &ordenacao);

    static void carregarJogadores(vector<Jogadores> &jogadoresVector);

    static void cadastrarJogadores(string apelido, string nome, Jogadores &Jogador, vector<Jogadores> &jogadoresVector);

    void ordenacaoApelido(vector<Jogadores> &jogadoresVector);

    void ordenacaoNome(vector<Jogadores> &jogadoresVector);
};

#endif