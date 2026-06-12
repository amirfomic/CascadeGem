#include "Player.h"
#include <bits/stdc++.h>
using namespace std;
class Player
{
    private:
        string name;
        int score;
        int bomb;
        int rocket;
        int hint;
    public:
        Player(string n)
        {
            name = n;
            score = 0;
            bomb = 0;
            rocket = 0;
            hint = 0;
        }
        void addscore(int points)
        {
            score += points;
        }

        bool popscore(int cost)
        {
            if (score >= cost) score -= cost;
            else return false;
            return true;
        }
        void addbomb()
        {
            bomb += 1;
        }
        void popbomb()
        {
            if (bomb > 0) bomb -= 1;
        }
        void addrocket()
        {
            rocket += 1;
        }
        void poprocket()
        {
            if(rocket > 0) rocket -= 1;
        }
        void addhint()
        {
            hint += 1;
        }
        void pophint()
        {
            if(hint > 0) hint -= 1;
        }
        int showscore() const
        {
            return score;
        }
        int showbomb() const
        {
            return bomb;
        }
        int showrocket() const
        {
            return rocket;
        }
        int showhint() const
        {
            return hint;
        }
        string showname() const
        {
            return name;
        }


};