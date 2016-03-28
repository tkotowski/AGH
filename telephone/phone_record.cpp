#include <iostream>
#include <fstream>
#include "phone_record.h"

int Record::eater(void) {
    name = "I have ate this";
    surname = "I have ate this too";
    number = 0;
    return 1;
}

Record::Record(const std::__cxx11::string &m_name, const std::__cxx11::string &m_surname, const long long m_number) {
    name=m_name;
    surname=m_surname;
    number=m_number;
}
Record::~Record(){
    std::cout<<"Destructor okay";
}

Record::Record() {
    name = "wrong_data";
    surname = "really_wrong_data";
    number = 000000000;
}


void Record::print_this(void) {
    std::cout<<name<<std::endl;
    std::cout<<surname<<std::endl;
    std::cout<<number<<std::endl;
}



void Record::remove_this(void) {
    //nie wiem co zrobic destruktor nie działa

}


void Record::save_record(void) {
    std::ofstream save("Phone_Book.txt", std::ios_base::out | std::ios_base::app);
    save<<name;
    save<<"\n";
    save<<surname;
    save<<"\n";
    save<<number;
    save<<"\n";
    save<<"\n";
    save.close();

}



void Record::zero_this(void) {
    eater();
}

void Record::edit_name(std::string &editor) {
    name = editor;
}

void Record::edit_surname(std::string &editor) {
    surname = editor;
}

void Record::edit_number(long long int &editor) {
    number = editor;
}
