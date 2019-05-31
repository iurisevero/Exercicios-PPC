#include <bits/stdc++.h>

using namespace std;

#define MAX_W 30
#define MAX_V 30
#define MAX_ITENS 30

// pesos e valores
int W[MAX_ITENS];
int V[MAX_ITENS];

// matriz de memoização
int memo[MAX_W][MAX_V];

int knapsack(int i, int w) {

    // Caso o item não exista ou não mais caiba na mochila
    // nenhum valor será agregado
    if (i < 0 || w <= 0) return 0;

    // Caso este estado já tenha sido resolvido
    if (memo[i][w] != -1) return memo[i][w];

    // Caso o item estoure a capacidade da mochila
    // O item não será carregado
    if (W[i] > w) return memo[i][w] = knapsack(i - 1, w);

    // Caso contrário o valor ótimo será o maior valor entre a decisão
    // de não carregar o item e carregar o item
    return memo[i][w] = max(knapsack(i - 1, w),
                            knapsack(i - 1, w - W[i]) + V[i]);
}

int main() {
	int N;
	
	while(cin >> N, N)
	{
    	memset(memo, -1, sizeof memo);
    	
    	int P;	
    	cin >> P;
    	for(int i=0; i<N; ++i)
    		cin >> V[i] >> W[i];	
    	
    	cout << knapsack(N-1, P) << " min.\n";
    }	
}
