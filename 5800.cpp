#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(int a, int b){
    return a > b;
}

int main(){
    FastIO();

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        vector<int> v;
        int students, gap = 0;
        cin >> students;

        for(int j = 0 ; j < students ; j++){
            int grade;
            cin >> grade;
            v.push_back(grade);
        }

        sort(v.begin(), v.end(), cmp);

        for(int j = 0 ; j < v.size()-1 ; j++){
            if(v[j] - v[j+1] > gap){
                gap = v[j] - v[j+1];
            }
        }

        cout << "Class " << i+1 << '\n';
        cout << "Max " << v[0] << ", Min " << v[v.size()-1] << ", Largest gap " << gap << '\n';
    }

    return 0;
}