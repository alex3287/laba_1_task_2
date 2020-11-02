#include "classa.h"

#include"classb.h"

ClassA::ClassA() : m_update(false)
{
    for (int j(0); j < 4; j++)
        m_pB[j] = 0;
}
ClassA :: ~ClassA()
{
    for (int j(0); j < 4; j++)
        m_pB[j] = 0;
}
//вернуть количество связей
const int ClassA:: getMultiplicity() const
{
    int n(0);
    while (m_pB[n] && n < 4)
        ++n;
    return n; }
//вернуть указатели на связанные объекты
const ClassB** ClassA:: getB() const
{
    return const_cast <const ClassB**> (m_pB);
}
//проверить наличие связей
bool ClassA:: hasB() const
{
    return m_pB[0] != 0;
}
//проверить связь с объектом
bool ClassA:: hasB(const ClassB& r) const
{
    int j(0);
    while (m_pB[j])
    {
        if (m_pB[j] == &r)
            return true;
        j++;
    }
    return false;
}
//установить связь с объектом
void ClassA::addB(ClassB& r)
{
    if (hasB(r))
        return;
    if (m_update)
        return;
    //должно быть место для добавления
    if (getMultiplicity() >= 4) return;
    //r должен быть свободен
    if (r.hasA())
        return;
    m_update = true;
    //запрос r об обновлении связи
    r.addA(*this);
    //обновление своих связей
    int n = getMultiplicity();
    m_pB[n] = &r;
    m_update = false;
}
//разорвать связь с объектом
void ClassA ::removeВ(ClassB& r)
{
    if (m_update) return;
    if (!hasB(r))
        return;
    m_update = true;
    //запрос r о разрыве связи
    r.removeA();
    //разрыв своей связи
    int n = getMultiplicity();
    int j;
    for (j = 0; j < n && m_pB[j] != &r; j++);
    for (int i(j); i < n-1; i++)
        m_pB[i] = m_pB[i+1];
    m_pB[n-1] = 0;
    m_update = false;
}
//разорвать все связи
void ClassA:: removeB()
{
    if (m_update) return;
    m_update = true;
    int j(0);
    while (j < getMultiplicity())
    {
        m_pB[j]->removeA(); j++;
    }
    for (int j(0); j < 4; j++)
        m_pB[j] = 0;
    m_update = false;
}

