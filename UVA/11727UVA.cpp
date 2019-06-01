#include <bits/stdc++.h>

using namespace std;

int main(){

	int N;
	cin >> N;
	for(int i=1; i<=N; ++i)
	{
		int salario_1, salario_2, salario_3;
		cin >> salario_1 >> salario_2 >> salario_3;
		int soma_salarios = salario_3 + salario_2 + salario_1;
		printf("Case %d: %d\n", i, soma_salarios - max(salario_3, max(salario_1, salario_2)) - min(salario_3, min(salario_1, salario_2)));
	}

	return 0;
}
