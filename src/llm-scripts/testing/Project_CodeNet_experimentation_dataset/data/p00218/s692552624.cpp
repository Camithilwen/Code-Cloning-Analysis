#include <iostream>
using namespace std;

int main(){
    int n;
    while( cin >> n, n ){
        int pm, pe, pj;
        while( n-- > 0 ){
            cin >> pm >> pe >> pj; 
            if( pm == 100 || pe == 100 || pj == 100 ||
                (pm+pe)/2 >= 90 || (pm+pe+pj)/3 >= 80 ){
                cout << 'A' << endl;
            }else if( (pm+pe+pj)/3 >= 70 || ((pm+pe+pj)/3 >= 50 && (pm >= 80 ||pe >=80))){
                cout << 'B' << endl;
            }else{
                cout << 'C' << endl;
            }
        }
    }
    return 0;
}