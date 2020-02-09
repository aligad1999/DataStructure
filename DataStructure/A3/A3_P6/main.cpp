#include <iostream>
#include "queue.h"
using namespace std;

int main() {

    int i;

    queue<int> q1;

    i = 0;

    while (i ++< 10) {
        q1.push(i);
    }

    i = 10;
    while (i --> 0) {
        cout << "Front 1 -> "<< q1.front() << ' ';
        q1.pop();
    }
    cout << endl;

    queue<int> q2(9, 10);

    i = 10;
    while(i --> 0) {
        cout << "Front 2 -> " << q2.front() << ' ';
        q2.pop();
    }
    cout << endl;

    return 0;
}
