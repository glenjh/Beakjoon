#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

bool sorting_key(string a , string b){
    if(a.length() == b.length()){ 
        return a < b;
    }else{
        return a.length() < b.length();
    }
}

int main(){
    int num_of_words;
    cin >> num_of_words;
    vector<string> v;
    for(int i=0 ; i<num_of_words ; i++){
        string words;
        cin >> words;
        v.push_back(words);
    }
    sort(v.begin() , v.end() , sorting_key);

    for(int i=0 ; i<v.size() ; i++){
        if(v[i] == v[i+1]){
            continue;
        }
        cout << v[i] << endl;
    }
    return 0;
}