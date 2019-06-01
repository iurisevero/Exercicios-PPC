#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << endl;
#define debug_pair(x) cerr << #x << ": " << x.first << " " << x.second << endl;

using namespace std;

int main(){
	int N;
	cin >> N;
	stack<string> painel;
	painel.push("F A C E");
	int winners = 0;
	while(N--){
		char l1, l2, l3, l4;
		scanf(" %c %c %c %c", &l1, &l2, &l3, &l4);
		string jogador;
		jogador.push_back(l1);
		jogador.push_back(' ');
		jogador.push_back(l2);
		jogador.push_back(' ');
		jogador.push_back(l3);
		jogador.push_back(' ');
		jogador.push_back(l4);
		
		string topo_painel = painel.top();
		reverse(topo_painel.begin(), topo_painel.end());
	/*	debug(jogador);
		debug(topo_painel);
		debug(painel.top());*/

		if(jogador == topo_painel){
			painel.pop();
			winners++;
		}else
			painel.push(jogador);

		if(painel.empty())
			painel.push("F A C E");	
	}

	cout << winners << endl;;

	return 0;
}