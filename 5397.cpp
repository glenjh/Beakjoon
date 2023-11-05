#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    string passcode;
    for(int i=0 ; i<testcase ; i++){
        cin >> passcode;
        list<char> l;   
        list<char>::iterator it = l.begin();
        for(int j=0 ; j<passcode.length() ; j++){
            if(passcode[j] == '<' ) { 
                if(it != l.begin()){
                    it--; 
                    }
                }
            else if (passcode[j] == '>' ) { 
                if(it != l.end())
                    it++; 
                }
            else if(passcode[j] == '-') { 
                if(it != l.begin()){
                    it--;
                    it = l.erase(it); 
                }
            }
            else { l.insert(it,passcode[j]); }
        }

        for(auto a : l){
            cout << a;
        }
        cout << endl;
    }
    return 0;
}