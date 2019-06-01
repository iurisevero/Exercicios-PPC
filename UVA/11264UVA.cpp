#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        long long int type_coins[N];
        for(int i =0; i<N; ++i)
            cin >> type_coins[i];
        long long int maior = type_coins[0];
        int coins = 1;
        for(int i=1; i<N-1; ++i){
            if(maior+type_coins[i]<type_coins[i+1]){
                maior += type_coins[i];
                coins++;
            }
        }
        coins++;
        cout << coins << endl;
    }

    return 0;
}
