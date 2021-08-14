/*
Questão 2) Desenvolva um código que leia um valor numérico entre 0 e 50, inclusive,
e imprima o resto da divisão desse número por todos os seus antecessores maiores que 0.
Atenção: Faça a crítica de dados para que o programa só aceite os valores citados.
Lembre-se de que não existe divisão por 0!
*/
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int valor;
	int divisor;
	int resto;

	//Entrada de dados
	cout << "Digite um valor entre 0 e 50:" << endl;
	cin >> valor;

	divisor = valor;

	while(valor < 0 || valor > 50)
	{
		cout << "Este nao eh um valor valido, digite um valor entre 0 e 50:" << endl;
		cin >> valor;
	}
	if(valor == 0)
		cout << "Todo numero dividido por 0 eh 0." << endl;
	while(divisor > 0 && divisor <= 50)
	{
		if(divisor == 1)
			cout << "Nao existe divisao por zero." << endl;
		else
		{
			cout << "Resto da divisao de " << valor << " por " << divisor - 1 << ": ";
			resto = valor % (divisor - 1);
			cout << resto << endl;
		}

		divisor--;

	}

	return 0;
}
