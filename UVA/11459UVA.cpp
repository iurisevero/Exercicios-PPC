#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;

int main(){
	int N;
	cin >> N;

	while(N--){
		int tabuleiro[110];
		for(int i=0; i<110; ++i){
			tabuleiro[i] = i;
		}
		int num_players, num_snakes, dices_roll;
		cin >> num_players >> num_snakes >> dices_roll;

		for(int i=0; i<num_snakes; ++i){
			int mouth, tail;
			cin >> mouth >> tail;
			tabuleiro[mouth] = tail;
			debug(mouth);
			debug(tabuleiro[mouth]);
		}

		int jogadores[1000010];
		fill(jogadores, jogadores + num_players + 5, 1);

		int jogador_atual = 0;
		bool win = false;
		for(int i=0; i<dices_roll; ++i){
			int dice;
			cin >> dice;
			debug(dice);
			if(!win){
				debug(jogador_atual%num_players + dice);
				debug(tabuleiro[jogadores[jogador_atual%num_players] + dice]);
				jogadores[jogador_atual%num_players] =
				tabuleiro[jogadores[jogador_atual%num_players] + dice];
				debug(jogadores[jogador_atual%num_players]);
				

				if(jogadores[jogador_atual%num_players] >= 100){
					jogadores[jogador_atual%num_players] = 100;
					win = true;
				}

				jogador_atual++;
			}
		}

		for(int i=0; i<num_players; ++i){
			cout << "Position of player " << i+1 << " is " << jogadores[i] << ".\n";
		}
	}

	return 0;
}