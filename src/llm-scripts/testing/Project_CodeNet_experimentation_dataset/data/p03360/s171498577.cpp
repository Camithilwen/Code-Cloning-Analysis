#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
 vector<int>v;
 int a,b,c,k;
 cin >> a >> b >> c >> k;
 v.push_back(a);
 v.push_back(b);
 v.push_back(c);
 int sum = 0;
 while(k--)
 {
     sort(v.begin(),v.end());
     v[2]*=2;

 }

 sum = v[0] + v[1] + v[2];
 cout << sum << endl;


}
