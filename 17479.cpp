#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, n; 
    long long original_price = 0, special_price = 0;
    
    cin >> a >> b >> c;
    map<string, long long> original;
    map<string, long long> special;
    set<string> service;

    for(int i = 0 ; i < a ; i++){
        string original_menu; 
        long long price;
        cin >> original_menu >> price;
        original.insert({original_menu, price});
    }

    for(int i = 0 ; i < b ; i++){
        string special_menu;
        long long price;
        cin >> special_menu >> price;
        special.insert({special_menu, price});
    }

    for(int i = 0 ; i < c ; i++){
        string service_menu;
        cin >> service_menu;
        service.insert(service_menu);
    }

    cin >> n;
    long long is_service_ordered = 0;
    bool flag = true;

    for(int i = 0 ; i < n ; i++){
        string food;
        cin >> food;

        if(original.find(food) != original.end()){
            original_price += original[food];
        }

        else if(special.find(food) != special.end()){
            special_price += special[food];
        }

        else if(service.find(food) != service.end()){
            is_service_ordered ++ ;
        }
    }

    if(original_price < 20000 && special_price != 0){ flag = false; }
    if(original_price + special_price < 50000 && is_service_ordered != 0 ){ flag = false; }
    if(is_service_ordered > 1){ flag = false; }

    if(flag){ cout << "Okay"; }
    else{ cout << "No"; }

    return 0;
}