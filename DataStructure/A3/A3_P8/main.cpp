#include <iostream>
#include "IntStack.h"
using namespace std;

int main() {

    IntStack s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    // 6 5 4 3
    cout <<"Top : " << s.top() << '\n';
    s.pop();

    // 5 4 3
    cout << "Top : " << s.top() << '\n';
    s.pop();

    // 4 3
    cout << "Top : " << s.top() << '\n';
    s.pop();

    // 3
    cout << "Top : " << s.top() << endl;
    s.pop();

    return 0;
}
