#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    FastIO();

    unordered_multiset<string> list, empty;
    int n, answer = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        if (input == "ENTER")
        {
            list = empty;
        }
        else
        {
            if (list.find(input) == list.end())
            {
                answer++;
                list.insert(input);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}