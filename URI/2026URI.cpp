#include <bits/stdc++.h>

using namespace std;
#define MAX_P 100
#define MAX_Q 100


int peso_pacote[MAX_P];
int qnt_enfeites[MAX_Q];

int memo[MAX_P][MAX_Q];

int knapsack(int i, int w){

	if(i<0 || w<=0)
		return 0;

	if(memo[i][w]!=-1)
		return memo[i][w];

	if(peso_pacote[i] > w)
		return memo[i][w] = knapsack(i-1, w);

	return memo[i][w] = max(knapsack(i-1, w), knapsack(i-1, w - peso_pacote[i]) + qnt_enfeites[i]);

}

int main()
{
	memset(memo, -1, sizeof memo);

	int galhos;
	cin >> galhos;

	for(int k=1; k<= galhos; k++)
	{
		int numero_pacotes, peso_galho;
		cin >> numero_pacotes >> peso_galho;

		for(int j=0; j<numero_pacotes; ++j)
			cin >> qnt_enfeites[j] >> peso_pacote[j];	

		printf("Galho %d:\n", k);
		printf("Numero total de enfeites: %d\n\n", knapsack(numero_pacotes, peso_galho));

		memset(peso_pacote, 0, sizeof peso_pacote);
		memset(qnt_enfeites, 0, sizeof qnt_enfeites);
		memset(memo, -1, sizeof memo);
	}


	return 0;
}