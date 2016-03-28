#ifndef IMPLEM
#define IMPLEM
#include <string>

struct  ksiazka{
    std::string name;
    std::string surname;
    long long int number;
};

void interface(void);
void AddRecord(void);
void DeleteRecord(void);
void EraseData(void);
void ReadDataBase(void);

#endif // IMPLEM

