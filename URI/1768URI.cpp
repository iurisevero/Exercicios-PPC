#include <bits/stdc++.h>

using namespace std;

int main()
{
    int base, altura, espaco,i,j, arvore;

    while(cin >> base)
    {
        altura = base/2+1;
        espaco = base/2;
        arvore = 1;
        for(j=0; j<altura; j++)
        {
            for(i=0; i<espaco; i++)
                cout << " ";
            for(i=0; i<arvore; i++)
                cout << "*";

            cout << "\n";
            espaco--;
            arvore+=2;
        }
        espaco = base/2;
        arvore = 1;
        for(j=0; j<2; j++)
        {
            for(i=0; i<espaco; i++)
                cout << " ";
            for(i=0; i<arvore; i++)
                cout << "*";

            cout << "\n";
            espaco--;
            arvore+=2;
        }
        cout << "\n";
    }

    return 0;
}
