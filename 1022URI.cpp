#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
	int N;
	cin >> N;

	while(N--)
	{
		pair<int, int> valores[3];
		char conta;
		int gcd_atual;

		scanf("%d / %d %c %d / %d", &valores[0].first, &valores[0].second, &conta, &valores[1].first, &valores[1].second);

		if(conta == '+'){
			valores[2].first = (valores[0].first*valores[1].second + valores[1].first*valores[0].second);
			valores[2].second = (valores[0].second*valores[1].second);
		}
		else if(conta == '-'){
			valores[2].first = (valores[0].first*valores[1].second - valores[1].first*valores[0].second);
			valores[2].second = (valores[0].second*valores[1].second);
		}
		else if(conta == '*'){
			valores[2].first = valores[0].first*valores[1].first;
			valores[2].second = valores[0].second*valores[1].second;
		}
		else{
			valores[2].first = valores[0].first*valores[1].second;
			valores[2].second = valores[0].second*valores[1].first;
		}

		gcd_atual = abs(gcd(valores[2].first, valores[2].second));

		if(valores[2].second<0)
		{
			valores[2].first *= -1;
			valores[2].second *= -1;
			cout << "aqui\n";
		}

		printf("%d/%d = %d/%d\n", valores[2].first, valores[2].second, valores[2].first/gcd_atual, valores[2].second/gcd_atual);
	}

	return 0;
}
