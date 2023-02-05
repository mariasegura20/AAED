/* 2. Escriba un programa que simule 10 000 000 de tiradas de un dado.
Imprima las frecuencias relativas que se obtienen para cada una de las
caras. Emplee la funcion del ejercicio anterior.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int pseudo_aleatorio (int, int);

int main (){
	
	int i, aux;
	int n = 10000000;
	int count[6]={};
	
	srand(time(nullptr));
	
	for (i = 0 ; i < n ; i++){
		aux = pseudo_aleatorio(1,6);
		count[(aux-1)]++;
	}
	
	for (i = 0 ; i < 6 ; i++){
		cout << "Se ha generado " << count[i] << " veces el numero " << i+1 << " (" << float(count[i])/float(n)*100.0 << "%)" << endl;
	}
	
	system("pause");
	return 0;
}

int pseudo_aleatorio(int a, int b){
	int n;
	
	n = a + rand() % (b+1-a);
	
	return n;
} 