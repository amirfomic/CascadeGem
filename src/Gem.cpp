#include <bits/stdc++.h>
using namespace std;
class Gem {
private:
    int type;
    string symbol;
    string color;
    void update()
    {
        switch(type)
        {
            case 0: symbol = "⚡"; color = "\033[93m"; break;
            case 1: symbol = "❄️"; color = "\033[96m"; break;
            case 2: symbol = "🔥" ; color = "\033[31m"; break;
            case 3: symbol = "🌙" ; color = "\033[37m"; break;
            case 4: symbol = "🌟" ; color = "\033[33m"; break;
            default: symbol = " " ; color = "\033[0m"; type = -1;

        }
    }

public:
    Gem(int t = -1) : type(t)
    {
        update();
    }
    void display() const
    {
      if(type == -1) cout << "◻️";
      else cout << color << symbol << "\033[0m";
    }
    int gettype() const
    {
        return type;
    }
    bool isempty() const
    {
        return (type == -1);
    }
    void settype(int t)
    {
        type = t;
        update();
    }
    void randomize()
    {
        type = rand()%5;
        update();
    }


    
    

};

