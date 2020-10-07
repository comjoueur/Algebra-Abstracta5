// g++ main.cpp Cifrado.cpp Generador.cpp Lib_math.cpp -o main

#include "Lib_math.h"
#include "Generador.h"
#include "Cifrado.h"
using namespace std;
int main()
{
  cout << "Ingrese el numero a cifrar" << endl;
  long long a;
  cin >> a;
  rsa A;
  a = A.Cifrar(a);
  cout << "La llave privada es: ";
  cout << "<" << A.llave_privada.first << "," << A.llave_privada.second << ">" << endl;
  cout << "La llave publica es: ";
  cout << "<" << A.llave_publica.first << "," << A.llave_publica.second << ">" << endl;
  cout << "El cifrado es: ";
  cout << a << endl;
  a = A.Descifrar(a);
  cout << "El descifrado es: ";
  cout << a << endl;
  return 0;
}
