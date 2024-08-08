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

    bool logar(string Apelido, vector<Jogadores> &jogadoresVector);

    void reescreveArquivo(vector<Jogadores> &jogadoresVector);

    void removeJogador(vector<Jogadores> &jogadoresVector, string &Apelido);

    void atualizaEstatisticas(char jogoEscolhido, vector<Jogadores> &jogadoresVector);

    void showRanking(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector);

    static bool ordenacaoDecrescente(const Jogadores &x, const Jogadores &y, const char &ordenacao);

    void showEstatisticas(vector<Jogadores> &jogadoresVector, const char &ordenacao, char &ordem);

    void loadJogadores(vector<Jogadores> &jogadoresVector);

    void definirJogador();

    void cadastrarJogadores(Jogadores &Jogador, vector<Jogadores> &jogadoresVector);

};

#endif