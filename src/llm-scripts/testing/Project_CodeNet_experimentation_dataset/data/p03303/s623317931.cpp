#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 
int  main(){
string s;
cin >> s;
int n;
cin >> n;
for(int i=0;i<s.size();i+=n){
    cout<<s.at(i);
}
cout<<endl;
}
 
