#include <cstdio>
#include <algorithm>
using namespace std;

int h[6];

int sq(int n){
    return n*n;
}

int find( int n , int s = 0 ){
    int count = 0, m = -1, mm = 0;
    for(int i = s; i < 6; i++){
        if( m == h[i] ){
            count++;
        }else{
            if( count == n ){
                mm = m;
                break;
            }
            m = h[i];
            count = 1;
        }
    }
    return mm;
}

int main(){
    while( scanf("%d,%d,%d,%d,%d",
                 h, h+1, h+2, h+3, h+4) != EOF ){
        sort(h, h+5);
        if( find(4) ) puts("four card");
        else if( find(3)*find(2) && 
                 find(3) != find(2) ) puts("full house");
        else if( (h[1]-h[0])*(h[2]-h[1])*(h[3]-h[2])*(h[4]-h[3]) == 1 ||
                 (h[0] == 1 && h[1] == 10 && h[2] == 11 &&
                  h[3] == 12 && h[4] == 13) ){
            puts("straight");
        }else if( find(3) ){
            puts("three card");
        }else if( find(2)*find(2,2) && find(2) != find(2,2) ){
            puts("two pair");
        }else if( find(2) ){
            puts("one pair");
        }else{
            puts("null");
        }
    }
    return 0;
}