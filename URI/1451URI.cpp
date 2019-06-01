#include <bits/stdc++.h>

using namespace std;

int main(){
	string frase;
	while(cin >> frase){
		//cout << "Frase: " << frase << endl;
		vector<string> frase_inicio;
		for(int i=0; i<frase.size(); ++i){
			if(frase[i]=='['){
				bool terminou = true;
				string palavra;
				do{
					i++;
					if(frase[i]=='['){
						i--;
						terminou = false;
						break;
					}
					palavra.push_back(frase[i]);
				}while(frase[i]!=']'&&i<frase.size());
				if(terminou) palavra.pop_back();
				frase_inicio.push_back(palavra);
				continue;
			}
			/*cout << "Frase inicio: ";
			for(auto p: frase_inicio)
				cout << p << " ";
			cout << endl;*/
		}
		string frase_fim;
		for(int i=0; i<frase.size(); ++i){
			if(frase[i]=='['){
				do{
					i++;
					if(frase[i]=='['){
						i--;
						break;
					}
				}while(frase[i]!=']'&&i<frase.size());
				continue;
			}
			if(frase[i]!=']')
				frase_fim.push_back(frase[i]);
		}

		reverse(frase_inicio.begin(), frase_inicio.end());
		for(auto p: frase_inicio)
			cout << p;
		cout << frase_fim << endl;
	}	
	return 0;
}