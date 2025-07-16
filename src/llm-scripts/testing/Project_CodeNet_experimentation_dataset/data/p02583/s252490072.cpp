 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  fi0 for(ll i=0;i<n;i++)
string s;
string strd(int n){
    string x;
    while(n){
        int d=n%10;
        x+=(d+'0');
        n/=10;
    }
    reverse(x.begin(),x.end());
    return x;
}
void digit()
{
    cin>>s;
    ll sum=0;
    for(int i=0;i<s.size();i++){
        char a=(char)s[i];
        int d=(int) a-'0';
        sum+=d;
    }
    if(sum%9==0)cout<<"Yes\n";
    else cout<<"No\n";
}
int main()
{
   ll n;
   cin>>n;
   ll cnt=0;
   ll a[n];
  fi0{
    cin>>a[i];
   }

   sort(a,a+n);
   ///fi0 cout<<a[i]<<' ';
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
             if(a[i]!=a[j]&&a[j]!=a[k]){
                vector<ll>xxx;
                xxx.push_back(a[i]);
                xxx.push_back(a[j]);
                xxx.push_back(a[k]);
                sort(xxx.begin(),xxx.end());
                if(xxx[0]+xxx[1]>xxx[2])cnt++;
             }
        }
    }
   }
   cout<<cnt<<endl;
}
