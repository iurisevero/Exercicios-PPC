#include <bits/stdc++.h>

using namespace std;

#define MAX_V 210

char G[MAX_V][MAX_V] = {'a'};

int dx[] = {-1, -1,  0,  0,  1,  1};
int dy[] = {-1,  0, -1,  1,  0,  1};

int N; // Tamanho das colunas e linhas da matriz

char flood_fill(int x, int y, char color) {
    int win;
    if (x < 0 || y < 0 || x >= N || y >= N) return '0';
    if (G[x][y] != color) return '0';

    G[x][y] = 'a';
    if(x==N-1&&color=='b')
        return 'B';
    if(y==N-1&&color=='w')
        return 'W';

    for(int i = 0; i < 6; ++i){
        win = flood_fill(x + dx[i], y + dy[i], color);
        if(win != '0')break;
    }

    if(win != '0')
        return win;
    else
        return '0';
}

int main()
{
    int contador = 1;
    while(cin >> N, N){

        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                cin >> G[i][j];

        char winner;
        for(int i=0; i<N; ++i){
            winner = flood_fill( 0, i, 'b');
            if(winner != '0')
                break;
        }

        if(winner == '0'){
            for(int i=0; i<N; ++i){
                winner = flood_fill( i, 0, 'w');
                if(winner != '0')
                    break;
            }
        }

        cout << contador << " " << winner << endl;
        contador ++;
    }

    return 0;
}
