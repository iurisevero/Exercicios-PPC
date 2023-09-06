// INCOMPLETE

#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_pair(x) cerr << #x << ": " << x.first << " " << x.second << endl;

using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using ll = unsigned long long int;

// #define MAX 2648956422
#define MAX 200000


ll binom(ll n, ll k){
	vector<ll> dp(k+1,0);
	dp[0]=1;

	for(ll i=1; i<=n; ++i)
		for(ll j=min(i,k); j>0; --j)
			dp[j] = dp[j] + dp[j-1];

	return dp[k];
}

ll seq[MAX];

void compute() {
    for(int i=0; i < MAX; ++i)
        seq[i] = binom(i, 2);
}

int main() {
    ll T;
    cin >> T;
    cerr << T << endl;
    // while(T--) {
    //     ll N, result;
    //     cin >> N;
        
    //     cout << result << endl;
    // }

    compute();
    for(int s : seq)
        cout << " " << s;
    cout << endl;

    return 0;
}
