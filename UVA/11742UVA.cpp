#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;

    while(cin >> N >> M, N+M)
    {
        int possible_seating=0;
        set<vector<int>> possible, impossible;

        if(M==0)
        {
            possible_seating++;
            for(int i=1; i<=N; i++)
                possible_seating*=i;
        }
        else
        {
            while(M--)
            {
                int a, b, c;
                cin >> a >> b >> c;
                vector<int> alunos;

                for(int i=0; i<N; ++i)
                    alunos.push_back(i);

                if(c>0)
                {
                    do{
                   		auto posicao_a = find(alunos.begin(), alunos.end(), a);
                    	auto posicao_b = find(alunos.begin(), alunos.end(), b);
                    	if(abs(distance(posicao_a, posicao_b))<=c)
                      		possible.insert(alunos);
                   		else
                        	impossible.insert(alunos);
                    }while(next_permutation(alunos.begin(),alunos.end()));
                }
                else
                {
                    do{
                    	auto posicao_a = find(alunos.begin(), alunos.end(), a);
                    	auto posicao_b = find(alunos.begin(), alunos.end(), b);
                    	if(abs(distance(posicao_a, posicao_b))>=-c)
                        	possible.insert(alunos);
                    	else
                        	impossible.insert(alunos);
                    }while(next_permutation(alunos.begin(),alunos.end()));
                }
            }
        }

        /* cout << endl;
        for(auto item: possible)
            cout << "Possivel: " << item[0] << item[1] << item[2] << endl;
        for(auto item: impossible)
            cout << "Impossivel: " << item[0] << item[1] << item[2] << endl;
        */
        for(auto item: possible)
        {
            //cout << item[0] << item[1] << item[2] << endl;
            if(impossible.count(item)!=0);
            else
                possible_seating++;
        }

        cout << possible_seating << endl;
    }

    return 0;
}
