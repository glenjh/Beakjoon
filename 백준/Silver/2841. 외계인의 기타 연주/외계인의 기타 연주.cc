#include <iostream>
#include <stack>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    stack<int> s[7];
    int n, p, answer = 0;
    cin >> n >> p;

    for(int i = 0 ; i < n ; i++){
        int lineNum, prat;
        cin >> lineNum >> prat;

        if(s[lineNum].empty()){
            s[lineNum].push(prat);
            answer++;
        }
        else{
            if(s[lineNum].top() > prat){
                while(true){
                    if(s[lineNum].top() >= prat){
                        if(s[lineNum].top() == prat){ break; }
                        s[lineNum].pop();
                        answer++;

                        if(s[lineNum].empty()){ 
                            s[lineNum].push(prat);
                            answer++;
                            break; 
                        }
                    }
                    else if(s[lineNum].top() < prat){
                        s[lineNum].push(prat);
                        answer++;
                    }
                }
                
                if(s[lineNum].top() != prat ){
                    s[lineNum].push(prat);
                    answer++;
                }
                
            }else if(s[lineNum].top() < prat){
                s[lineNum].push(prat);
                answer++;
            }
        }
    }
    cout << answer << '\n'; 


    return 0;
}