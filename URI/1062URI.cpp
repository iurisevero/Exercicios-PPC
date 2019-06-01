#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << endl;
#define debug_pair(x) cerr << #x << ": " << x.first << " " << x.second << endl;

using namespace std;

int main(){
	int N;
	int first = 0;
	while(cin >> N, N){
		while(1){
			bool cabou = false;
			stack<int> est_A;
			for(int i=N; i>0; --i)
				est_A.push(i);

			//debug(est_A.size());

			stack<int> estacao;
			int aux = est_A.top(); 
			est_A.pop();
			estacao.push(aux);

			queue<int> est_B;
			for(int i=0; i<N; ++i){
				cin >> aux;

				if(aux==0){
					cabou = true;
					break;
				}

				est_B.push(aux);
			}
			//debug(est_B.size());

			if(cabou) break;

			bool possivel = true;
			while(!est_B.empty()){
				if(estacao.top()<est_B.front()){
					aux = est_A.top(); 
					est_A.pop();
					estacao.push(aux);
				}else if(estacao.top()==est_B.front()){
					estacao.pop();
					est_B.pop();
				}else{
					possivel = false;
					break;
				}

				if(estacao.empty()&&!est_A.empty()){
					aux = est_A.top(); 
					est_A.pop();
					estacao.push(aux);
				}

			}
/*
			debug(est_A.size());
			debug(estacao.size());
			debug(est_B.size());
*/
			if(possivel) cout << "Yes\n";
			else cout << "No\n"; 
		}
		cout << endl;
	}
	return 0;
}