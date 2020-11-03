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
    cout<<b1.hasA()<<endl; // проверим наличие связей с объектом класса A

    b1.addA(a1);    //установим связь
    cout<<b1.hasA()<<endl; // проверим наличие связей с объектом класса A

    a1.addB(b1);
    cout<<a1.hasB()<<endl; // проверим наличие связей с объектом класса B

    //разорвать все связи
    a1.removeB();
    cout<<a1.hasB()<<endl; // проверим наличие связей с объектом класса B


    return 0;
}
