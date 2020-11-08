#include <iostream>
#include "classb.h"
#include "classa.h"

ClassB :: ClassB(): m_update (false), m_рА(0) {}
ClassB :: ~ClassB()
{
    m_рА = 0;
    std::cout<<"Destructor classB"<<std::endl;
}
//вернуть указатель на связанный объект
const ClassA* ClassB :: getA() const
{
    return m_рА;
}
//проверить наличие связи
bool ClassB :: hasA() const
{
    return m_рА != 0;
}
//установить связь
void ClassB :: addA (ClassA& r)
{
    if (m_update) return;
    if (m_рА == &r) return;
    //объект r должен быть свободен от этого объекта
    if (r.hasB(*this)) return;
    if (hasA()) removeA();
    //разрушение своей связи
    //модификация связи
    m_update = true;
    r.addB(*this);
    m_рА = &r;
    m_update = false;
}
//разрушить связь
void ClassB :: removeA()
{
    if (!hasA()) return;
    if (m_update) return;
    m_update = true;
    m_рА->removeB();
    //разрушение своей связи
    m_рА = 0;
    m_update = false;
}
