#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int a, b, sum, c = 1;
    cin >> a >> b;
    sum = a;
    if(b == 1){
        cout << 0;
    }
    else if(b <= a){
        cout << 1;
    }
    else{
        while(1){
            sum = sum + (a - 1);
            c++;
            if(sum >= b){
                break;
            }
        }
        cout << c;
    }


}





///promy_pompom
//hello world
