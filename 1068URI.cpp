#include <bits/stdc++.h>

using namespace std;

int main(){

	string expressao;

	while(cin >> expressao){
		int correto=0;
		for(int i=0; i< expressao.size(); ++i){
			if(expressao[i]=='(') correto++;
			if(expressao[i]==')') correto--;

			if(correto<0) break;
		}

		if(!correto) cout << "correct\n";
		else cout << "incorrect\n";
	}

	return 0;
}
