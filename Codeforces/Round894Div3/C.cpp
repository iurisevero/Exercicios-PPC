#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_pair(x) cerr << #x << ": " << x.first << " " << x.second << endl;

using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;

int fence[200001];
int hor_fence[200001];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        for(int i=0; i < N; ++i)
            cin >> fence[i];
        
        if(fence[0] != N){
            cout << "NO\n";
            continue;
        }

        for(int i=0; i < N; ++i) hor_fence[i] = N;

        // cerr << "Hor Fence build:\n";
        for(int i=1; i < N; ++i) {
            for(int j=fence[i-1]-1; j > fence[i]-1; --j){
                hor_fence[j] = i;
            }
            // for(int i=0; i < N; ++i) cerr << " " << hor_fence[i];
            // cerr << endl;
        }
        hor_fence[0] = N;

        // cerr << "Fence:";
        // for(int i=0; i < N; ++i) cerr << " " << fence[i];
        // cerr << endl;

        // cerr << "Hor Fence:";
        // for(int i=0; i < N; ++i) cerr << " " << hor_fence[i];
        // cerr << endl;

        bool equal = true;
        for(int i=0; i < N; ++i){
            if(fence[i] != hor_fence[i]){
                equal = false;
                break;
            }
        }
        cout << (equal? "YES\n" : "NO\n");
    }


    return 0;
}