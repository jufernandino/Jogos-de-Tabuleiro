#include "lig4.hpp"
#include <iomanip>
#include <iostream>
#include <string>

lig4::lig4() {
  //não achei variação no tabuleiro do lig4, é sempre 6x7, então decidimos deixar fixo
  this->rows = 6;
  this->columns = 7;
}