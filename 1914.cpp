#include <iostream>
#include <cmath>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Hanoi(int n, int start, int by, int to){
    if(n > 0){
        Hanoi(n - 1, start, to, by);
        cout << start << " " << to << '\n';
        Hanoi(n - 1, by, start, to);
    }
}

int main() {
    FastIO();

    int n; 
    string rel;
    cin >> n;

    rel = to_string(pow(2, n));
    int x = rel.find('.');

    rel = rel.substr(0, x);
    rel[rel.length() - 1] -= 1;

    cout << rel << '\n';

    if(n <= 20){
        Hanoi(n, 1, 2, 3);
    }

    return 0;
}