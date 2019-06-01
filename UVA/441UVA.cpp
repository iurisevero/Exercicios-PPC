#include <bits/stdc++.h>

using namespace std;

int main()
{
    int K;
    cin >> K;
    while(K)
    {
        int aux=0;
        vector<int> S;
        for(int i=0; i<K; ++i)
{
            cin >> aux;
            S.push_back(aux);
        }

        for(int i=0; i<K-5; i++)
            for(int j=1; j<K-4; j++)
                for(int k=2; k<K-3; k++)
                    for(int l=3; l<K-2; l++)
                        for(int m=4; m<K-1; m++)
                            for(int n=5; n<K; n++)
                                if(i<j&&j<k&&k<l&&l<m&&m<n)
                                    printf("%d %d %d %d %d %d\n", S[i], S[j], S[k], S[l], S[m], S[n]);

        cin >> K;
        if(K==0)break;
        cout << "\n";

    }

    return 0;
}


