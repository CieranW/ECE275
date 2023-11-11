#ifndef STATEPAIR_H
#define STATEPAIR_H

#include <iostream>

using namespace std;

template <typename T1, typename T2>
class StatePair
{
public:
    StatePair();
    StatePair(T1 newKey, T2 newValue);
    void SetKey(T1 newKey);
    void SetValue(T2 newValue);
    T1 GetKey() const;
    T2 GetValue() const;
    void PrintInfo() const;

private:
    T1 key;
    T2 value;
};

template <typename T1, typename T2>
StatePair<T1, T2>::StatePair()
{
    key = T1();
    value = T2();
}

template <typename T1, typename T2>
StatePair<T1, T2>::StatePair(T1 newKey, T2 newValue)
{
    key = newKey;
    value = newValue;
}

template <typename T1, typename T2>
void StatePair<T1, T2>::SetKey(T1 newKey)
{
    key = newKey;
}

template <typename T1, typename T2>
void StatePair<T1, T2>::SetValue(T2 newValue)
{
    value = newValue;
}

template <typename T1, typename T2>
T1 StatePair<T1, T2>::GetKey() const
{
    return key;
}

template <typename T1, typename T2>
T2 StatePair<T1, T2>::GetValue() const
{
    return value;
}

template <typename T1, typename T2>
void StatePair<T1, T2>::PrintInfo() const
{
    cout << key << ": " << value << endl;
}

#endif // STATEPAIR_H
