#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v_numeros;
    int aux;

    while(cin >> aux)
        v_numeros.push_back(aux);

    for(int i=0; i<v_numeros.size(); ++i){
        int n_times = 1;
        for(int j=i+1; j<v_numeros.size(); ++j){
            if(v_numeros[i]==v_numeros[j]){
                n_times++;
                v_numeros.erase(v_numeros.begin()+j);
                --j;
            }

        }
        cout << v_numeros[i] << " " << n_times << "\n";
    }


    return 0;
}
