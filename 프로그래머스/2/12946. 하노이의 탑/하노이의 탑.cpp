#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void Hanoi(int n, int start, int by, int to){
    if(n == 1){
        vector<int> v;
        v.push_back(start);
        v.push_back(to);
        answer.push_back(v);
    }
    else{
        Hanoi(n - 1, start, to, by);
        vector<int> v;
        v.push_back(start);
        v.push_back(to);
        answer.push_back(v);
        Hanoi(n - 1, by, start, to);
    }
}

vector<vector<int>> solution(int n) {
    Hanoi(n, 1, 2, 3);
    return answer;
}