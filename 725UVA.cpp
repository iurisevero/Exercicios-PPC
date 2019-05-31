#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, contador=0;
    while(cin >> N, N)
    {
        int A, B, A_aux, B_aux;
        bool solucao = true;

        contador++;
        if(contador>1)
			printf("\n");

        for(int B=1234; B<=98765; ++B)
        {
            bitset<10> valores;
            B_aux = B;
            A = B*N;
            A_aux = A;
            if(A>98765)
                break;

            if(A<10000||B<10000)
                valores.set(0);

            while(A_aux)
            {
                int A_m10 = A_aux%10;
                valores.set(A_m10);
                A_aux/=10;
            }
            while(B_aux)
            {
                int B_m10 = B_aux%10;
                valores.set(B_m10);
                B_aux/=10;
            }

            if(valores.all()){
                printf("%05d / %05d = %d\n", A, B, N);
                solucao = false;
            }
        }

        if(solucao)
            printf("There are no solutions for %d.\n", N);
    }

    return 0;
}


