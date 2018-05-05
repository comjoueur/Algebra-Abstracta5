#include "Lib_math.h"
#include "Generador.h"
#include "Cifrado.h"
using namespace std;
int main(){
	long long a;
	cin>>a;
	rsa A;
	a=A.Cifrar(a);
	cout<<a<<endl;
	a=A.Descifrar(a);
	cout<<a<<endl;
	return 0;
}
