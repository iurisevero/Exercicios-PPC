#include <bits/stdc++.h>

using namespace std;

int main(){

	int N;

	cin >> N;
	while(N--){
		int L;
		cin >> L;
		vector<int> vagoes(L);
		for(int i=0; i<L; ++i)
			cin >> vagoes[i];

		bool update = false;
		int swaps=0;
		do{
			update = false;

			for(int i=1; i<vagoes.size(); ++i){
				if(vagoes[i-1] > vagoes[i]){
					update = true;
					swap(vagoes[i-1], vagoes[i]);
					swaps++;
				}
			}	
		}while(update);

		cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
	}
	return 0;
}
