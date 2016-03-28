#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"lista.h"
#include"puzzle.h"
using namespace std;

int main()
{
    double_clist<char> cdl;
    char choice;
    char element;
    int dziala = 1;
    while(dziala)
    {
        cin>>choice;
        switch(choice)
        {
            case '+':
            {
                cin>>element;
                cdl.insert_(element);
                break;
            }
            case '-':
            {
                cdl.remove_();
                break;
            }
            case '=':
            {
                cin>>element;
                cdl.replace_(element);
                break;
            }
            case '@':
            {
                cout<<cdl.getCursor()<<endl;
                break;
            }
            case 'N':
            {
                if(cdl.gotoNext()){};
                break;
            }
            case 'P':
            {
                if(cdl.gotoPrior()){};
                break;
            }
            case '<':
            {
                if(cdl.gotoBeginning()){};
                break;
            }
            case '>':
            {
                if(cdl.gotoEnd()){};
                break;
            }
            case 'E':
            {
                cout<<cdl.isEmpty()<<endl;
                break;
            }
            case 'C':
            {
                cdl.clear_();
                break;
            }
            case 'S':
            {
                cdl.show_();
                break;
            }
            case 'Q':
            {
                dziala = 0;
                break;
            }
        }
    }
    return 0;
}
