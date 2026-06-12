#ifndef GEM_H
#define GEM_H
#include <string>
class Gem {
private:
    int type;
    std::string symbol;
    std::string color;
    void update();

public:
    Gem(int t = -1);
    void display() const;
    int gettype() const;
    bool isempty() const;
    void settype(int t);
    void randomize();
};
#endif