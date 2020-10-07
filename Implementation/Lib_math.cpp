#include "Lib_math.h"
using namespace std;
long long mod(long long a, long long b)
{
  long long r = a - (a / b) * b;
  if (r < 0)
    r += b;
  return r;
}
long long mcd(long long a, long long b)
{
  long long x = a, y = b, tmp;
  if (x < y)
  {
    tmp = x;
    x = y;
    y = tmp;
  }
  if (y == 0)
  {
    return x;
  }
  else
  {
    while (y > 0)
    {
      tmp = mod(x, y);
      x = y;
      y = tmp;
    }
    return x;
  }
}
pair<long long, long long> Euclides_ext(long long a, long long b)
{
  long long gcd = mcd(a, b);
  long long x = a / gcd, y = b / gcd, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
  long long q, tmp;
  pair<long long, long long> par;
  while (y > 0)
  {
    q = x / y;
    tmp = x - q * y;
    x = y;
    y = tmp;
    tmp = s1 - q * s2;
    s1 = s2;
    s2 = tmp;
    tmp = t1 - q * t2;
    t1 = t2;
    t2 = tmp;
  }
  par.first = s1;
  par.second = t1;
  return par;
}
long long Inversa_mod(long long a, long long b)
{
  int x = a, y = b, r;
  pair<long long, long long> par = Euclides_ext(x, y);
  r = mod(par.first, b);
  return r;
}
long long Potencia_mod(long long a, long long b, long long c)
{
  long long r = a, p = b, m = c;
  long long s = 1;
  r = mod(r, m);
  while (p > 0)
  {
    if (p & 1)
    {
      s = mod(s * r, m);
    }
    p = p >> 1;
    r = mod(r * r, m);
  }
  return s;
}
bool Primalidad(long long a)
{
  if (a < 2)
    return 0;
  if (a < 4)
    return 1;
  if (mod(a, 2) == 0)
    return 0;
  long long e = sqrt(a) + 1;
  bool arr[e];
  for (long long i = 0; i < e; i++)
    arr[i] = 1;
  for (long long i = 3; i < e; i += 2)
  {
    if (arr[i])
    {
      if (mod(a, i) == 0)
        return 0;
      for (long long j = i * i; j < e; j += i)
      {
        arr[j] = 0;
      }
    }
  }
  return 1;
}
