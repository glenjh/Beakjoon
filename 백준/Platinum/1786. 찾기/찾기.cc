#include <iostream>
#include <string>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string pattern, text;
vector<int> answer;

vector<int> GetFail(string pattern){
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

    return f;
}

void KMP(string pattern, string text){
    vector<int> fail = GetFail(pattern);

    for(int j = 0, i = 0 ; i < text.length() ; i++){
        while(j > 0 && text[i] != pattern[j]){
            j = fail[j - 1];
        }
        if(text[i] == pattern[j]){
            if(j == pattern.length() - 1){
                answer.push_back(i - j + 1);
                j = fail[j];
            }else{
                j++;
            }
        }
    }
}

int main() {
    FastIO();
   
    getline(cin, text);
    getline(cin, pattern);

    GetFail(pattern);
    KMP(pattern, text);

    cout << answer.size() << '\n';
    for(int i = 0 ; i < answer.size() ; i++){
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}