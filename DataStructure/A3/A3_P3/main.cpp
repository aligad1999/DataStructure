#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    int i;
    stack <int> s1;

    i = 0;
    while (i++ < 10)
    {
        s1.push(i);
    }

    i = 10;
    while (i --> 0)
    {
        cout << s1.top() << ' ';
        s1.pop();
    }
    cout << "\nSize = " << s1.size();

    cout << endl;

    return 0;
}



//    stack <int> s2(9, 10);
//
//    i = 10;
//
//    while(i --> 0)
//    {
//        cout << s2.top() << ' ';
//        s2.pop();
//    }
//    cout << endl;

