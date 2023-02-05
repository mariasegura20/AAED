
/* 3. Utilizando rand(), escriba una funcion que genere un numero
pseudoaleatorio de coma flotante y precision doble en el intervalo
continuo [a, b]. */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double pseudo_aleatorio (int, int);

int main (){
	
	int a, b;

	srand(time(nullptr));
	
	cout << "Introduzca el valor de a: ";
	cin >> a;
	cout << "Introduzca el valor de b: ";
	cin >> b;
	
	cout << "El numero pseudoaleatorio de coma flotante y precision doble generado en el intervalo discreto [" << a << ", " << b << "] es: " << pseudo_aleatorio(a,b) << endl;
	
	system("pause");
	return 0;
}

double pseudo_aleatorio(int a, int b){
	double n;
	
	n = (float(rand() * (b-a)) / float(RAND_MAX )) + a;
	
	return n;
} 