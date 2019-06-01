#include <bits/stdc++.h>

using namespace std;

int main(){

	int N;

	while(cin >> N, N){
		int A, B, pont_A=0, pont_B = 0;

		for(int i=0; i<N; ++i){
			cin >> A >> B;
			if(A>B)
				pont_A++;
			else if(B>A)
				pont_B++;
		}

		cout << pont_A << " " << pont_B << endl;
	}
	return 0;
}
