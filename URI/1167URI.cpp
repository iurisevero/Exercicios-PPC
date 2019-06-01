#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << endl;
#define debug_pair(x) cerr << #x << ": " << x.first << " " << x.second << endl;

using namespace std;

int main(){
	int N;
	while(cin >> N, N){
		vector<pair<string, int>> roda;

		for(int i=0; i<N; ++i){
			string nome;
			int valor;
			cin >> nome >> valor;

			roda.emplace_back(nome, valor);
		}
		int bilhete_atual = roda[0].second;
		int posicao=0;
		while(roda.size()!=1){
			if(bilhete_atual%2==0){
				for(int i=0; i<bilhete_atual; ++i){
					posicao--;
					if(posicao<0)
						posicao = roda.size()-1;

					//debug_pair(roda[posicao]);
				}
				//debug(posicao);
				bilhete_atual = roda[posicao].second;
				//debug_pair(roda[posicao]);
				roda.erase(roda.begin()+posicao);
				/*debug(roda.size());
				debug(bilhete_atual);
				debug_pair(roda[posicao]);*/
				if(bilhete_atual%2)
					posicao--;
			}else{
				for(int i=0; i<bilhete_atual; ++i){
					posicao++;
					if(posicao>roda.size()-1)
						posicao = 0;

					//debug_pair(roda[posicao]);
				}
				//debug(posicao);
				//debug_pair(roda[posicao]);
				bilhete_atual = roda[posicao].second;
				roda.erase(roda.begin()+posicao);
				//debug_pair(roda[posicao]);
				if(bilhete_atual%2)
					posicao--;
				if(posicao<0)
						posicao = roda.size()-1;
				/*debug(roda.size());
				debug(bilhete_atual);*/
			}
		}

		cout << "Vencedor(a): " << roda[0].first << endl;

	}	
	return 0;
}