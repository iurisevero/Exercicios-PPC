#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;

	while(N--){
		string mina;
		cin >> mina;
		int menor = 0, diamantes=0;
		for(int i=0; i<mina.size(); ++i){
			if(mina[i] == '<') menor++;
			else if(mina[i] == '>'&&menor){
				menor--;
				diamantes++;
			}
		}

		cout << diamantes << endl;
	}

	return 0;
}