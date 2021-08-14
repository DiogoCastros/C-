/*
Questão 3) Faça um código que recebe um valor n, referente a quantidade de testes
que serão feitos. Logo em seguida, monte uma função que recebe 5 valores inteiros
e mostra quantos valores digitados foram pares, quantos valores digitados foram
ímpares, quantos valores digitados foram positivos e quantos valores digitados
foram negativos e mostre na tela.
Ex.:
Entrada:
2
-2 1 33 14 111
-13 72 90 -1 0

Saída:
Quantidade de numeros pares: 2
Quantidade de numeros impares: 3
Quantidade de numeros positivos: 4
Quantidade de numeros negativos: 1

Quantidade de numeros pares: 3
Quantidade de numeros impares: 2
Quantidade de numeros positivos: 3
Quantidade de numeros negativos: 2
*/

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void verificador(int num[], int inicio)
{
	int contPar = 0;
	int contImpar = 0;
	int contPositivo = 0;
	int contNegativo = 0;

	//testando as variaveis
	for(int i = inicio; i < (inicio + 5); i++)
	{
		if(num[i] >= 0)
		{
			contPositivo++;

			if(num[i] % 2 == 0)
				contPar++;
			else
				contImpar++;
		}
		else
		{
			contNegativo++;

			if(num[i] % 2 == 0)
				contPar++;
			else
				contImpar++;
		}
	}

	cout << "Quantidade de numeros pares: " << contPar << endl;
	cout << "Quantidade de numeros impares: " << contImpar << endl;
	cout << "Quantidade de numeros positivos: " << contPositivo << endl;
	cout << "Quantidade de numeros negativos: " << contNegativo << endl;
}

int main()
{
	//quantidade de testes que serao feito
	int testes;

	//variaveis que serao testadas
	int num[1000];

	//indice que inicia a vericiacao
	int inicio = 0;
	
	cout << "Quantos testes serao feitos? ";
	cin >> testes;

	cout << "Digite 5 numeros para iniciar os testes:" << endl;
	for(int i = 0; i < (5 * testes); i++)
		cin >> num[i];

	while(testes > 0)
	{
		verificador(num, inicio);
		testes--;
		inicio += 5;
		cout << endl;
	}


	return 0;
}
