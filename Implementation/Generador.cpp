#include "Generador.h"
using namespace std;
long long Generar_primo(long long f = -1)
{
  srand(time(NULL));
  long long x;
  bool b = 1;
  while (b)
  {
    x = mod(rand(), 10000) + 1;
    b = !(Primalidad(x) && x != f);
  }
  return x;
}
long long Generar_e(long long n)
{
  srand(time(NULL));
  long long x;
  bool b = 1;
  while (b)
  {
    x = mod(rand(), (n - 2)) + 2;
    b = (mcd(n, x) != 1);
  }
  return x;
}
