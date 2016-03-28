#include <iostream>
#include <cstdlib>
#include <fstream>

void interface(void) {

    std::cout << "Hello Dear User!" << std::endl;
    std::cout << "Welcome to Phone_Book 0.01" << std::endl;
    std::cout << std::endl;
    std::cout << "1) Print entire phonebook           press 1" << std::endl;
    std::cout << "2) Add record to phonebook          press 2" << std::endl;
    std::cout << "3) Print record that you created    press 3" << std::endl;
    std::cout << "4) Save record that you created     press 4" << std::endl;
    std::cout << "5) Clear record that you created    press 5" << std::endl;
    std::cout << "6) Edit record that you created     press 6" << std::endl;
    std::cout << "7) Delete record that you created   press 7" << std::endl;
    std::cout << "8) Clear entire phonebook           press 8" << std::endl;
    std::cout << "9) Clear screen and print menu      press 9" << std::endl;
    std::cout << "10) Exit from program               press 10" << std::endl;
    std::cout << std::endl;

}

void interface_print(void) {
    std::cout<< "You chose to add record to phonebook!" << std::endl;
    std::cout<< "At first please provide name of the person that you would like to add" << std::endl;
    std::cout<< "Then please provide surname and phone number of this person" << std::endl;
}

void interface_edit(void) {
    std::cout << "You chose to edit record that you just typed" << std::endl;
    std::cout << "To edit name of typed record press 1" << std::endl;
    std::cout << "To edit surname of typed record press 2" << std::endl;
    std::cout << "To edit number of typed record press 3" << std::endl;
}

void cleanscr(void) {
    std::cout << "\033[2J\033[1;1H";

}

void clear_data_base(void) {
    std::ofstream clear("Phone_Book.txt", std::ios_base::out);
    if (!clear.is_open()) {
        std::cout<<"SOMETHING WENT WRONG, FAILED DURING OPENING DATA BASE EXIT DURING CLEANING";
    }
    clear.close();
    interface();

}

void print_entire_data_base(void) {
    std::ifstream print("Phone_Book.txt", std::ios_base::in);
    if(!print.is_open()) {
        std::cout<<"SOMETHING WEN WRONG, REALLY WRONG FAILED DURING OPENING DATA BASE EXIT PRINTING";
    }
    std::cout<<"Your phonebook has got these records:"<<std::endl;
    char ch;
    while(print.get(ch)) {
        std::cout << ch;
    }
    std::cout<<std::endl;

}
