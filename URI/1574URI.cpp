#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	map<string, int> mapa;
	mapa["LEFT"] = -1;
	mapa["RIGHT"] = 1;
	cin >> T;
	while(T--){
		int N, robo=0;
		cin >> N;
		char operacoes[110][15];

		for(int i=0; i<N; ++i){
			char lixo;
			do{
				scanf("%c", &lixo);
			}while(lixo!='\n');

			scanf("%[^\n]", &operacoes[i][0]);

			if(operacoes[i][0]=='S'){
				string valor;
				if(strlen(operacoes[i])%2)
					valor.push_back(operacoes[i][8]);
				else{
					valor.push_back(operacoes[i][8]);
					valor.push_back(operacoes[i][9]);
				}
				strcpy(operacoes[i], operacoes[stoi(valor)-1]);
			}
			
			robo += mapa[operacoes[i]];
		}
		cout << robo << endl;

	}

	return 0;
}