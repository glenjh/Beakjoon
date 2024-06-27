#include <iostream>
#include <string>
#include <unordered_map>

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

    while (true)
    {
        int m;
        string word;

        cin >> m;
        if (m == 0)
            break;
        cin.ignore();
        getline(cin, word);

        unordered_map<char, int> char_count;
        int max_length = 0;
        int start = 0;

        for (int end = 0; end < word.length(); ++end)
        {
            char current_char = word[end];
            char_count[current_char]++;

            while (char_count.size() > m)
            {
                char start_char = word[start];
                char_count[start_char]--;
                if (char_count[start_char] == 0)
                {
                    char_count.erase(start_char);
                }
                start++;
            }

            max_length = max(max_length, end - start + 1);
        }

        cout << max_length << '\n';
    }

    return 0;
}