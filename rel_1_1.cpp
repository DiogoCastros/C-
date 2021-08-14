/*
Questão 1) Em uma banca de frutas o preço das laranjas pode assumir 2 valores 
distintos, R$0,80 cada se forem adquiridas menos de uma dúzia, 
e R$0,65 se forem adquiridas pelo menos doze.
Utilizando a estrutura de decisão if-else, elabore um programa que leia o número 
de laranjas compradas e imprima o valor total da compra.
OBS.: Limitador de casas decimais em C: #include <iomanip>
cout << fixed << setprecision(numero_de_casas_decimais);
Ex.:
Entrada:12
Saída:
Preco da unidade: R$0.65
Preco total: R$7.80
Entrada: 6
Saída:
Preco da unidade: R$0.80
Preco total: R$4.80
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

	int laranjas;
	float preco;
	float total;

	//Entrada de dados
	int entrada = 1;
	while(entrada)
	{
		cout << "Qual a quantidade de laranjas?" << endl;
		cin >> laranjas;
		
		//Estrutura para determinar o valor de acordo com a quantidade de laranjas compradas
		if(laranjas >= 12)
			preco = 0.65;
		else
			preco = 0.8;

		total = laranjas * preco;

		//Sa�da de dados
		cout << fixed << setprecision(2);
		cout << "Pre�o por unidade: R$" << preco << endl;
		cout << "Pre�o total: R$" << total << endl;

		cout << "Digite 1 para nova entrada e 0 para finalizar:" << endl;
		cin >> entrada;
		cout << endl;
	}

	return 0;
}
