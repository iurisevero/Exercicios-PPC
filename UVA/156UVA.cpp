#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;

int main(){
	
	char letra =' ';

	string texto;

	while(letra!= '#'){
		scanf("%c", &letra);
		texto.push_back(letra);
	}

	//debug(texto);
	texto.pop_back();

	map<string, int> anagramas;
	map<string, string> anagramas_palavra_original;

	int _size_texto = texto.size();
	string palavra_analisada;

	for(int i=0; i<_size_texto; ++i){
		//debug(texto[i]);
		if(texto[i]!=' '&&texto[i]!='\n'){
			palavra_analisada.push_back(texto[i]);
		}
		else{
			if(!palavra_analisada.empty()){
				//debug(palavra_analisada);
				string palavra_ordenada;
				for(auto l:palavra_analisada){
					palavra_ordenada.push_back(tolower(l));
				}
				sort(palavra_ordenada.begin(), palavra_ordenada.end());
				//debug(palavra_ordenada);

				anagramas[palavra_ordenada]++;
				anagramas_palavra_original[palavra_ordenada] = palavra_analisada;
				palavra_analisada.clear();
			}
		}
	}

	vector<string> anagramas_confirmados;

	for(auto anagrama : anagramas){
		//debug(anagramas_palavra_original[anagrama.first]);
		//debug(anagrama.second);
		if(anagrama.second == 1){
			anagramas_confirmados.push_back(anagramas_palavra_original[anagrama.first]);
		}
	}

	sort(anagramas_confirmados.begin(), anagramas_confirmados.end());
	for(auto anagrama : anagramas_confirmados)
		cout << anagrama << endl;

	return 0;
}