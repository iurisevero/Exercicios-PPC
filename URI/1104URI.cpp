#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B;

    while(cin >> A >> B, A+B)
    {
        int cartas_iguais=0;
        vector<int> Xa, Xb;
        for(int i=0, j=0; i<A; ++i, ++j)
        {
            int aux;
            cin >> aux;
            Xa.push_back(aux);
            if(Xa[j]==Xa[j-1]){
                Xa.pop_back();
                j--;
            }
        }
        for(int i=0, j=0; i<B; ++i, ++j)
        {
            int aux;
            cin >> aux;
            Xb.push_back(aux);
            if(Xb[j]==Xb[j-1]){
                Xb.pop_back();
                j--;
            }
        }

        if(Xa.size()<Xb.size())
            swap(Xa, Xb);
        if(B>A)
            swap(A, B);
        for(int i=0; i<Xa.size(); i++){
            for(int j=0; j<Xb.size(); ++j){
                if(Xb[j]==Xa[i])
                    cartas_iguais++;
            }
        }

        cout << Xb.size()-cartas_iguais << "\n";
    }


    return 0;
}
