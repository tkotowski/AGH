#include <iostream>
#include <fstream>
#include "implem.h"

void interface(void){
    std::cout<<"Press 1 to Add Record\nPress 2 to read existing data base\nPress 3 to delete entire data base\nPress 4 to exit program\n";
};


void AddRecord(void){
    std::ofstream write;
    write.open("Data_Base.txt");
    if(!write.is_open()){
        std::cout<<"EXIT DURING READING DATA BASE\n";
        exit(EXIT_FAILURE);
    }
    ksiazka NewRecord;
    std::cout<<"Please write name of added person\n";
    std::cin>>NewRecord.name;
    std::cout<<"Please write surname of added person\n";
    std::cin>>NewRecord.surname;
    std::cout<<"Please write number of person you would like to add\n";
    std::cin>>NewRecord.number;
    write<<"\n\n";
    write<<NewRecord.name;
    write<<"\n";
    write<<NewRecord.number;
    write<<"\n";
    write<<NewRecord.surname;
    write<<"\n";
    write.close();

};

void ReadDataBase(void){
    std::ifstream read;
    read.open("Data_Base.txt");
    if (!read.is_open()){
        std::cout<<"EXIT_FAILURE";
        exit(EXIT_FAILURE);        
        }
    std::string line;
    while(read.good()){


       std::getline(read, line);
       std::cout<<line<<"\n";

       if(read.eof())
       {
           std::cout<<"END OF DATA BASE\n";
       }

    }
    read.close();
}

void EraseData(){
    if( remove( "Data_Base.txt" ) != 0 )
        perror( "Error deleting file" );
      else
        puts( "File successfully deleted" );
};
