#include "Cifrado.h"
#include "Generador.h"
using namespace std;
rsa::rsa()
{
  long long p1 = Generar_primo(-1), p2 = Generar_primo(p1);
  long long n = p1 * p2;
  long long f = (p1 - 1) * (p2 - 1);
  long long e = Generar_e(f);
  long long d = Inversa_mod(e, f);
  llave_privada = make_pair(d, n);
  llave_publica = make_pair(e, n);
}
rsa::rsa(long long p1, long long p2)
{
  long long n = p1 * p2;
  long long f = (p1 - 1) * (p2 - 1);
  long long e = Generar_e(f);
  long long d = Inversa_mod(e, f);
  llave_privada = make_pair(d, n);
  llave_publica = make_pair(e, n);
}
rsa::rsa(pair<long long, long long> r, string p)
{
  if (p == "public")
  {
    llave_publica = r;
  }
  if (p == "private")
  {
    llave_privada = r;
  }
}
long long rsa::Cifrar(long long a)
{
  long long b = Potencia_mod(a, llave_publica.first, llave_publica.second);
  return b;
}
long long rsa::Descifrar(long long a)
{
  long long b = Potencia_mod(a, llave_privada.first, llave_privada.second);
  return b;
}
