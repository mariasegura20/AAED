/* 5. Escriba un programa que genere 10 000 000 permutaciones
pseudoaleatorias de los 6 primeros numeros naturales e imprima cuantas
de ellas estan ordenadas.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>

using namespace std;

int main (){
	int v[] = {1,2,3,4,5,6}, s[] = {1,2,3,4,5,6};
	int i, j, count = 0, n = 10000000;
	
	srand(time(nullptr));
	
	for (i=0;i<n;i++){
		random_shuffle(v, v+6);
		
		if (memcmp(v,s,6*sizeof(*v)) == 0){
			count++;
		}
	}
	
	cout << "Se han generado " << count << " permutaciones ordenadas" << endl;
	
	system("pause");
	return 0;
} 


