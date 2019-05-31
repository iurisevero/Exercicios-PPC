#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Q;
    vector<int> l_chimp, h_luchu;

    cin >> N;
    for(int i=0, j=0; i<N; ++i, ++j)
    {
        int aux;
        cin >> aux;
        l_chimp.push_back(aux);
        if(l_chimp[j]==l_chimp[j-1]){
            l_chimp.pop_back();
            j--;
        }
    }
    cin >> Q;
    while(Q--)
    {
        int aux;
        cin >> aux;
        h_luchu.push_back(aux);
    }

    for(int i=0; i<h_luchu.size(); ++i)
    {
        int menor_h=0, maior_h=0;
        for(int j=0; j<l_chimp.size(); ++j)
        {
            if(l_chimp[j]==h_luchu[i])
            {
                if(j>0)
                    menor_h = l_chimp[j-1];
                if(j<l_chimp.size()-1)
                    maior_h = l_chimp[j+1];
                break;
            }
            else if(h_luchu[i] < l_chimp[j])
            {
                if(j>0)
                    menor_h = l_chimp[j-1];
                maior_h = l_chimp[j];
                break;
            }
            else
                menor_h = l_chimp[j];
        }
        if(maior_h==0&&menor_h==0)
            cout << "X X\n";
        else if(maior_h ==0)
            cout << menor_h << " X\n";
        else if(menor_h ==0)
            cout << "X " << maior_h << "\n";
        else
            cout << menor_h << " " << maior_h << "\n";

    }

    return 0;
}
