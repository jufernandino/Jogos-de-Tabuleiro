#include <iostream>
#include "Tabuleiro.hpp"

Tabuleiro::Tabuleiro() {
    this->_colunas = 4;
    this->_linhas = 4;
}

void Tabuleiro::ImprimeTabuleiro() {
    
    std::cout<<"   ";
    for(int topo=0; topo < _colunas ; topo++){
        std::cout<<"====";
    }
    
    std::cout<<std::endl;

    for(int tamanho=0 ; tamanho<_colunas ; tamanho++){
        
        std::cout << " " << tamanho <<" ";
        for(int numlinha=0; numlinha < _linhas ; numlinha++)
            std::cout<< " X " << "|";
        
        
        std::cout<<std::endl;
        std::cout<<"   ";
        
        
        if(tamanho!=_linhas-1){
            for(int numcolunas=0 ; numcolunas<_colunas;numcolunas++)
                std::cout<<"---+";
        
            std::cout<<std::endl;
        }
    }
    
    for(int base=0; base < _colunas ; base++)
        std::cout<<"====";
        
    std::cout<<std::endl<<"  ";
    
    for(int numbase=0; numbase < _colunas ; numbase++)
        std::cout << "  " << numbase <<" ";
}