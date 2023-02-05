#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#include "cronometro.h"

#define ERROR_ABS 0,000001
#define ERROR_REL 0,0000005

#define N 1000

using namespace std;

void ord_intercambio (int *, int);
void ord_seleccion (int *, int);
void ord_insercion (int *, int);

int main(){
	int v[N], cont = 0;
	cronometro c;

	// Semilla para rand()
	srand(time(nullptr));

    for (int i = 1000 ; i <= N ; i+=1000)
    {
        // Genero vector ordenado
	    for (int j = 0; j < i ; j++)
        {
		    v[j] = j;
	    }
	    
        c.activar();   
        
        do
        {
            // Desordeno el vector
            random_shuffle(v, v+i);
        
            // Algortimos de ordenación
            ord_intercambio(v,i);
            // ord_seleccion(v,n);
            // ord_insercion(v,n);

            // Incremento del contador
            cont++;
        } while (c.tiempo() < ERROR_ABS / (ERROR_REL + ERROR_ABS));
	    
        c.parar();
        
        cout << "El tiempo para el vector de tamaño " << i << " es de " << c.tiempo() / double (cont) << endl;
    }

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