#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
void add_self(int& a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}


int main(){
	float d,t,s;
    cin>>d>>t>>s;
    if ((d/s)>t){
        cout<<"No";
    }

    else{
        cout<<"Yes";
    }
    }