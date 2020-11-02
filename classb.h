#ifndef CLASSB_H
#define CLASSB_H

#pragma once
class ClassA;
class ClassB {
    ClassA* m_рА; //указатель на связанный объект
    bool m_update; //признак обновления связи
public: ClassB();
        ~ClassB(); //вернуть указатель на связанный объект
        const ClassA* getA() const;
        bool hasA() const;//проверить наличие связи
        void addA(ClassA&);//установить связь
        void removeA(); //разрушить связь
};

#endif // CLASSB_H
