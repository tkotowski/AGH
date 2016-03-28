#include <iostream>
using namespace std;


int main(void)
    {


    int a[2][3]={1,2,3,4,5};
    int(*p)[3]=a;
    //cout<<**p;
    int *q;
    p++;
    q=*p;
    q--;


    cout<<  *q  ;


        return 0;
}

