#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int p[10001];
bool visited[10001];

int main() {
    FastIO();

    int t;
    cin >> t;
    for(int testCase = 0 ; testCase < t ; testCase++){
        int n, answer;
        cin >> n;

        for(int i = 1 ; i <= n ; i++){
            visited[i] = false;
            p[i] = i;
        }

        for(int i = 0 ; i < n - 1 ; i++){
            int a, b;
            cin >> a >> b;
            p[b] = a;
        }

        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        while(p[nodeA] != nodeA){
            visited[nodeA] = true;
            nodeA = p[nodeA];
        }

        while (true){
            if(visited[nodeB]){
                answer = nodeB;
                break;
            }
            visited[nodeB] = true;
            nodeB = p[nodeB];
        }
        
        cout << answer << '\n';
    }

    return 0;
}