#ifndef STACK_H
#define STACK_H
#include "list.h"

template <class T> class stack : private list<T>
{

public:

    stack() : list<T>()
    {
    }

    stack(int val, int iSize) : list<T>(val, iSize)
    {
    }

    ~stack()
    {

        // No implementation required, the parent will do the whole clean up procedure.
    }

    T& top()
    {
        return *(list<T>::begin());
    }

    void pop()
    {
        list<T>::erase(list<T>::begin());
    }

    void push(T val)
    {
        list<T>::insert(val, list<T>::begin());
    }

    int size()
    {
        return list<T>::size();
    }
};

#endif // STACK_H
