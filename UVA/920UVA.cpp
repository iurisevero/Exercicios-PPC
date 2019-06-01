#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_pair(x) cerr << #x << ": " << x.first << " " << x.second << endl;
#define PI 3.14159265
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;

int main(){
	int C;
	cin >> C;

	while(C--){
		int N;
		cin >> N;
		priority_queue<ii> pontos_ordenados;

		for(int i=0; i<N; ++i){
			ii ponto;
			cin >> ponto.first >> ponto.second;
			pontos_ordenados.push(ponto);
		}
		double metros = 0;
		ii ponto_anterior = pontos_ordenados.top();
		pontos_ordenados.pop();
		int ponto_mais_alto = 0;
		while(!pontos_ordenados.empty()){
			auto p = pontos_ordenados.top();
			pontos_ordenados.pop();
			//debug_pair(p);
			//debug_pair(ponto_anterior);
			if(p.second > ponto_mais_alto){
				double teta = atan(abs(p.second - ponto_anterior.second)*1.0/abs(p.first-ponto_anterior.first));
				metros += abs(p.second - ponto_mais_alto)/sin(teta);
				ponto_mais_alto = p.second;
			}
			ponto_anterior = p;
		}
		printf("%.2lf\n", metros);
	}
}

