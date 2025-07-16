#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lld long long int
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
string s;
cin>>s;
int max=0;
if(s[0]=='R')
{
    max++;
}
if(s[1]=='R')
max++;
if(s[2]=='R')
max++;
if(max==2)
{
    if(s[1]!='R')
    cout<<1<<"\n";
    else
    cout<<max<<"\n";
}
else
cout<<max<<"\n";
	return 0;
}

