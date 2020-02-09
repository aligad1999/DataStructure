#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool delimiterMatching(string input)
{
    stack <char> trace;

    bool ignore = false;

    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] != '*' && !ignore)   // ([{}])(){}[]{[]} ==5
        {
            if ((input[i] == '('  || input[i] == '[' || input[i] == '{'))
            {
                trace.push(input[i]);
            }

            else if (input[i] == '/' && (i + 1) < input.size() && input[i + 1] == '*')
            {
                trace.push(input[i]);
                trace.push(input[++i]);
                ++i;
                ignore = true;
            }

            else if ((input[i] == ')' || input[i] == ']' || input[i] == '}'))
            {
                if (!trace.empty() &&
                        ((trace.top() == '(' && input[i] == ')') ||
                         (trace.top() == '[' && input[i] == ']') ||
                         (trace.top() == '{' && input[i] == '}')))
                {
                    trace.pop();
                }
                else  // Our Stack Is Empty
                {
                    return false;
                }
            }
        }
        else if (input[i] == '*' && (i + 1) < input.size() && input[i + 1] == '/')
        {
            if (!trace.empty() &&
                    trace.top() == input[i])  /* Comment */
            {
                trace.pop();
                trace.pop();
                ++i;
                ignore = false;
            }
            else
            {
                return false;
            }
        }
    }

    if (!trace.empty())
    {
        return false;
    }

    return true;
}

int main()
{
    cout << delimiterMatching("([{}])(){}[]{[]}") << endl;
    cout << delimiterMatching("({))") << endl;
    cout << delimiterMatching("({/*)}]]]]]]}*/})") << endl;
    cout << delimiterMatching("({/*[][[]]]]]})") << endl;
    cout << delimiterMatching("[{/*******/}]") << endl;
    cout << delimiterMatching("/*") << endl;
    cout << delimiterMatching("*/") << endl;
    cout << delimiterMatching("(") << endl;
    cout << delimiterMatching(")") << endl;
    cout << delimiterMatching("()") << endl;
    cout << delimiterMatching("") << endl;
    return 0;
}
