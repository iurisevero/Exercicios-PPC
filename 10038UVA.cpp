#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while(cin >> N){
        vector<int> sequence, Jolly;

            for(int i=0; i<N; ++i){
                int teste;
                cin >> teste;
                sequence.push_back(teste);
                Jolly.push_back(0);
            }
        if(N>1){
            for(int i=0; i<N-1; ++i){
                int valor = abs(sequence[i]-sequence[i+1]);
                if(valor>0&&valor<N)
                    Jolly[valor] = 1;
            }

            sort(Jolly.begin(), Jolly.end());
        }
        else
            Jolly.push_back(1);

        if(Jolly[1])
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return 0;
}
