#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	while(cin >> N){
		vector<string> tel(N);
		for(int i=0; i<N; ++i)
			cin >> tel[i];

		sort(tel.begin(), tel.end());

		int caracteres = 0;
		for(int i=1; i<N; ++i){
			for(int j=0; j<tel[i].size(); ++j){
				if(tel[i][j]==tel[i-1][j])
					caracteres++;
				else
					break;
			}
		}

		cout << caracteres << endl;		
	}

	return 0;
}