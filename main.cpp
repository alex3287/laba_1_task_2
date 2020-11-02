#include <iostream>
#include <classa.h>
#include <classb.h>

using namespace std;

int main()
{

    //создание объекта Class A
    ClassA a1;
    cout<<a1.getMultiplicity()<<endl; // проверим количество связей

    //создание объекта Class B
    ClassB b1;

    return 0;
}
