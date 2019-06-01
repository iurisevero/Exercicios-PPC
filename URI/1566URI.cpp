#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		priority_queue<int,  vector<int>, greater<int> > alturas;

		for(int i=0; i<N; ++i)
		{
			int aux;
			cin >> aux;
			alturas.push(aux);
		}

		for(int i=0; i<N; ++i){
			int p = alturas.top();
			alturas.pop();
			cout << p << (i+1<N? " ": "\n");
		}
	}
	return 0;
}