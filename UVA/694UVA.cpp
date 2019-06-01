#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int A, A_inicial, L;
    int n_casos=0;

    while(scanf("%lld %lld", &A, &L), A!=-1)
    {
        n_casos++;
        int n_termos = 0;
        A_inicial = A;
        while(1)
        {
            n_termos++;
            if(A==1)
                break;
            else if(A%2==0)
                A/=2;
            else
                A = 3*A + 1;
            if(A>L)
                break;
        }
        //n_termos = teste(A, L, n_termos);
        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", n_casos, A_inicial, L, n_termos);
    }

    return 0;
}
/*
int teste(int A, int L, int n_termos)
{
    if(A>L)
        return n_termos;

    n_termos++;

    if(A==1)
        return n_termos;
    else if(A%2==0)
        return teste(A/2, L, n_termos);
    else
        return teste(3*A+1, L, n_termos);
}
*/
