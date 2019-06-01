#include <bits/stdc++.h>

using namespace std;

typedef struct Aluno{
	string nome;
	string presenca;
	int P=0;
	int total_de_presenca=0;
} Aluno;

int main(){
	int T;

	cin >> T;

	while(T--){
		int N;
		Aluno alunos[100];
		cin >> N;

		for(int i=0; i<N; ++i){
			cin >> alunos[i].nome;
		}

		for(int i=0; i<N; ++i){
			cin >> alunos[i].presenca;
		}

		for(int i=0; i<N; ++i){
			for(int j=0; j<alunos[i].presenca.size(); ++j){
				if(alunos[i].presenca[j]=='P'){
					alunos[i].P++;
					alunos[i].total_de_presenca++;
				}
				else if(alunos[i].presenca[j]=='A')
					alunos[i].total_de_presenca++;
			}
		}
		bool first = false;
		for(int i=0; i<N; ++i){
			if(first){
				if(alunos[i].total_de_presenca*75/100 + (alunos[i].total_de_presenca*75%100? 1 : 0)> alunos[i].P)
					cout << " " << alunos[i].nome;
			}
			else{
				if(alunos[i].total_de_presenca*75/100 + (alunos[i].total_de_presenca*75%100? 1 : 0)> alunos[i].P){ 
					cout << alunos[i].nome;
					first = true;
				}
			}
		}
		cout << endl;
	}

	return 0;
}