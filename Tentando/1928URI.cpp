#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

vector<int> G[500000];
int dist[500000];
int visited[500000];
bool found[500000];
void bfs() {
	memset(visited, 0, sizeof visited);

	int initial_vertice = 1;

	queue<int> to_visit;
	to_visit.push(initial_vertice);
	dist[initial_vertice] = 0;
	visited[initial_vertice] = 1;

	while(!to_visit.empty()){
		auto v = to_visit.front();
		to_visit.pop();



		for(auto i : G[v]){
			if(!visited[i]){
				visited[i] = true;
				to_visit.push(i);
				dist[i] = dist[v] + 1;
			}
		}
	}
}

int main(){
	int N;
	cin >> N;
	vector< vector<int> > C(N);

	for(int i=1; i<=N; ++i){
		int aux;
		cin >> aux;
		C[aux].push_back(i);
	}

	for(int j=1; j<N; ++j){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bfs();

	int pontuacao_total = 0;

	for(int i=1; i<=N; ++i)
		debug(dist[i]);

	for(int i=1; i<=N/2; ++i){
		debug(C[i][0]);
		debug(C[i][1]);
	}

	for(int i=1; i<= N/2; ++i){
		debug(pontuacao_total);
		pontuacao_total += abs(dist[C[i][1]] - dist[C[i][0]]);
	}

	cout << pontuacao_total << endl;

	return 0;
}