#include <iostream>

using namespace std;

struct pilha
{
    int topo;         // guarda a posicao do topo
    int capacidade;   // guarda a capacidade da pilha
    float *elementos; // vetor que armazena os valores
};

void init(pilha *p, int c)
{
    p->topo = -1;                // indica que a pilha está vazia
    p->capacidade = c;           // define a capacidade da pilha
    p->elementos = new float[c]; // aloca memória para a capacidade fornecida
}

bool isEmpty(pilha *p)
{
    if (p->topo == -1)
        return true;
    else
        return false;
}

bool isFull(pilha *p)
{
    if (p->topo == p->capacidade-1)
        return true;
    else
        return false;
}

void push(pilha *p, float v)
{
    p->topo++;
    p->elementos[p->topo] = v;
}

float pop(pilha* p)
{
    float aux = p->elementos[p->topo];
    p->topo--;
    return aux;
}

float top(pilha* p)
{
    return p->elementos[p->topo];
}

int main()
{
    pilha p;
    int cap;
    
    // inicializacao da pilha
    cout << "Digite a capacidade da pilha: ";
    cin >> cap;
    cout << endl;
    
	init(&p, cap);
    
    
    // exibicao do menu e leitura da escolha do usuario
    char opcao;
    do {
        cout << "E - Empilhar (push)" << endl;
        cout << "D - Desempilhar (pop)" << endl;
        cout << "T - Exibir topo (top)" << endl;
        cout << "S - Sair" << endl;
        cin >> opcao;
        cout << endl;
		        
        switch (opcao)
        {
            // empilhar
            case 'E':
                if (isFull(&p) == true)
                {
                    cout << "Pilha estah cheia; nao eh possivel inserir" << endl;
                }
                else
                {
                    float v;
                    cout << "Entre com o valor a ser empilhado: ";
                    cin >> v;
                    push(&p, v);
                    cout << endl;
                    cout << "Inseri o elemento " << v << endl;
                    cout << endl;
                }
                break;
                
            // desempilhar
            case 'D':
                if (isEmpty(&p) == true)
                {
                    cout << "Pilha estah vazia; nao eh possivel remover" << endl;
                }
                else
                {
                    float tchau = pop(&p);
                    cout << "Removi o elemento " << tchau << endl;
                    cout << endl;
                }
                break;
                
            // topo
            case 'T':
                if (isEmpty(&p) == true)
                {
                    cout << "Pilha estah vazia; nao ha topo a ser exibido" << endl;
                }
                else
                {
                    cout << "O topo da pilha eh " << top(&p) << endl;
                    cout << endl;
                }
                break;
                
            // sair
            case 'S':
                cout << "tchau!" << endl;
                break;
                
            // invalido
            default:
                cout << "Opcao invalida; digite E, D, T ou S" << endl;
                break;
        }
    } while (opcao != 'S');
    
    return 0;
}
