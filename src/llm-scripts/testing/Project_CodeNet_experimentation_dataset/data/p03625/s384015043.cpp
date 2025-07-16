#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI acos(-1)
typedef  long long ll;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}

int main(){
   int n;
   cin>>n;

   vector<int> a(n);
   rep(i,n){
      cin>>a[i];
   }
   sort(a.begin(),a.end());
   vector<int> b;
   b.push_back(0);
   b.push_back(0);
   rep(i,n-1){
      if(a[i+1]==a[i]){
         if(a[i+2]==a[i]){
            if(a[i+3]==a[i]){
               b.push_back(a[i]);
               b.push_back(a[i]);
               i+=3;
            }
            else{
               b.push_back(a[i]);
               i+=2;
            }
         }
         else{
         b.push_back(a[i]);
         }
      }
   }
   int p=0,q=0;

   

   sort(b.begin(),b.end(),greater<int>());
   cout<<(ll)b[0]*(ll)b[1];
   


   return 0;
}
