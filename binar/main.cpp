#include <iostream>
#include <string>
using namespace std;

int main()
{   string cede;
    cout << "Hello World!" << endl;
    int n = 32;
    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");

        n >>= 1;
}
    return 0;
}

