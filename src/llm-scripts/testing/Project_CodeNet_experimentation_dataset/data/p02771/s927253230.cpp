#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll power(ll p,ll n){
   ll result=1;
   while(n!=0){
   if(n%2==0){
    n/=2;
    p*=p;
   }
   else{
    n--;
    result=result*p;
   }
   }
    return result;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n,t,a,b,c,d;
   ll mod =1e9+7;
   string s1,s2;
   stack<ll>stck1;
   stack<ll>stck2;

   set<ll>st;
   cin>>a>>b>>c;
   st.insert(a);
   st.insert(b);
   st.insert(c);

   if(st.size()==2){
    cout<<"Yes"<<endl;
   }
   else{
    cout<<"No"<<endl;
   }
}
