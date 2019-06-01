#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;

	while(cin >> N, N){
		int n_lados = 0;
		for(int i=0; i<N; ++i){
			int comp, qnt;
			cin >> comp >> qnt;
			n_lados+= qnt/2;
		}

		cout << n_lados/2 << endl;
	}

	return 0;
}