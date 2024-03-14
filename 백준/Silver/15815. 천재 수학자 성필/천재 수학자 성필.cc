#include <iostream>
#include <stack>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    string formula;
    cin >> formula;

    stack<int> s;
    for (int i = 0; i < formula.length(); i++)
    {
        char c = formula[i];

        if (c >= '0' && c <= '9')
        {
            s.push(c - '0');
        }
        else
        {
            int a, b;
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();

            if (c == '+')
            {
                s.push(b + a);
            }
            else if (c == '-')
            {
                s.push(b - a);
            }
            else if (c == '*')
            {
                s.push(b * a);
            }
            else if (c == '/')
            {
                s.push(b / a);
            }
        }
    }

    cout << s.top();
}