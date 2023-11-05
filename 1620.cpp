# include <iostream>
# include <string>
# include <algorithm>
#include <vector>
#include <map>

using namespace std;
string name[1000000];
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    
    map<string,int> dogam;
    map<int,string> dogam2;
    
    string what;
    int n , m;
    cin >> n >> m;
    string pokemon;
    for(int i=0 ; i<n ; i++){
        cin >> pokemon;
        name[i] = pokemon;
        dogam.insert(pair<string,int>(pokemon,i+1));
        dogam2.insert(pair<int,string>(i+1,pokemon));
    }
    for(int i=0 ; i<m ; i++){
        cin >> what;
        if(isdigit(what[0]) == true){
            cout << dogam2[stoi(what)] << '\n';
        }else{
            cout << dogam[what] << '\n';
        }
    }
    return 0;
}