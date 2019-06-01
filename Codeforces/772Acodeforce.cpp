#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> a, b;
double p;

bool possivel(double t){
	double tempo_para_carga = 0.0;

	for(int i=0; i<N; ++i)
	{
		double c = b[i] - (a[i]*t);
		if(c<0.0)
			tempo_para_carga+= abs(c)/p;
	}

	return tempo_para_carga<=t;
}

int main()
{
	long long int soma_a = 0; 
	cin >> N >> p;

	for(int j=0; j<N; ++j)
	{
		int a_aux, b_aux;
		cin >> a_aux >> b_aux;
		soma_a+= a_aux;
		a.push_back(a_aux);
		b.push_back(b_aux);
	}

	if(p>=soma_a)
		cout << "-1\n";
	else{
		double left=0.0 , right = 1e14;

		for(int j=0; j<500; ++j)
		{
			double M = left + (right-left)/2;

			if(possivel(M))
				left = M;
			else
				right = M;
		}

		cout << left << endl;
	} 

	return 0;
}