#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"lista.h"
#include"puzzle.h"
using namespace std;

int main()
{
    char solution[7] = "Konrad";
    char rozsypanka[7] = "Kdonra";
    Puzzle ukladanka(solution, rozsypanka);
    int dziala = 1;
    char choice;
    while(dziala)
    {
        cout<<"D - display"<<endl
        <<"L - shift left"<<endl
        <<"S - swap ends"<<endl
        <<"C - check"<<endl
        <<"Q - quit"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 'D':
            {
                ukladanka.display();
                break;
            }
        case 'L':
            {
                ukladanka.shiftLeft();
                break;
            }
        case 'S':
            {
                ukladanka.swapEnds();
                break;
            }
        case 'C':
            {
                if(ukladanka.isSolved()) 
                {
					cout<<"Correct!"<<endl;
					dziala = 0;
				}
                else cout<<"Incorrect!"<<endl;
                break;
            }
        case 'Q':
            {
                dziala = 0;
                break;
            }
        }
        cin.get();
        cout<<"Press enter to continue"<<endl;
        while((choice = getchar()) != '\n'){};
        system("clear");
    }
    return 0;
}
