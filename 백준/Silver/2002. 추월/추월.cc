#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    unordered_map<string, int> in;
    vector<int> v;
    string firstCar = "";
    int n, answer = 0;

    cin >> n;
    for(int i = 0 ; i < n  ; i++){
        string cars;
        cin >> cars;
        if (firstCar == "")
        {
            firstCar = cars;
        }
        in.insert({cars, i + 1});
    }

    for (int i = 0; i < n; i++)
    {
        string cars;
        cin >> cars;
        v.push_back(in[cars]);
    }
    
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(v[i] > v[j]){
                answer += 1;
                break;;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}