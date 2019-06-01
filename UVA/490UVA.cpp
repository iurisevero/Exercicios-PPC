#include <bits/stdc++.h>

using namespace std;

int main()
{
    string frase, frases[110];
    vector<char> frase_vert[110];
    int maior=0, maior_linha=0, qnt_frases = 0;
    while(getline(cin, frase))
    {
        frases[qnt_frases] = frase;

        if(maior<frase.size()){
            maior = frase.size();
            maior_linha = qnt_frases;
        }

        qnt_frases++;
    }

    for(int i =qnt_frases; i>maior_linha; --i)
    {
        for(int j=frases[i].size(); j<maior; ++j)
            frases[i].push_back(' ');
    }

    for(int j=0; j<qnt_frases; ++j)
        for(int i=0; i<frases[j].size(); i++)
            frase_vert[i].push_back(frases[j][i]);

    for(int i=0; i<maior; i++){
        while(frase_vert[i].size()){
            cout << frase_vert[i].back();
            frase_vert[i].pop_back();
        }

        cout << "\n";
    }

    return 0;
}
