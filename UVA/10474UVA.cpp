#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, Q, caso=1;
	while(cin >> N >> Q, N+Q)
	{
		vector<int> marble;

		while(N--)
		{
			int aux;
			cin >> aux;
			marble.push_back(aux);
		}

		sort(marble.begin(), marble.end());

		printf("CASE# %d:\n", caso);
		caso++;
		while(Q--)
		{
			int aux;
			cin >> aux;

			if(binary_search(marble.begin(), marble.end(), aux))
			{
				auto it = lower_bound(marble.begin(), marble.end(), aux);
				cout << aux << " found at " << 1+(it - marble.begin()) << endl;
			}
			else
				cout << aux << " not found\n";
		}

	}

	return 0;
}