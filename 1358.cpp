#include <iostream>
using namespace std;

int main(){
    int w,h,x,y,p;
    int cnt = 0;
    int x_pos, y_pos;
    cin >> w >> h >> x >> y >> p;
    for(int i=0 ; i<p ; i++){
        cin >> x_pos >> y_pos;
        if( (x_pos-x)*(x_pos-x) + (y_pos-(y+h/2))*(y_pos-(y+h/2)) <= h/2 * h/2 ){
            cnt++;
        }
        else if((x_pos-(x+w))*(x_pos-(x+w)) + (y_pos-(y+h/2))*(y_pos-(y+h/2)) <= h/2 * h/2){
            cnt++;
        }
        else if( (x <= x_pos && x_pos <= x+w) && (y <= y_pos && y_pos <= y+h)){
            cnt++;
        } 
    }
    cout << cnt;
    return 0;
}