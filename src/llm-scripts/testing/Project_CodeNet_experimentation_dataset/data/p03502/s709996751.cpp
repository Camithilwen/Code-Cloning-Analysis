#include<bits/stdc++.h>
using namespace std;
int main()
{ string s;
long long d,sum=0,num;
cin>>s;
long long n=s.size();
for(int i=0 ; i<n ; i++){
     d = s[i] - '0';
    num = num * 10 + d;
sum+=d;
}
if(num%(sum)==0) cout<< "Yes"<<  endl;
if(num%(sum)!=0) cout<< "No"<<  endl;

return 0;

}
