#include <stdio.h>

int main() {

    int A, C;
    scanf("%d", &C);
    while(C--){
        scanf("%d", &A);
        printf("%d\n", A%2);
    }

    return 0;
}
