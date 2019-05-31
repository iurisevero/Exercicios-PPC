#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, D, R;

    while(cin >> N >> D >> R, N+D+R)
    {
        vector<int> morning, evening;
        for(int i=0; i<N; ++i)
        {
            int aux;
            cin >> aux;
            morning.push_back(aux);
        }
        for(int i=0; i<N; ++i)
        {
            int aux;
            cin >> aux;
            evening.push_back(aux);
        }

        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end());

        int valor_a_pagar = 0;
        for(int i=0, j=N-1; i<N; i++, j--)
        {
            int valor = morning[i] + evening[j];
            if(valor>D)
                valor_a_pagar += (valor-D)*R;
        }
        cout << valor_a_pagar << endl;
    }
    return 0;
}
