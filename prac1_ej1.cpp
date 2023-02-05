/* 1. Utilizando rand(), escriba una funcion que genere un numero
pseudoaleatorio entero en el intervalo discreto [a, b].*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int pseudo_aleatorio (int, int);

int main (){
	
	int a, b;
	
	srand(time(nullptr));
	
	cout << "Introduzca el valor de a: ";
	cin >> a;
	cout << "Introduzca el valor de b: ";
	cin >> b;
	
	cout << "El numero pseudoaleatorio entero generado en el intervalo discreto [" << a << ", " << b << "] es: " << pseudo_aleatorio(a,b) << endl;
	
	system("pause");
	return 0;
}

int pseudo_aleatorio(int a, int b){
	int n;
	
	n = a + rand() % (b+1-a);
	
	return n;
}