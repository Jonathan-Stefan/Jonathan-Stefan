#include <iostream>

using namespace std;


struct Arquivo
{
	int imp; // grau de importancia do arquivo
	int tam; // tamanho do arquivo
	bool pego; // Indica os arquivos que ja foram pegos
};

int main()
{
	int n; // quantidade de arquivos
	//int p; // Variavel auxiliar para separar os pacotes
	int b = 1; // Variavel usada para definir o numero do pacote
	int capacidade = 1460; // capacidade total da rede
	Arquivo v[100]; // vetor de Arquivos
	int pd[100][1461]; 	// valor maximo sendo:
	// olhando do item 'i'->final
	// olhando uma mochila de capacidade 'j'
	int caminho[100][1461]; // utilizado para recuperar quais arquivos foram escolhidos
	// 0 -> nao pegar o arquivo
	// 1 -> pegar o arquivo

	cout << "Entre com a quantidade de arquivos" << endl;
	cin >> n;
	//p = n;

	for(int i = 0; i < n; i++)
	{
		cout << "Entre com o grau de importancia e o tamanho do arquivo " << i << endl;
		cin  >> v[i].imp >> v[i].tam ;
		v[i].pego = false;
	}
	// CASO BASE:
	// olhando do ultimo arquivo para frente, val. maximo = 0
	for(int j = 0; j <= capacidade; j++)
		pd[n][j] = 0;
	// olhando tendo uma rede de capacidade 0, o val. maximo=0
	for(int i = 0; i <= n; i++)
		pd[i][0] = 0;
	// CASO GERAL
	for (int h = 0; h < n; h++)
	{
		while(v[h].pego == false)
		{
			for(int i = n - 1; i >= 0; i--)
				for(int j = 1; j <= capacidade; j++)
				{
					int pega, npega; // val. para caso eu pegar ou nao pegar o arquivo 'i'

					npega = pd[i + 1][j]; // olhar o proximo item, mantendo a capacidade 'j'

					if(v[i].pego == false && j >= v[i].tam) // se eu tiver capacidade disponivel p/ pegar o arquivo 'i'
						pega = pd[i + 1][j - v[i].tam] + v[i].imp;
					// olho o proximo item, subtraio o peso da capacidade
					// disponivel, e somo o valor do arquivo 'i'
					else
						pega = 0; // se nao posso pegar, o valor eh 0

					if(pega > npega) // se valer a pena pegar
					{
						pd[i][j] = pega;
						caminho[i][j] = 1;
					}

					else // se valer a pena nao pegar
					{
						pd[i][j] = npega;
						caminho[i][j] = 0;
					}
				}

			// RECUPERACAO
			// Começa na posicao final
			int i, j;
			i = 0; // do item 0->final
			j = capacidade; // para uma arquivo de capacidade max
			cout << "Pacote " << b++ << endl;
			while(i != n)  // enquanto eu nao chegar no ultimo item
			{
				if(caminho[i][j] == 0) // se nesse momento a melhor opcao foi nao pegar eu nao pego
					i++; // avanço para o proximo i, mantendo a capacidade

				else // if(caminho[i][j] == 1) /// se nesse momento a melhor opcao for pegar, eu pego
				{
					v[i].pego = true; // Indico que ele foi enviado e não o uso mais
					cout << i << " "; // indico que peguei o item
					j -= v[i].tam; // diminuo a capacidade disponivel
					i++; // avanco para o proximo i

				}
			}

			capacidade = 1460; //Volta a capacidade da rede para 1460
			cout << endl;
		}
	}
	return 0;
}


