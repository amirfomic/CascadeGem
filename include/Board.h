#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <utility>   
#include "Gem.h"
class Board
{
private:
    std::vector<std::vector<Gem>> item;
    std::vector<std::vector<bool>> visited;

public:
    Board();
    void display() const;
    void shuffle();
    void setvisited();
    std::vector<std::pair<int, int>> matches(int i, int j, int type);
    std::vector<std::pair<int, int>> allmatches();
    void popmatch(std::vector<std::pair<int, int>>& allmatche);
    void gravity();
    void fill();
    int chain();
    int swapandmatch(int x1, int y1, int x2, int y2);
    bool haslocked();
};

#endif 