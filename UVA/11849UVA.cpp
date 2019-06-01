#include <bits/stdc++.h>

using namespace std;

using lld = long long int;

int main(){
    
    int N, M;
    while(cin >> N >> M, M+N){
    	set<lld> cds;

    	for(int i=0; i<N; ++i)
    	{
    		lld aux;
    		cin >> aux;
    		cds.insert(aux);
    	}
    	int qnt_cds=0;
    	for(int i=0; i<M; ++i)
    	{
    		lld aux;
    		cin >> aux;

    		if(cds.count(aux)!=0)
    			qnt_cds++;
    	}

    	cout << qnt_cds << endl;
    }
    return 0;
}
