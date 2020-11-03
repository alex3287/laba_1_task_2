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
    ClassB b1, b2;
    cout<<"b1: "<<b1.hasA()<<" b2: "<<b2.hasA()<<endl; // проверим наличие связей с объектом класса A

    b1.addA(a1);    //установим связь

    // проверим наличие связей с объектом класса A
    cout<<"b1:"<<b1.hasA()<<" b2: "<<b2.hasA()<<endl;

    //установим связь
    a1.addB(b1);
    a1.addB(b2);
    cout<<a1.hasB()<<endl; // проверим наличие связей с объектом класса B
    cout<<a1.getMultiplicity()<<endl; //проверим количество связей

    cout<<a1.getB()<<endl; // вернуть указатель на свяанные объекты

    //разорвать все связи
    a1.removeB();
    cout<<a1.hasB()<<endl; // проверим наличие связей с объектом класса B

    return 0;
}
