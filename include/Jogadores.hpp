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
    int reversisWins;
    int reversisDefeats;
    int lig4sWins;
    int lig4sDefeats;
    bool victory;

    int pesquisaJogador(string Apelido); //procura o jogador pelo seu apelido no arquivo

    Jogadores(); //construtor default

    Jogadores(string Apelido); //de fato faz o cadastro

    void signIn(string Apelido, vector<Jogadores> &jogadoresVector);

    void reescreveArquivo(vector<Jogadores> &jogadoresVector);

    void removeJogador(vector<Jogadores> &jogadoresVector);

    void atualizaEstatisticas(int gameMode, vector<Jogadores> &jogadoresVector);

};

#endif