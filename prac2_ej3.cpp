#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#include "cronometro.h"

using namespace std;

void ord_intercambio (int *, int);
void ord_seleccion (int *, int);
void ord_insercion (int *, int);

int main(){
	int n = 10000, v[n];
	cronometro c;

	// Semilla para rand()
	srand(time(nullptr));

	// Genero vector ordenado
	for (int i = 0; i < n ; i++){
		v[i] = i;
	}
	
	// Desordeno el vector
	random_shuffle(v, v+n);
	
	c.activar();
	
	// Algortimos de ordenación
	ord_intercambio(v,n);
	// ord_seleccion(v,n);
	// ord_insercion(v,n);

	c.parar();

	cout << "Tiempo: " << c.tiempo() << endl;

	system("pause");
	return 0;
}

void ord_intercambio (int * v, int n)
{
	for (int i=0 ; i < n ; i++)
	{
		for (int j = n-1 ; j > i ; j--)
		{
			if (v[j] < v[j-1])
			{
				swap(*(v+j), *(v+j-1));
			}
		}
	}
}

void ord_seleccion (int * v, int n){
	int *s;

	for (int i = 0; i < n-1 ; i++){
		s = min_element(v+i, v+n);
        swap(*s, *(v+i));
	}
}

void ord_insercion (int * v, int n)
{
	int x, j;

	for (int i = 1 ; i < n ; i++)
	{
		x = v[i];
		j = i;

		while (j > 0 && x < v[j-1])
		{
			v[j] = v[j-1];
			j--;
		}

		v[j] = x;
	}
}