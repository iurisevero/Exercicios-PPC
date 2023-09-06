#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_pair(x) cerr << #x << ": " << x.first << " " << x.second << endl;

using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;

int main() {
    int T;
    cin >> T;
    string name = "vika";
    while(T--) {
        int N, M;
        char carpet[21][21];
        cin >> N >> M;
        for(int i=0; i < N; ++i) {
            for(int j=0; j < M; ++j) {
                cin >> carpet[i][j];
            }
        }
        
        int seq = 0;
        for(int j=0; j < M; ++j){
            for(int i=0; i < N; ++i){
                if(carpet[i][j] == name[seq]){
                    seq++;
                    break;
                }
            }
        }

        cout << (seq == 4? "YES" : "NO") << endl;
    }
    return 0;
}