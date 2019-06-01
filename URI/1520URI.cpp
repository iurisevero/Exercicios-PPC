#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;

	while(cin>>N)
	{
		vector<int> prateleira;
		while(N--)
		{	
			int tamanho_X, tamanho_Y;
			cin >> tamanho_X >> tamanho_Y;
			for(int i=tamanho_X; i<=tamanho_Y; ++i)
				prateleira.push_back(i);
		}

		sort(prateleira.begin(), prateleira.end());

		int produto_desejado;

		cin >> produto_desejado;
		if(binary_search(prateleira.begin(),prateleira.end(), produto_desejado)){
			auto lower = lower_bound(prateleira.begin(), prateleira.end(), produto_desejado);
			auto upper = upper_bound(prateleira.begin(), prateleira.end(), produto_desejado);
			int posicao_x = distance(prateleira.begin(), lower);
			int posicao_y = distance(prateleira.begin(), upper)-1;

			cout << produto_desejado << " found from " << posicao_x << " to " << posicao_y << endl;
		}
		else
			cout << produto_desejado << " not found\n";
	}

	return 0;
}