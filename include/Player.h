#ifndef PLAYER_H
#define PLAYER_H
#include <string>
class Player {
private:
    std::string name;
    int score;
    int bomb;
    int rocket;
    int hint;
public:
    Player(std::string n);
    void addscore(int points);
    bool popscore(int cost);
    void addbomb();
    void popbomb();
    void addrocket();
    void poprocket();
    void addhint();
    void pophint();

    int showscore() const;
    int showbomb() const;
    int showrocket() const;
    int showhint() const;
    std::string showname() const;
};
#endif 