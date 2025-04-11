#ifndef WATERMELON_H
#define WATERMELON_H

#include <iostream>
#include <string>
using namespace std;
class Watermelon {
public:
    void printTypes();
    void set();
    void round();
    void Data(int p,int gm);
    void hide();
    void show();
    int snake(int p);
    int eat(int p);
    int weigh(int p);
    int board(int p);
    void printNutrition();
    void printCultivation();
    void funFact();
    void poemmenu();
    void where();
    int zhishi(string a,int p);
    int zhishi2(string a,int p);
    int migong(int p);
    int hit(int p);
    void shengming(string v1);
    int pwt(int gm);
};

#endif
