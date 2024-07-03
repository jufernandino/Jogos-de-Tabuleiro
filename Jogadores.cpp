#include <iostream>
#include <iomanip>
#include <string>
#include "Jogadores.hpp"

using namespace std;

int Jogadores::pesquisaJogador(string Apelido){

    ifstream in("outputFile.txt", fstream::in);

    if(!in.is_open()){
        cout << "O arquivo "outputFile" não pôde ser aberto." << endl;
        return 1;
    }

    string aux;
    while(getline(in, aux, ' ')){
        if(aux == Apelido){
            //cout << "ERRO: jogador repetido" << endl;
            return 1;
        }
    }

    inFile.close();
}

Jogadores::Jogadores(string Apelido, string Nome){ //construtor, faz o cadastro

    if(this->pesquisaJogador){
        cout << "ERRO: jogador repetido" << endl;
        return;
    } 
        
    this->id = Jogadores::automatic;
    Jogadores::automatic++;
    this->Apelido = Apelido;
    this->Nome = Nome;
}

Jogadores::signInjogador(string Apelido){

    if(this->pesquisaJogador){
        //provavelmente aqui terá a atualização do arquivo com as vitórias posteriormente
    } 

}

Jogadores::removeJogador(string Apelido,){

    if(this->pesquisaJogador){
        ifstream in("outputFile.txt", fstream::in);

        if(!in.is_open()){
            cout << "O arquivo "outputFile" não pôde ser aberto." << endl;
            return 1;
        }

        ofstream out("outputFile.txt", fstream::out);

        if(!out.is_open()){
            cout << "O arquivo "outputFile" não pôde ser aberto." << endl;
            return 1;
        }
            
        string line;
        string aux;
        while(getline(in, aux, ' ')){
            if(aux == Apelido){
                while(getline(in, line)){
                    out << line << endl; //não sei se dá certo, mas a ideia é criar outro arquivo de mesmo nome e esse deve sobrescrever o antigo
                }
            }
        }

    }

}

void Jogadores::listarJogadores(){
    ifstream in("outputFile.txt", fstream::in);
    if(!in.is_open()){
        cout << "O arquivo "outputFile" não pôde ser aberto." << endl;
        return 1;
    }

    string line;
    while(getline(in, line)){
        cout << line << endl;
    }

    inFile.close();
}

