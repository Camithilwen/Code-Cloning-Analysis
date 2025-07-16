#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int d12, d13, d23, T;

void comparar () {
    int t1=d12+d23;
    int t2=d13+d23;
    int t3=d12+d13;
    if (t1>=t2) {
        T=min(t3,t2);
    } else {
        T=min(t1,t3);    
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>d12>>d13>>d23;
    comparar();
    cout<<T;
        
   return 0;
}
