#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while( n-- > 0 ){
        int out = 0, score = 0, base = 0;
        string event;
        while( out < 3 ){
            cin >> event;
            if( event == "OUT" ) out++;
            else if( event == "HIT" ){
                score += base/3;
                if( !(base/3) ) base++;
            }else if( event == "HOMERUN" ){
                score += base+1;
                base = 0;
            }
        }
        cout << score << endl;
    }
    return 0;
}