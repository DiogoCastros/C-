#include <iostream>

using namespace std;

struct fila
{
	int fim; // guarda a posição do fim da fila
	int capacidade; // guarda a capacidade da fila
	double *elementos; // vetor que armazena os valores
};

void init(fila *f, int c)
{
	f->fim = -1; // indica que a fila está vazia
	f->capacidade = c; // define a capacidade da fila
	f->elementos = new double[c]; // aloca memória para a capacidade fornecida
}

//verificando se a fila esta vazia
bool isEmpty(fila *f)
{
	return (f->fim == -1);
}

//verificando se a fila esta cheia
bool isFull(fila *f)
{
	return (f->fim == f->capacidade - 1)
}

//inserindo valor na fila
	   void enqueue(fila *f, double v)
{
	f->fim++;
	f->elementos[f->fim] = v;
}

//retirando valor da fila
double dequeue(fila *f)
{
	double aux = f->elementos[0];
	for (int i = 0; i < f->fim; i++)
		f->elementos[i] = f->elementos[i + 1];
	f->fim--;
	return aux;
}

//verificando o valor da frente da fila
double front(fila *f)
{
	return f->elementos[0];
}

int main()
{
	fila f; //fila
	int cap; //tamanho da fila

	// inicializacao da fila
	cout << "Digite o tamanho da fila: ";
	cin >> cap;
	cout << endl;

	//iniciando a fila
	init(&f, cap);

	// exibicao do menu e leitura da escolha do usuario
	char opcao;
	do
	{
		cout << "C - Colocar na fila(enqueue)" << endl;
		cout << "R - Remover da fila(dequeue)" << endl;
		cout << "E - Exibir inicio(front)" << endl;
		cout << "S - Sair" << endl;
		cin >> opcao;
		cout << endl;

		switch (opcao)
		{
			// emfileirar
		case 'C':
			if (isFull(&f) == true)
			{
				cout << "Fila estah cheia; nao eh possivel inserir" << endl;
			}
			else
			{
				float v;
				cout << "Entre com o valor a entrar na fila: ";
				cin >> v;
				enqueue(&f, v);
				cout << endl;
				cout << "Inseri o elemento " << v << endl;
				cout << endl;
			}
			break;

			// desemfileirar
		case 'R':
			if (isEmpty(&f) == true)
			{
				cout << "A fila estah vazia; nao eh possivel remover" << endl;
			}
			else
			{
				float tchau = dequeue(&f);
				cout << "Removi o elemento " << tchau << endl;
				cout << endl;
			}
			break;

			// topo
		case 'E':
			if (isEmpty(&f) == true)
			{
				cout << "A fila esta vazia" << endl;
			}
			else
			{
				cout << "O inicio da fila e " << front(&f) << endl;
				cout << endl;
			}
			break;

			// sair
		case 'S':
			cout << "bye!" << endl;
			break;

			// invalido
		default:
			cout << "Opcao invalida; digite C, R, E ou S" << endl;
			break;
		}
	}
	while (opcao != 'S'); //condicao para manter a repeticao da estrutura

	return 0;
}
