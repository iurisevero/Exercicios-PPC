#include <bits/stdc++.h>

using namespace std;

#define MAX_V 1000

char G[MAX_V][MAX_V];

int dx[] = { 1,-1, 0, 0};
int dy[] = { 0, 0,-1, 1};

int N, M; // Tamanho das colunas e linhas da matriz

void flood_fill(int x, int y, char color, char new_color) {

    if (x < 0 || y < 0 || x >= N || y >= M);
    else if (G[x][y] != color);
    else{
        G[x][y] = new_color;

        for(int i = 0; i < 4; ++i)
            flood_fill(x + dx[i], y + dy[i], color, new_color);
    }
}

int main()
{
    int qnt_vezes=0;

    cin >> N >> M;

    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            cin >> G[i][j];

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(G[i][j]!='o')
            {
                flood_fill(i, j, '.', 'o');
                qnt_vezes++;
            }
        }
    }

    cout << qnt_vezes << endl;

    return 0;
}
