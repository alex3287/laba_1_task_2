#include <iostream>
#include "classa.h"
#include "classb.h"

using namespace std;

int main()
{

    //создание объекта Class A
    ClassA a1;
    // проверим количество связей
    cout<<"количество связий у объекта a1: "<<a1.getMultiplicity()<<endl;

    //создание объектов Class B
    ClassB b1, b2;
    cout<<"\nb1: "<<b1.hasA()<<" b2: "<<b2.hasA()<<endl; // проверим наличие связей с объектом класса A

    b1.addA(a1);    //установим связь

    // проверим наличие связей с объектом класса A
    cout<<"b1:"<<b1.hasA()<<" b2: "<<b2.hasA()<<endl;

    if (b1.hasA()){
        cout<<"\nсвязь обнаружена, удалим её"<<endl;
        b1.removeA();
    }
    cout<<"b1:"<<b1.hasA()<<" b2: "<<b2.hasA()<<endl<<endl;


    //установим связь
    a1.addB(b1);
    a1.addB(b2);
    cout<<"количество связей у объекта a1: "<<a1.getMultiplicity()<<endl; //проверим количество связей

    cout<<"указатель на связанный объект "<<a1.getB()<<endl; // вернуть указатель на свяанные объекты

    //разорвать все связи
    a1.removeB();
    cout<<"\nколичество связей объекта a1: "<<a1.getMultiplicity()<<endl; // проверим наличие связей с объектом класса B

    //проверка времени жизни объектов
    ClassA a4, a5, a6;

    return 0;
}
