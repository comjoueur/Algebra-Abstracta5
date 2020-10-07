#include <bits/stdc++.h>
#include "Generador.h"
#include "Lib_math.h"
using namespace std;
class rsa
{
public:
  pair<long long, long long> llave_privada;
  pair<long long, long long> llave_publica;
  rsa();
  rsa(long long, long long);
  rsa(pair<long long, long long> r, string p);
  long long Cifrar(long long);
  long long Descifrar(long long);
};
