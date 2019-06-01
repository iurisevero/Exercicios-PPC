#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int A, A_inicial, soma=0;
    int n_casos, N;

    cin >> N;
    for(n_casos=1; n_casos<=N ; n_casos++)
    {
        cin >> A;
        A_inicial = A;
        if(A==1)
            printf("Case #%d: %lld is a Happy number.\n", n_casos, A_inicial);
        else{
            while(1){

                while(1)
                {
                    soma+= (A%10)*(A%10);
                    //cout << "soma: " << soma << "\n";
                    if(A/10==0)
                        break;
                    A/=10;
                }
                A = soma;
                //cout << "A final: " << A << "\n";
                soma =0;
                if(A==4)
                {
                    printf("Case #%d: %lld is an Unhappy number.\n", n_casos, A_inicial);
                    break;
                }
                else if(A==1)
                {
                    printf("Case #%d: %lld is a Happy number.\n", n_casos, A_inicial);
                    break;
                }

            }
        }
    }
    return 0;
}
