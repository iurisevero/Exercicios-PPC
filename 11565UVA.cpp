#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        int A, B, C;
        int x, y, z;
        bool solution = true;

        cin >> A >> B >> C;

        for(x=-100; x<=100; ++x)
            for(y=-100; y<=100; ++y)
                for(z=-100; z<=100; ++z)
                {
                    if(x+y+z>A)
                        break;
                    else if(x+y+z==A&&x*y*z==B&&x*x+y*y+z*z==C&&x!=y&&x!=z&&z!=y){
                        printf("%d %d %d\n", x, y, z);
                        solution = false;
                        x=200;
                        y=200;
                        break;
                    }
                }

        if(solution)
            printf("No solution.\n");
    }

    return 0;
}
