#include <bits/stdc++.h>

using namespace std;

int main()
{
    string word;
    int i, marcador;

    while(cin >> word)
    {
        string soundex;
        for(i=0; i<word.size(); i++)
        {
            if(word[i]=='B'||word[i]=='F'||word[i]=='P'||word[i]=='V')
            {
                if(marcador!=1)
                    soundex.push_back('1');
                marcador = 1;
            }
            else if(word[i]=='C'||word[i]=='G'||word[i]=='J'||word[i]=='K'||word[i]=='Q'||word[i]=='S'||word[i]=='X'||word[i]=='Z')
             {
                 if(marcador!=2)
                    soundex.push_back('2');
                marcador = 2;
             }
            else if(word[i]=='B'||word[i]=='D'||word[i]=='T')
            {
                if(marcador!=3)
                    soundex.push_back('3');
                marcador = 3;
            }
            else if(word[i]=='L')
            {
                if(marcador!=4)
                    soundex.push_back('4');
                marcador = 4;
            }
            else if(word[i]=='B'||word[i]=='M'||word[i]=='N')
            {
                if(marcador!=5)
                    soundex.push_back('5');
                marcador = 5;
            }
            else if(word[i]=='R')
            {
                if(marcador!=6)
                    soundex.push_back('6');
                marcador = 6;
            }
            else
                marcador = 0;
        }
        marcador = 0;
        cout << soundex << "\n";
    }
    return 0;
}
