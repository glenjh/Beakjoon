#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    vector<double> v;
    stack<double> s;
    
    int n;
    cin >> n;

    string input;
    cin >> input;

    cout << fixed;
    cout.precision(2);

    for(int i = 0 ; i < n ; i++){
        double x;
        cin >> x;
        v.push_back(x);
    }


    double a, b, temp;

    for(auto it : input){
        if (isalpha(it)){
            s.push(v[it - 'A']);
        }
        else{
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            

            if(it == '+'){
                temp = b + a;
            }else if(it == '-'){
                temp = b - a;
            }else if(it == '*'){
                temp = b * a;
            }else if(it == '/'){
                temp = b / a;
            }

            s.push(temp);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';
  
    
    return 0;
}