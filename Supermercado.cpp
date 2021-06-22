#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> estoque;
    list<int> venda;
    list<int>::iterator p;
    int n; // quantidade de operaçoes
    int x; // determina o tipo de operacao 1 para adicionar no estoque e 2 para retirar do estoque e colocar em venda
    int y; // Elemento a ser inserido na lista

    cout << "Digite a quantidade de operacoes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Digite o tipo de operacao: ";
        cin >> x;

        if (x == 1)
        {
            cout << "Digite o codigo do produto: ";
            cin >> y;
            estoque.push_back(y);
        }
        else
        {
            y = *estoque.begin();
            venda.push_front(y);
            estoque.pop_front();
        }
    }
    cout << "Estoque: ";
    for (p = estoque.begin(); p != estoque.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
    cout << "Venda: ";
    for (p = venda.begin(); p != venda.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}