/* Estrutura deque que permite a insercao de um numero no inicio ou no final
do deque, tanto como remocoes. */

#include <iostream>

using namespace std;

//struct para dados contidos no deque
struct deque
{
	int frente; //armazena a frente do deque
	int fim; //armazena o final do deque
	int cap; //armazena a capacidade ddo deque
	float *info; //informacao contida no deque
};

//funcao de inicializacao do deque
void init(deque *d, int c)
{
	d->frente = 0; // indica que o deque está vazio
	d->fim = -1; // indica que o deque está vazio
	d->cap = c; // define a capacidade do deque
	d->info = new float[c]; // aloca memória para a capacidade fornecida
}

//funcao para saber se esta vazio
bool isEmpty(deque *d)
{
	return (d->fim == -1);
}

//funcao para saber se esta cheio
bool isFull(deque *d)
{
	return (d->fim == d->cap - 1);
}

//funcao para inserir valor na frente do deque
void insertFront(deque *d, float v)
{
	if(d->fim == -1)
	{
		d->fim++;
		d->info[d->fim] = v;
	}

	else
	{
		for(int i = d->fim; i >= d->frente; i--)
		{
			float aux = d->info[i];
			d->info[i + 1] = aux;
		}
		d->info[d->frente] = v;
		d->fim++;
	}
}

//funcao para inserir valor no final do deque
void insertRear(deque *d, float v)
{
	d->fim++;
	d->info[d->fim] = v;
}

//funcao para deletar o valor da frente do deque
float deleteFront(deque *d)
{
	float excluido = d->info[d->frente];
	
	if(d->fim == 0)
		d->fim--;

	else
	{
		for(int i = d->frente + 1; i <= d->fim; i++)
		{
			float aux = d->info[i];
			d->info[i - 1] = aux;
		}
		d->fim--;
	}

	return excluido;
}

//funcao para deletar o valor do final do deque
float deleteRear(deque *d)
{
	float aux = d->info[d->fim];

	d->fim--;

	return aux;
}

//funcao para exibir o inicio do deque
float getFront(deque *d)
{
	return d->info[d->frente];
}

//funcao para exibir o final do deque
float getRear(deque *d)
{
	return d->info[d->fim];
}

int main()
{
	deque d; //deque
	int cap; //capacidade do deque


	cout << "Informe qual sera o tamanho do deque: ";
	cin >> cap;

	//definindo o tamnaho do deque
	init(&d, cap);

	int opcao; //opcao para selecao de funcoes do menu

	do
	{
		//opcoes para o usurio
		cout << "Digite 1 para inserir um valor na frente do deque (insertFront);" << endl;
		cout << "Digite 2 para inserir um valor no final do deque (insertRear);" << endl;
		cout << "Digite 3 para deletar um valor na frente do deque (deleteFront);" << endl;
		cout << "Digite 4 para deletar um valor no final do deque (deleteRear);" << endl;
		cout << "Digite 5 para ver o valor da frente do deque (getFront);" << endl;
		cout << "Digite 6 para ver o valor do fim do deque (getRear);" << endl;
		cout << "Digite 0 para sair;" << endl;

		cin >> opcao;

		//cases possiveis
		switch(opcao)
		{

			//incluir um valor no inicio do deque
		case 1:
			if (isFull(&d) == true)
				cout << "Sorry!!! O deque esta cheio!!\n" << endl;
			else
			{
				float v;
				cout << "Entre com o valor que deseja incluir: ";
				cin >> v;
				insertFront(&d, v);
				cout << "O valor " << v << " foi incluido na frente do deque.\n" << endl;
			}
			break;

			//incluindo valor no final do deque
		case 2:
			if (isFull(&d) == true)
				cout << "Sorry!!! O deque esta cheio!!\n" << endl;
			else
			{
				float v;
				cout << "Entre com o valor que deseja incluir: ";
				cin >> v;
				insertRear(&d, v);
				cout << "O valor " << v << " foi incluido no final do deque.\n" << endl;
			}
			break;

			//removendo valor da frente do deque
		case 3:
			if (isEmpty(&d) == true)
				cout << "Sorry!!! O deque esta vazio!!\n" << endl;
			else
			{
				float v = deleteFront(&d);
				cout << "Removi o valor " << v << " da frente do deque.\n";
			}
			break;

			//removendoo valor do final do deque
		case 4:
			if (isEmpty(&d) == true)
				cout << "Sorry!!! O deque esta vazio!!\n" << endl;
			else
			{
				float v = deleteRear(&d);
				cout << "Removi o valor " << v << " do final do deque.\n";
			}
			break;

			//mostrando o valor da frente do deque
		case 5:
			if (isEmpty(&d) == true)
				cout << "Sorry!! O deque esta vazio!!\n" << endl;
			else
			{
				float v = getFront(&d);
				cout << "O valor da frente do deque e " << v << ".\n";
			}
			break;

			//mostrando o valor do final do deque
		case 6:
			if (isEmpty(&d) == true)
				cout << "Sorry!!! O deque esta vazio!!\n" << endl;
			else
			{
				float v = getRear(&d);
				cout << "O valor do final do deque e " << v << ".\n";
			}
			break;

			//saindo do deque
		case 0:

			cout << "See you later!!! Bye!!!\n" << endl;

			break;

		default:
			cout << "Opcao ivalida, digite 1, 2, 3, 4, 5, 6 ou 0.\n" << endl;
			break;
		}
	}
	while(opcao != 0);

	return 0;
}
