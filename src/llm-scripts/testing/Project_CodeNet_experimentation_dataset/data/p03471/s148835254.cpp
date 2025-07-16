#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){
    int N,Y;
    int c1,c2,c3;
    c1 = -1;
    c2 = -1;
    c3 = -1;
    cin >> N >> Y;

    for(int a = 0;a <= N;a++){
        for(int b = 0;b <= N-a;b++){
            int c = N-a-b;
            int total = 10000*a+5000*b+1000*c;

            if(total == Y){
                c1 = a;
                c2 = b;
                c3 = c;
            }
            
        }
    }

    cout << c1 << " " << c2 << " " << c3 <<endl;


    return 0;
}