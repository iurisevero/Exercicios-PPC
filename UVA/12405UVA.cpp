#include <bits/stdc++.h>

using namespace std;
//tudo errado
int main()
{
    int T, caso = 1;
    cin >> T;
    while(T--)
    {
        int N;
        string field;
        vector<int> terreno_infertil;

        cin >> N >> field;


        int qnt_espantalhos =0;
        for(int i=1; i<N; i+=3)
        {
            while(field[i-1]=='#'&&i<N){
                if(field[i+1]=='#'&&field[i]=='.'||i==N-1&&field[i]=='.')
                {
                    if(field[i+2]=='.'&&i<N-1);
                    else
                        break;
                }
                i++;
            }

            if(i<N){
                qnt_espantalhos++;
                //field[i] = '#';
            }

            if(i==N-3&&field[N-1]=='.')
                i--;
        }

        cout << "Case " << caso << ": " << qnt_espantalhos << endl;
        caso++;
    }

    return 0;
}
