#ifndef INTSTACK_H
#define INTSTACK_H
#include <queue>

using namespace std;

class IntStack
{

private:

    queue <int> data;

public:

    int top()
    {
        return data.back();
    }

    void pop()
    {
        int sz = data.size();
        for (int i = 0; i < sz - 1; ++i)
        {
            data.push(data.front());
            data.pop();
        }
        data.pop();
    }

    void push(int value)
    {
        data.push(value);
    }
};

#endif // INTSTACK_H
