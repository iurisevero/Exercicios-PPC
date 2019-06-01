#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;

    while(cin >> N, N)
    {
        int picos=0;
        vector <int> magnetude;
        for(int i=0; i<N; ++i)
        {
            int aux;
            cin >> aux;
            magnetude.push_back(aux);
        }
        magnetude.push_back(magnetude[0]);
        magnetude.push_back(magnetude[1]);

        for(int i=1; i<magnetude.size()-1; i++)
        {
            if(magnetude[i]>magnetude[i-1]&&magnetude[i]>magnetude[i+1]||magnetude[i]<magnetude[i-1]&&magnetude[i]<magnetude[i+1])
                picos++;
        }

        cout << picos << "\n";

    }

    return 0;
}
