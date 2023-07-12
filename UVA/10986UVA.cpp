#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_pair(x) cerr << #x << ": " << x.first << " " << x.second << endl;

using namespace std;
using ii = pair<int, int>;

// Maximo de vertices
#define MAX_V 20001
// Numero grande para representar a pior distancia
#define INF_NUM 100000000


vector<ii> G[MAX_V];
int distances[MAX_V];

int sssp_dijkstra(int source, int destiny, int N) {
    fill(distances, distances + N + 1, INF_NUM);

    priority_queue< ii, vector<ii>, greater<ii> > to_visit;

    distances[source] = 0;
    to_visit.push(ii(distances[source], source));

    while(!to_visit.empty()) {
        // Distancia d :: Veritice v
        auto d = to_visit.top().first;
        auto v = to_visit.top().second;
        to_visit.pop();

        // Caso a distancia seja maior do que a distancia já registrada
        if (d > distances[v]) continue;

        for(auto i: G[v]) {
            auto i_v = i.first;
            auto i_d = i.second;

            if (distances[v] + i_d < distances[i_v]) {
                distances[i_v]  = distances[v] + i_d;
                to_visit.push(ii(distances[i_v], i_v));
            }
        }
    }

    return distances[destiny];
}

int main() {
    int N;
    cin >> N;

    for(int i = 1; i <= N; ++i){
        int n, m, S, T;
        cin >> n >> m >> S >> T;

        for(int j = 0; j < m; ++j){
            int s1, s2, w;
            cin >> s1 >> s2 >> w;
            G[s1].emplace_back(s2, w);
            G[s2].emplace_back(s1, w);
        }

        int dist = sssp_dijkstra(S, T, n);
        cout << "Case #" << i << ": " << 
            (dist == INF_NUM? "unreachable" : to_string(dist)) << endl; 
        
        for(int j=0; j<n; ++j) G[j].clear();
    }
    return 0;
}