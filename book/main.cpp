#include <iostream>
#include <fstream>
#include "implem.h"

int main(void){

    int a=0;
    std::ofstream outFile;


    while(a!=4){
        interface();
        std::cin>>a;
    switch(a){
    case 1:
        AddRecord();
        break;
    case 2:
        ReadDataBase();
        break;
    case 3:
        EraseData();
        break;

    }
}

    return 0;
}

