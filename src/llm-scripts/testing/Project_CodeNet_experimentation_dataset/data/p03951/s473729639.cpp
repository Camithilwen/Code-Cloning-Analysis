#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int N;
    string s,t;
    cin>>N>>s>>t;
    long long len1,len2,count=0;
    len1=s.length();
    len2=t.length();
if(len1==len2&&len1==N&&N>=1&&N<=100){
 if (N>=len1+len2){
        count=N;
 }
else {
    count=len1+len2;
        for(int i=0;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s.substr(i,len1)==t.substr(0,j)&&len1+len2-j>=N){
                    count=min(len1+len2-j,count);
                }
            }
        }
}
cout<<count;
}
    return 0;
}