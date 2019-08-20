#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

int main(){
	int A, B;

	cin >> A >> B;

	int Q = A/B, R = A%B;

	cout << Q << " " << R << endl;

	return 0;
}