#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int N;

    while(cin >> N, N)
    {
        long long int A, B;
        bitset<32> n(N), a, b;

        for(int i=0, j=1; i<32; ++i)
        {
            if(n[i]==1)
            {
                if(j%2==0){
                    b.set(i);
                    j++;
                }
                else{
                    a.set(i);
                    j++;
                }
            }
        }

        cout << a.to_ullong() << " " << b.to_ullong() << endl;
    }
    return 0;
}
