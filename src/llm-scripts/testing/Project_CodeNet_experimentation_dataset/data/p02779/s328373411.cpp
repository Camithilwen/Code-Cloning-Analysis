/*
h s, d't skp th si tll i's sved
 * ABC141 E
 * ABC145 D
 * ABC147 F
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n,x;
cin>>n;
set<int> st;
string ans="YES";
while(n--)
{
cin>>x;
if(st.count(x))
{
ans="NO";
break;
}
st.insert(x);
}
cout<<ans;
}