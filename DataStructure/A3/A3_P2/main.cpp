#include <iostream>
#include <list>

using namespace std;

template<class T> void mergeSortedLists(list<T>& l1, list<T>& l2)
{
    typename list<T>::iterator l1it = l1.begin();
    typename list<T>::iterator l2it = l2.begin();

    while (l1it != l1.end() && l2it != l2.end())
    {
        if (*l1it > *l2it)
        {
            l1.insert(l1it, *l2it);
            ++l2it;
        }
        else if (*l1it < *l2it)
        {
            ++l1it;
        }
        else
        {
            ++l1it;
            ++l2it;
        }
    }

    while (l2it != l2.end())
    {
        l1.push_back(*l2it);
        ++l2it;
    }
}

int main()
{
    list <int> l1;
    l1.push_back(1);
    l1.push_back(6);
    l1.push_back(9);

    list<int> l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(7);
    l2.push_back(20);
    l2.push_back(25);

    mergeSortedLists(l1, l2);

    for (list<int>::iterator it = l1.begin(); it != l1.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
