#include <iostream>
#include <fstream>
#include <string>
#include "interface.h"
#include "phone_record.h"

int main()
{   static Record *kaczorek;
    interface();
    int command = 0;
    int inner_command = 0;
    std::string editer;
    std::cin >> command;
    long long int editing_number;


    while(command==1||command==2||command==3||command==4||command==5||command==6||command==7||command==8||command==9) { // ANOMALIA PRZY CHARZE SHACKUJ TOOO
        switch(command) {
        case 1:
            print_entire_data_base();
            break;
        case 2: {
            delete kaczorek;
            std::cout << std::endl;
            interface_print();
            std::string name;
            std::string surname;
            long long int number;
            std::cin>>name>>surname;
            std::cin>>number;
            kaczorek = new Record(name, surname, number);
            kaczorek -> print_this();
        }
            break;
        case 3:
            kaczorek -> print_this();
            break;
        case 4:
            kaczorek->save_record();
            delete kaczorek;

            break;
        case 5:
            delete kaczorek;
            kaczorek = new Record(0,0,0);

            break;
        case 6:
            interface_edit();
            std::cin >> inner_command;
            while(inner_command==1||inner_command==2||inner_command==3) {
                switch (inner_command) {
                case 1:
                    std::cout << "Type new name:" << std::endl;
                    std::cin >> editer;
                    kaczorek->edit_name(editer);
                    break;
                case 2:
                    std::cout << "Type new surname:" << std::endl;
                    std::cin >> editer;
                    kaczorek->edit_surname(editer);
                    break;
                case 3:
                    std::cout << "Type new number:" << std::endl;
                    std::cin >> editer;
                    kaczorek->edit_number(editing_number);
                    break;
                default:
                    break;
                }

            }



        case 7:
            delete kaczorek;
            break;
        case 8:
            clear_data_base();
            break;
        case 9:
            cleanscr();
            break;
        default:
            break;

        }
        std::cin>>command;
    }

    std::cout << std::endl;
    delete kaczorek;
    return 0;
}

