#include <bits/stdc++.h>

using namespace std;

int main(){
	int T, participantes_certos = 0;
	cin >> T;
	for(int i=0; i<5; ++i){
		int participantes;
		cin >> participantes;

		if(participantes==T)
			participantes_certos++;
	}

	cout << participantes_certos << endl;

	return 0;
}