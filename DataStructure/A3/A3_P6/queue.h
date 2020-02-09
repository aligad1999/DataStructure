#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

template <class T> class queue : private list<T> {
public:
    queue() : list<T>() {
    }

    queue(int val, int iSize) : list<T>(val, iSize) {
    }

    ~queue() {

        // No implementation required, the parent will do the whole clean up procedure.
    }

    T& front() {
        return *(list<T>::begin());
    }

    void pop() {
        list<T>::erase(list<T>::begin());
    }

    void push(T val) {
        list<T>::insert(val, list<T>::end());
    }

    int size() {
        return list<T>::size();
    }
};

#endif // QUEUE_H
