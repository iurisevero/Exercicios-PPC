#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    while(N--)
    {
        int M, n_mudou=0;
        cin >> M;
        vector<int> notas,  notas_copia;
        while(M--)
        {
            int aux;
            cin >> aux;
            notas.push_back(aux);
        }

        notas_copia = notas;
        sort(notas.begin(), notas.end());
        reverse(notas.begin(), notas.end());
        for(int i=0; i<notas.size(); i++){
            cout << notas[i] << " " << notas_copia[i] << "\n";
            if(notas[i]==notas_copia[i])
                n_mudou++;
        }

        cout << n_mudou << "\n";

    }

    return 0;
}
