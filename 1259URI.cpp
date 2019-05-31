#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, i;
    vector<int> pares, impares, v_pares, v_impares;
    cin >> N;

    while(N--){
        int aux;
        cin >> aux;
        if(aux%2==0)
            pares.push_back(aux);
        else
            impares.push_back(aux);
    }

    sort(pares.begin(), pares.end());
    sort(impares.begin(), impares.end());
    reverse(impares.begin(), impares.end());
    for(i=0; i<pares.size(); ++i){
        cout << pares[i] << "\n";}
    for(i=0; i<impares.size(); ++i){
        cout << impares[i] << "\n";}

    return 0;
}
