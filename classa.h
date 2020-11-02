#ifndef CLASSA_H
#define CLASSA_H

#pragma once
class ClassB;
class ClassA
{
private:
    bool m_update;
    ClassB* m_pB[4]; //массив указателей на связанные объекты
public:
    ClassA();
    ~ClassA();
    //вернуть количество связей
    const int getMultiplicity() const;
    //вернуть указатели на связанные объекты
    const ClassB** getB() const;
    bool hasB() const; // проверить наличие связей
    bool hasB(const ClassB&) const; //проверить связь
    void addB(ClassB&);//установить связь
    void removeВ(ClassB&);//разорвать связь
    void removeB(); //разорвать все связи
};

#endif // CLASSA_H
