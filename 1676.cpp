#include <iostream>
#include <string>
#include <algorithm>

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

    int count = 0; 
    for (int i = 5; i <= n; i *= 5)
    {
        count += n / i; 
    }

    cout << count << '\n';

    return 0;
}
