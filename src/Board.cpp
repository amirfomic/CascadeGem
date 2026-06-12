#include "Board.h"
#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;
class Board
{
    private:
        vector<vector<Gem>> item;
        vector<vector<bool>> visited;
    public:
        Board()
        {
            item.resize(8,vector<Gem>(8));
            visited.resize(8,vector<bool>(8, false));
        }
        void display() const
        {
            cout << "========================================" << "\n";
            cout << "\n";
            cout << "    0   1   2   3   4   5   6   7" << "\n";
            cout << "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗" << "\n";
            for(int i=0; i < 8;i++ )
            {
                cout << i << " " << "║";
                for(int j=0; j < 8;j++)
                {
                    cout << " ";
                    item[i][j].display();
                    cout << " " << "║";
                }
                cout << "\n";
                if(i!=7) cout <<"  ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣";
                else cout <<"  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝";
                cout << "\n";
            }
            cout << "========================================" << "\n";
        }
        void shuffle()

        {
            for(int i=0;i < 8; i++)
            {
                for(int j=0; j < 8; j++)
                {
                    item[i][j].randomize();
                }
            }
        }
        void setvisited()
        {
            for(int i=0; i < 8 ; i++)
            {
                for(int j = 0; j < 8; j++) visited[i][j] = false;
            }
        }
        vector<pair<int,int>> matches(int i,int j,int type)
        {
            vector<pair<int,int>> matche;
            if(i < 0 || i > 7 || j < 0 || j > 7) return matche;
            if(visited[i][j]) return matche;
            if(item[i][j].isempty()) return matche;
            if(item[i][j].gettype() != type) return matche;
            visited[i][j] = true;
            matche.push_back({i,j});
            auto g1 = matches(i-1,j,type);
            auto g2 = matches(i+1,j,type);
            auto g3 = matches(i,j-1,type);
            auto g4 = matches(i,j+1,type);
            matche.insert(matche.end(),g1.begin(),g1.end());
            matche.insert(matche.end(),g2.begin(),g2.end());
            matche.insert(matche.end(),g3.begin(),g3.end());
            matche.insert(matche.end(),g4.begin(),g4.end());
            return matche;

        }
        vector<pair<int,int>> allmatches()
        {
            vector<pair<int,int>> allmatche;
            setvisited();
            bool typedone[8] = {false};
            for(int i=0 ; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    if(item[i][j].isempty()) continue;
                    int type = item[i][j].gettype();
                    if(typedone[type]) continue;
                    auto matche = matches(i,j,item[i][j].gettype());
                    int size = matche.size();
                    if(size > 2)
                    {
                      if(size >= 5) 
                      {
                        typedone[type] = true;
                        for(int i1=0; i1 < 8; i1++)
                        {
                            for(int j1=0; j1 < 8; j1++)
                            {
                                if(!item[i1][j1].isempty() && item[i1][j1].gettype() == type)
                                {
                                    visited[i1][j1] = true;
                                    allmatche.push_back({i1,j1});
                                }
                            }
                        }
                      }
                      else if(size == 4)
                      {
                        bool samei = true;
                        bool samej = true;
                        for(auto& p : matche)
                        {
                            if(p.first != matche[0].first) samei = false;
                            if(p.second != matche[0].second) samej = false;
                        }
                        if(samei || samej)
                        {
                            if(samei)
                            {
                                int row = matche[0].first;
                                for(int c=0 ; c <8; c++)
                                {
                                    if(!item[row][c].isempty() && !visited[row][c])
                                    {
                                        visited[row][c] = true;
                                        allmatche.push_back({row,c});
                                    }
                                }
                            }
                            else
                            {
                                int col = matche[0].second;
                                for(int r=0; r < 8 ; r++)
                                {
                                    if(!item[r][col].isempty() && !visited[r][col])
                                    {
                                        visited[r][col] = true;
                                        allmatche.push_back({r,col});
                                    }
                                }
                            }
                        }
                      }
                      else
                      {
                        allmatche.insert(allmatche.end(),matche.begin(),matche.end());
                      }
                    }
                }
            }
            return allmatche;

        }
        void popmatch(vector<pair<int,int>>& allmatche)
        {
            for(auto& v : allmatche)
            {
                item[v.first][v.second].settype(-1);
            }

        }
        void gravity()
        {
            for(int i=6 ; i >=0 ; i--)
            {
                for(int j = 0; j < 8; j++)
                {
                   if(!item[i][j].isempty())
                    {
                        int i1 = i;
                        while(i1 +1 <= 7 && item[i1+1][j].isempty()) i1 += 1;
                        int type = item[i][j].gettype();
                        item[i][j].settype(-1);
                        item[i1][j].settype(type);

                    }
                }
            }


        }
        void fill()
        {
            for(int i=0; i < 8; i++)
            {
                for(int j=0 ; j < 8; j++)
                {
                    if(item[i][j].isempty())
                    {
                        item[i][j].randomize();
                    }
                }
            }
        }
        int chain()
        {
            int score = 0;
            int x = 10;
            while(true)
            {
                auto allmatche = allmatches();
                if(allmatche.empty()) break;
                popmatch(allmatche);
                display();
                this_thread::sleep_for(chrono::milliseconds(500));
                gravity();
                fill();
                display();
                score += x*allmatche.size();
                x *= 2;
            }
            return score;
        }
        int swapandmatch(int x1,int y1,int x2, int y2)
        {
            if(x1 > 7 || x1 < 0 || x2 > 7 || x2 < 0 || y1 > 7 || y1 < 0 || y2 > 7 || y2 < 0) return -1;
            if((abs(y2-y1) + abs(x2-x1)) != 1) return -1;
            swap(item[x1][y1],item[x2][y2]);
            auto allmatche = allmatches();
            if (allmatche.empty())
            {
                swap(item[x1][y1],item[x2][y2]);
                return 0;
            }
            return chain();
        }
        bool haslocked()
        {
            for(int i=0 ; i < 8 ; i++)
            {
                for(int j=0; j < 8; j++)
                {
                    int iplus = i + 1;
                    int jplus = j + 1;
                    if(iplus >= 0 && iplus < 8)
                    {
                        swap(item[i][j],item[iplus][j]);
                        auto allmatche = allmatches();
                        if(!allmatche.empty()) return false;
                        swap(item[i][j],item[iplus][j]);
                    }
                    if(jplus >= 0 && jplus < 8)
                    {
                        swap(item[i][j],item[i][jplus]);
                        auto allmatche = allmatches();
                        if(!allmatche.empty()) return false;
                        swap(item[i][j],item[i][jplus]);
                    }
                }
            }
            return true;
        }


        

};

