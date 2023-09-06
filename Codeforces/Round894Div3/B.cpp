#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_pair(x) cerr << #x << ": " << x.first << " " << x.second << endl;

using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;

int seq[200000];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        for(int i=0; i < N; ++i)
            cin >> seq[i];

        queue<int> result;
        result.push(seq[0]);
        for(int i=1; i < N; ++i){
            if(seq[i] < result.back()){
                result.push(seq[i]);
            }
            result.push(seq[i]);
        }

        cout << result.size() << endl;
        cout << result.front();
        result.pop();
        while(!result.empty()) {
            cout << " " << result.front();
            result.pop();
        }
        cout << endl;
    }


    return 0;
}