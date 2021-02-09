#include <iostream>
#include <cctype>

#include "utils.h"

/**
 * Percorre a string passada por parâmetro convertendo cada caractere em minúsculo
 * @param s string a ser convertida
 * @return resultado da conversão
 */
string toLowercase(string s) {
  string result = "";

  for (size_t i = 0; i < s.size(); i++) {
    result += tolower(s[i]);
  }
  
  return result;
}