#include <bits/stdc++.h>

using namespace std;

int main(){

	int N;
	cin >> N;
	while(N--){
		long long int A, B;
		cin >> A >> B;

		if(A>B) cout << ">\n";
		else if(A<B) cout << "<\n";
		else cout << "=\n";
	}

	return 0;
}
