#ifndef GEM_H
#define GEM_H
#include <bits/stdc++.h>
using namespace std;
class Gem 
{
private:
    int type;              
    string symbol;    
    string color; 
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