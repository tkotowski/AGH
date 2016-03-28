#ifndef PUZZLE_H_
#define PUZZLE_H_

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"lista.h"
using namespace std;

template<typename T>
class double_clist;

template<typename T>
class node;

class Puzzle
{
public:
Puzzle( char answ[], char init[] ); // Konstruuje puzzle
void shiftLeft();
void swapEnds();
void display();
bool isSolved();
private:
double_clist<char> solution, puzzle;
};

Puzzle::Puzzle(char answ[], char init[])
{
    for(int i = 0; answ[i] != '\0'; i++)
    {
        solution.insert_(answ[i]);
        puzzle.insert_(init[i]);
    }
}

void Puzzle::shiftLeft()
{
    char temp;
    char first = puzzle.getCursor();
    for(int i = 0; i < puzzle.count() - 1; i++)
    {
        puzzle.gotoNext();
        temp = puzzle.getCursor();
        puzzle.gotoPrior();
        puzzle.replace_(temp);
        puzzle.gotoNext();
    }
    puzzle.replace_(first);
}

void Puzzle::swapEnds()
{
    char tempS;
    char tempE;
    puzzle.gotoBeginning();
    tempS = puzzle.getCursor();
    puzzle.gotoEnd();
    tempE = puzzle.getCursor();
    puzzle.replace_(tempS);
    puzzle.gotoBeginning();
    puzzle.replace_(tempE);
}

void Puzzle::display()
{
    puzzle.show_();
}

bool Puzzle::isSolved()
{
    puzzle.gotoBeginning();
    solution.gotoBeginning();
    for(int i = 0; i < puzzle.count() - 1; i++)
    {
        if(puzzle.getCursor() != solution.getCursor()) return false;
        puzzle.gotoNext();
        solution.gotoNext();
    }
    return true;
}

#endif
