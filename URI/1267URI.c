#include <stdio.h>

int main()
{
    int M[500][100], i, j, D, N;
    scanf("%d %d", &N, &D);
    while(1) {
        if(N == 0 && D == 0) {
            break;
        }

        for(i=0; i<D; i++)
            for(j=0; j<N; j++)
                scanf("%d", &M[i][j]);

        int soma=0, n_foi = 1;
        for(j=0; j<N; j++)
        {
            soma =0;
            for(i=0; i<D; i++)
            {
                soma+= M[i][j];
            }
            if(soma == D)
            {
                printf("yes\n");
                n_foi =0;
                break;
            }
        }

        if(n_foi)
            printf("no\n");

        scanf("%d %d", &N, &D);
    }
    return 0;
}
