#include <iostream>
#include "list.h"
using namespace std;

template <class T> void listTraversal(list<T> l)
{
    typename list<T>::iterator it = l.begin();
    while (it != l.end())
    {
        cout << *it << ' ';
        ++it;
    }
    cout << endl;
}

template <class T> void reversedListTraversal(list<T> l)
{
    typename list<T>::iterator it = l.end();
    while (it != l.begin())
    {
        --it;
        cout << *it << ' ';
    }
    cout << endl;
}

int main()
{
    cout << "Constructors:\n";
    list<int> l1;
    list<int> l2(9, 10);

    cout << "l1:\n";
    listTraversal(l1);

    cout << "l2:\n";
    listTraversal(l2);

    cout << endl;

    // Size
    cout << "Size:\n" << l1.size() << '\n' << l2.size() << '\n' << endl;

    // Insert
    cout << "Insert into l1:\n";
    l1.insert(6, l1.end());
    l1.insert(5, l1.begin());
    l1.insert(4, l1.end() - 1);
    l1.insert(9, l1.end() - 2);
    listTraversal(l1);

    cout << endl;

    cout << "Printing l1 in reverse order\n";
    reversedListTraversal(l1);
    cout << endl;

    // Erase the first element.
    cout << "Erase l1...\n";
    list<int>::iterator it = l1.begin();
    while (it != l1.end())
    {
        it = l1.erase(it) - 1;
        ++it;
    }

    cout << "Printing l1\n";
    listTraversal(l1);

    cout << endl;

    // Testing assignment
    cout << "Assignment (l3 = l2):\n";
    list<int> l3;
    l3 = l2;

    cout << "Printing l3:\n";
    listTraversal(l3);

    cout << "Editing l2...\n";
    l2.erase(l2.erase(l2.begin()));

    cout << "Printing l2:\n";
    listTraversal(l2);

    cout << "Printing l3:\n";
    listTraversal(l3);

    // The code for the previous tests is a living test for the rest.
    return 0;
}
