#include <stdio.h>

int main() {
    int N, i, M, V;

    scanf("%d", &N);
    for(i = 0; i < N; i ++) {
        int gols1 = 0, gols2 = 0, pontos1 = 0, pontos2 = 0, gols_adv1 = 0, gols_adv2 = 0;
        scanf("%d x %d", &M, &V);
        if(M > V)
            pontos1 += 3;
        else if (V > M)
            pontos2 += 3;
        else
        {
            pontos1 ++;
            pontos2 ++;
        }
        gols1 += (M - V);
        gols2 += (V - M);

        gols_adv2 += V;

        scanf("%d x %d", &V, &M);
        if(M > V)
            pontos1 += 3;
        else if (V > M)
            pontos2 += 3;
        else
        {
            pontos1 ++;
            pontos2 ++;
        }
        gols1 += (M - V);
        gols2 += (V - M);

        gols_adv1 += M;

        if(pontos1 > pontos2) {
            printf("Time 1\n");
        }
        else if(pontos2 > pontos1) {
            printf("Time 2\n");
        }
        else {
            if(gols1 > gols2) {
                printf("Time 1\n");
            }
            else if(gols2 > gols1) {
                printf("Time 2\n");
            }
            else {
                if(gols_adv1 > gols_adv2) {
                    printf("Time 1\n");
                }
                else if(gols_adv2 > gols_adv1) {
                    printf("Time 2\n");
                }
                else {
                    printf("Penaltis\n");
                }
            }
        }

    }
    return 0;
}
