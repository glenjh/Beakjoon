#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int GetFail(string pattern){
    vector<int> f(pattern.length());

    int j = 0;
    for(int i = 1 ; i < pattern.length() ; i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = f[j - 1];
        }
        if(pattern[i] == pattern[j]){
            f[i] = ++j;
        }
    }

    sort(f.begin(), f.end());
    return f[f.size() - 1];
}


int main() {
    FastIO();

    int answer = 0;
    string text;
    cin >> text;
    for(int i = 0 ; i < text.length() ; i++){
        int temp = 0;
        string pattern = text.substr(i, text.length());
        temp = GetFail(pattern);
    
        answer = max(answer, temp);
    }

    cout << answer << '\n';

    return 0;
}