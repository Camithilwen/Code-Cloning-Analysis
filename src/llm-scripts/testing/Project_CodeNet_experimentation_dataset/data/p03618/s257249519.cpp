#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define INF 1e15
int main()
{
string s;cin>>s;
ll hash[1000]={0};
for(int  i=0;i<s.length();i++)
hash[s[i]-'0']++;

ll count=0;
ll n=s.length();
for(int i=0;i<1000;i++)
count+=(hash[i]*(hash[i]-1))/2;

ll res=(((n*(n-1))/2))-count+1;
cout<<res<<endl;;
}