#ifndef Jogadores_H
#define Jogadores_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Jogadores{
    public:
    string Apelido;
    string Nome;
    int winsReversi;
    int lossesReversi;
    int winsLig4;
    int lossesLig4;

    int pesquisaJogador(string Apelido); //procura o jogador pelo seu apelido no arquiv

    Jogadores(string Apelido, string Nome); //de fato faz o cadastro
};

#endif