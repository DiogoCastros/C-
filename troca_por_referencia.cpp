/*Passagem de paramentro por referencia*/
#include <iostream>

using namespace std;

//funcao para efetuar a troca de dois numeros inteiros
void troca(int &i, int &j)
{
	int temp; //variavel para guardar o valor de i temporariamente
	temp = i;
	i = j;
	j = temp;
}

int main()
{
	//declaracao das variaveis
	int i = 5, j = 3;
	
	//chamando a funcao troca
	troca(i, j);
	
	//print dos resultados
	cout << i << ", " << j << endl;
		
	return 0;
}
