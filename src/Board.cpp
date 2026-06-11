#include "Board.h"
#include <bits/stdc++.h>
using namespace std;
class Board
{
    private:
        vector<vector<Gem>> item;
    public:
        void display() const
        {
            cout << "========================================" << "\n";
            cout << "\n";
            cout << "    0   1   2   3   4   5   6   7" << "\n";
            cout << "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗" << "\n";
            for(int j=0; j < 8;j++ )
            {
                cout << j << " " << "║";
                for(int i=0; i < 8;i++)
                {
                    cout << " ";
                    item[i][j].display();
                    cout << " " << "║";
                }
                cout << "\n";
                if(j!=7) cout <<"  ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣";
                else cout <<"  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝";
                cout << "\n";
            }
            cout << "========================================" << "\n";
        }
        void itemrandom()
        {
            for(int i=0;i < 8; i++)
            {
                for(int j=0; j < 8; j++)
                {
                    item[i][j].randomize();
                }
            }
        }
    
        

};

