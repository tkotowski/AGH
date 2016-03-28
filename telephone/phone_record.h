#ifndef PHONE_RECORD
#define PHONE_RECORD
#include <string>



class Record {

private:
std::string name;
std::string surname;
long long int number;
int eater(void);

public:
Record(); //konstruktor domyślny
Record(const std::string &m_name, const std::string &m_surname, const long long int m_number); //konstruktor
~Record(); //destruktor
void save_record(void);
void remove_this(void);
void print_this(void);
void zero_this(void);
void edit_name(std::string &);
void edit_surname(std::string &);
void edit_number(long long int &);
};



#endif // PHONE_RECORD

