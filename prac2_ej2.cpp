#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

void ord_intercambio (int *, int);
void ord_seleccion (int *, int);
void ord_insercion (int *, int);

int main(){
	int n = 9, val = 1, op;
	int v[n], w[n], x[n], i = 0;
	
	// Semilla para rand()
	srand(time(nullptr));

	cout << "Los algoritmos de ordenacion disponibles son: \n 1) Intercambio \n 2) Seleccion \n 3) Insercion \nAlgoritmo a utilizar: ";
	cin >> op;

	// Genero vector ordenado V
    for (int i =  0; i < n ; i++)
	{
        v[i] = i;
    }

    memcpy(w,v,sizeof(v));                  // Vector W (que permuta)

    do
    {
        memcpy(x,w,sizeof(w));              // Vector X (en el que se ordena las permutaciones)

        switch (op)
		{
			case 1: ord_intercambio(x,n); break;
			case 2: ord_seleccion(x,n); break;
			case 3: ord_insercion(x,n); break;
			default: break;
		}

        if (memcmp(v,x,sizeof(v)) != 0)
		{
            cout << "ERROR." << endl;
			val = 0;
        }
            
    } while (next_permutation(w,w+n) && val);

	if (val)
	{
		switch (op)
		{
			case 1: cout << "El algoritmo de ordenacion por intercambio funciona correctamente." << endl; break;
			case 2: cout << "El algoritmo de ordenacion por seleccion funciona correctamente." << endl; break;
			case 3: cout << "El algoritmo de ordenacion por insercion funciona correctamente." << endl; break;
			default: break;
		}
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

void ord_seleccion (int * v, int n)
{
	int *s;

	for (int i = 0; i < n-1 ; i++)
	{
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