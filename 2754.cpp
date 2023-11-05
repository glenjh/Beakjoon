#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    cin >> input;
    if(input == "A+"){
        cout << "4.3" << '\n';
    }
    else if(input == "A0"){
        cout << "4.0" << '\n';
    }
    else if(input == "A-"){
        cout << "3.7" << '\n';
    }
    else if(input == "B+"){
        cout << "3.3" << '\n';
    }
    else if(input == "B0"){
        cout << "3.0" << '\n';
    }
    else if(input == "B-"){
        cout << "2.7" << '\n';
    }
    else if(input == "C+"){
        cout << "2.3" << '\n';
    }
    else if(input == "C0"){
        cout << "2.0" << '\n';
    }
    else if(input == "C-"){
        cout << "1.7" << '\n';
    }
    else if(input == "D+"){
        cout << "1.3" << '\n';
    }
    else if(input == "D0"){
        cout << "1.0" << '\n';
    }
    else if(input == "D-"){
        cout << "0.7" << '\n';
    }
    else{
        cout << "0.0" << '\n';
    }
    return 0;
}