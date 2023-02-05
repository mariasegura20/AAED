/* 4. Escriba un programa que genere 10 000 000 de numeros
pseudoaleatorios de precision doble en el intervalo [0, 1] e imprima
la media de los valores y = 4*raiz(1 - x^2) correspondientes a cada
numero x. Emplee la funcion del ejercicio anterior.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double pseudo_aleatorio (int, int);

int main (){
	
	int i, n = 20;
	double x, total = 0;
	
	srand(time(nullptr));
	
	for (i=0 ; i < n ; i++){
		x = pseudo_aleatorio(0,1);
		total += (4 * sqrt(1-pow(x,2)));
	}
	
	cout << "La media de los valores y = 4*raiz(1-x^2), donde x son " << n << " numeros pseudoaleatorios de precision doble en el intervalo [0,1] es " << total / float(n) << endl;
	
	system("pause");
	return 0;
}

double pseudo_aleatorio(int a, int b){
	double n;
	
	n = (float(rand() * (b-a)) / float(RAND_MAX )) + a;
	
	return n;
} 