
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
int b,c,d,e,f,g,h,i,j,k,l,m,t;

long long a;
cin>>a;
string s;
while(a--)
{
s+=('a'+a%26);
a=a/26;

}
reverse(s.begin(),s.end());
cout<<s;
}