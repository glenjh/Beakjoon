#include <iostream>

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

    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "SK" << '\n';
    }
    else
    {
        cout << "CY" << '\n';
    }
    return 0;
}