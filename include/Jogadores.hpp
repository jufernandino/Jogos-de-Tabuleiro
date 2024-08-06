#ifndef Jogadores_H
#define Jogadores_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Jogadores{
    public:
    string Apelido;
    string Nome;
    int reversiWins;
    int reversiDefeats;
    int lig4Wins;
    int lig4Defeats;
    int tictactoeWins;
    int tictactoeDefeats;
    bool victory;

    int pesquisaJogador(string Apelido); //procura o jogador pelo seu apelido no arquivo

    Jogadores(); //construtor default

    //Jogadores(string Apelido); //de fato faz o cadastro
    Jogadores(string Apelido, string Nome);

    void signIn(string Apelido, vector<Jogadores> &jogadoresVector);

    void reescreveArquivo(vector<Jogadores> &jogadoresVector);

    void removeJogador(vector<Jogadores> &jogadoresVector);

    void atualizaEstatisticas(int gameMode, vector<Jogadores> &jogadoresVector);

    void showRanking(const int &gameMode, vector<Jogadores> &jogadoresVector);

    static bool ordenacaoAlfabetica(const Jogadores &x, const Jogadores &y);

    void showEstatisticas(vector<Jogadores> &jogadoresVector);

    void loadJogadores(vector<Jogadores> &jogadoresVector);

};

#endif