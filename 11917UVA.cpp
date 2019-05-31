#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for(int i=0; i<N; ++i)
    {
        map<string, int> materia_tempo;
        int qnt_materia, tempo_total;
        cin >> qnt_materia;
        while(qnt_materia--)
        {
            pair <string, int> m_t;
            cin >> m_t.first >> m_t.second;
            materia_tempo[m_t.first] = m_t.second;
        }

        cin >> tempo_total;

        string dever_casa;
        cin >> dever_casa;

        printf("Case %d: ", i+1);
        if(materia_tempo.find(dever_casa)!= materia_tempo.end()){
            if(materia_tempo[dever_casa] <= tempo_total)
                cout << "Yesss" << endl;
            else if(materia_tempo[dever_casa]>tempo_total&&materia_tempo[dever_casa]<=tempo_total+5)
                cout << "Late" << endl;
            else if(materia_tempo[dever_casa] > tempo_total+5)
                cout << "Do your own homework!" << endl;
        }
        else
           cout << "Do your own homework!" << endl;

    }

    return 0;
}
