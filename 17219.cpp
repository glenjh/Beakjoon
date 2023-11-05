#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    unordered_map<string , string> program; 
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        string site_name , password;
        cin >> site_name >> password;
        if(program.find(password) == program.end()){
            program.insert( {site_name , password} );
        }
    }

    for(int i = 0 ; i < m ; i++){
        string target_password;
        cin >> target_password;
        cout << program[target_password] << '\n';
    }

    return 0;
}